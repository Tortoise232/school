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

namespace PracticBazeDeDate2
{
    public partial class Form1 : Form
    {
        SqlConnection dbConn;
        SqlDataAdapter daProducer, daChocolates;
        DataSet ds;
        BindingSource bsProducer, bsChocolates;
        SqlCommandBuilder cbChocolate;
        SqlCommandBuilder cbProducer;
        private void Form1_Load(object sender, EventArgs e)
        {
          
            dbConn = new SqlConnection(@"Server=DESKTOP-V3PAQVA\GNCSB;" + "Database=Practic;Integrated Security=SSPI;");
            Console.Write(dbConn);
            ds = new DataSet();

            daProducer = new SqlDataAdapter("SELECT * FROM Producer", dbConn);
            daChocolates = new SqlDataAdapter("SELECT * FROM Chocolate", dbConn);

            daProducer.Fill(ds, "Producer");
            daChocolates.Fill(ds, "Chocolate");

            cbChocolate = new SqlCommandBuilder(daChocolates);
            cbProducer = new SqlCommandBuilder(daChocolates);


            ds.Relations.Add(new DataRelation("FK_C_P",
                    ds.Tables["Producer"].Columns["ProducerID"],
                    ds.Tables["Chocolate"].Columns["ProducerID"]));
            bsProducer = new BindingSource();
            bsChocolates = new BindingSource();

            bsProducer.DataSource = ds;
            bsProducer.DataMember = "Producer";
            dataGridView1.DataSource = bsProducer; //load the data here lol      

            bsChocolates.DataSource = bsProducer;
            bsChocolates.DataMember = "FK_C_P";
            dataGridView2.DataSource = bsChocolates; //load the data here lol 
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {

            daProducer.Update(ds.Tables["Producer"]);
            daChocolates.Update(ds.Tables["Chocolate"]);
        }

        public Form1()
        {
            InitializeComponent();

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {     
        }
    }
}
