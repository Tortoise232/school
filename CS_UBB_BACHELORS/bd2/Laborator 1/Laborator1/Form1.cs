﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace Laborator1
{
    public partial class Form1 : Form
    {
        SqlConnection databaseConnection;
        SqlDataAdapter dataAdapterEmployees, dataAdapterAddresses, dataAdapterDepartments, dataAdapterAcquisitions;
        DataSet dataSet;
        BindingSource bindingSourceEmployees, bindingSourceAddresses, bindingSourceDepartments, bindingSourceAcquisitions;
        SqlCommandBuilder commandBuilderEmployees;
        SqlCommandBuilder commandBuilderAddresses;
        SqlCommandBuilder commandBuilderDepartments;
        SqlCommandBuilder commandBuilderAcquisitions;
        string database = ConfigurationManager.AppSettings["database"];
        string parent = ConfigurationManager.AppSettings["parent"];
        string child = ConfigurationManager.AppSettings["child"];
        string parentColumn = ConfigurationManager.AppSettings["parentColumn"];
        string childColumn = ConfigurationManager.AppSettings["childColumn"];
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void addressLabel_Click(object sender, EventArgs e)
        {

        }

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            databaseConnection = new SqlConnection(@"Server=DESKTOP-V3PAQVA\GNCSB;" + "Database=" + database + ";Integrated Security=SSPI;");
            Console.Write(databaseConnection);
            dataSet = new DataSet();

            dataAdapterEmployees = new SqlDataAdapter("SELECT * FROM " + parent, databaseConnection);
            dataAdapterAddresses = new SqlDataAdapter("SELECT * FROM " + child, databaseConnection);
            dataAdapterDepartments = new SqlDataAdapter("SELECT * FROM DEPARTMENTS", databaseConnection);
            dataAdapterAcquisitions = new SqlDataAdapter("SELECT * FROM ACQUISITIONS", databaseConnection);


            dataAdapterEmployees.Fill(dataSet, parent);
            dataAdapterAddresses.Fill(dataSet, child);

            //change setting and turn these off
            dataAdapterDepartments.Fill(dataSet, "DEPARTMENTS");
            dataAdapterAcquisitions.Fill(dataSet, "ACQUISITIONS");

            commandBuilderEmployees = new SqlCommandBuilder(dataAdapterEmployees);
            commandBuilderAddresses = new SqlCommandBuilder(dataAdapterAddresses);
            commandBuilderDepartments = new SqlCommandBuilder(dataAdapterDepartments);
            commandBuilderAcquisitions = new SqlCommandBuilder(dataAdapterAcquisitions);

            bindingSourceDepartments = new BindingSource();
            bindingSourceEmployees = new BindingSource();
            bindingSourceAddresses = new BindingSource();
            bindingSourceAcquisitions = new BindingSource();

            dataSet.Relations.Add(new DataRelation("FK_E_A",
                 dataSet.Tables[parent].Columns[parentColumn],
                 dataSet.Tables[child].Columns[childColumn]));

            bindingSourceEmployees.DataSource = dataSet;
            bindingSourceEmployees.DataMember = parent;
            employeesGrid.DataSource = bindingSourceEmployees;

            bindingSourceAddresses.DataSource = bindingSourceEmployees;
            bindingSourceAddresses.DataMember = "FK_E_A";
            addressGrid.DataSource = bindingSourceAddresses;

            //turn these off

            dataSet.Relations.Add(new DataRelation("FK_D_A",
               dataSet.Tables["DEPARTMENTS"].Columns["DID"],
               dataSet.Tables["ACQUISITIONS"].Columns["DID"]));

            dataSet.Relations.Add(new DataRelation("FK_D_E",
               dataSet.Tables["DEPARTMENTS"].Columns["DID"],
               dataSet.Tables["EMPLOYEES"].Columns["DID"]));
               
            bindingSourceDepartments.DataSource = dataSet;
            bindingSourceDepartments.DataMember = "DEPARTMENTS";
            departmentsGrid.DataSource = bindingSourceDepartments;

            
            bindingSourceAcquisitions.DataSource = bindingSourceDepartments;
            bindingSourceAcquisitions.DataMember = "FK_D_A";
            acquisitionGrid.DataSource = bindingSourceAcquisitions;
            


        }

        private void Update_Click(object sender, EventArgs e)
        {
            dataAdapterEmployees.Update(dataSet.Tables[parent]);
            dataAdapterAddresses.Update(dataSet.Tables[child]);
            dataAdapterEmployees.Update(dataSet.Tables["DEPARTMENTS"]);
            dataAdapterAddresses.Update(dataSet.Tables["ACQUISITIONS"]);
        }

    }
}
