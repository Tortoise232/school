using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }
        SqlConnection con;
        SqlDataAdapter adS, adP;
        DataSet ds;
        private void Form1_Load(object sender, EventArgs e)
        {
            con = new SqlConnection();
            ds = new DataSet();
            adS = new SqlDataAdapter("SELECT * FROM  System", con);
            adP = new SqlDataAdapter("SELECT * FROM Planets", con);

            adS.Fill(ds, "System");
            adP.Fill(ds, "Planets");

            SqlCommandBuilder sqlcbS = new SqlCommandBuilder(adS);
            SqlCommandBuilder sqlcbP = new SqlCommandBuilder(adP);

            DataRelation dr = new DataRelation("FK_Solar_Planets", ds.Tables["System"].Columns["ssid"], ds.Tables["Planets"].Columns["ssid"]);
            BindingSource bindd = new BindingSource(ds, "System");

            ds.Relations.Add(dr);
            BindingSource binddp = new BindingSource(bindd, "FK_Solar_Planets");

            solarGrid.DataSource = bindd;
            planetsGrid.DataSource = binddp;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            adS.Update(ds.Tables["System"]);
            adP.Update(ds.Tables["Planets"]);
        }
    }
}