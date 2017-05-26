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
        SqlDataAdapter daU, daP;
        DataSet ds;
        BindingSource bsU, bsP;
        SqlCommandBuilder cbp;
        private void Form1_Load(object sender, EventArgs e)
        {
          
            dbConn = new SqlConnection(@"Server=DESKTOP-V3PAQVA\GNCSB;" + "Database=MiniFacebook;Integrated Security=SSPI;");
            Console.Write(dbConn);
            ds = new DataSet();

            daU = new SqlDataAdapter("SELECT * FROM Users", dbConn);
            daP = new SqlDataAdapter("SELECT * FROM Posts", dbConn);

            daU.Fill(ds, "Users");
            daP.Fill(ds, "Posts");

            cbp = new SqlCommandBuilder(daP);

            ds.Relations.Add(new DataRelation("FK_P_U",
                    ds.Tables["Users"].Columns["UserID"],
                    ds.Tables["Posts"].Columns["UserID"]));
            bsU = new BindingSource();
            bsP = new BindingSource();

            bsU.DataSource = ds;
            bsU.DataMember = "Users";
            dataGridView1.DataSource = bsU; //load the data here lol      

            bsP.DataSource = bsU;
            bsP.DataMember = "FK_P_U";
            dataGridView2.DataSource = bsP; //load the data here lol 
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {

            daU.Update(ds.Tables["Users"]);
            daP.Update(ds.Tables["Posts"]);
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
