using System;
using System.Data;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace Lab1
{
    public partial class Form1 : Form
    {
        SqlConnection _connection;
        DataSet _dataSet;
        SqlDataAdapter _childDataAdapter;
        SqlDataAdapter _parentDataAdapter;
        BindingSource _childBindingSource;
        BindingSource _parentBindingSource;

        public Form1()
        {
            InitializeComponent();

            _connection = new SqlConnection(@" Data Source= DESKTOP-V900N5R\ANDREI; Initial Catalog=WorldChamp; Integrated Security=true");

            _connection.Open();
            _dataSet = new DataSet();

            _childDataAdapter = new SqlDataAdapter(ConfigurationManager.AppSettings["child_participants_select"], _connection);
            _parentDataAdapter = new SqlDataAdapter(ConfigurationManager.AppSettings["parent_category_select"], _connection);

            _childDataAdapter.Fill(_dataSet, ConfigurationManager.AppSettings["childTable"]);
            _parentDataAdapter.Fill(_dataSet, ConfigurationManager.AppSettings["parentTable"]);

            // for update
            SqlCommandBuilder sb = new SqlCommandBuilder(_childDataAdapter);
            SqlCommandBuilder gb = new SqlCommandBuilder(_parentDataAdapter);

            // for child and parent
            _childBindingSource = new BindingSource();
            _parentBindingSource = new BindingSource();

            _parentBindingSource.DataSource = _dataSet;
            _parentBindingSource.DataMember = ConfigurationManager.AppSettings["parentTable"];
            dataGridViewParent.DataSource = _parentBindingSource;

            // add new relationship between the parent table and the child table 
            _dataSet.Relations.Add(new DataRelation("FK_Category_Participants", 
                _dataSet.Tables[ConfigurationManager.AppSettings["parentTable"]].Columns[ConfigurationManager.AppSettings["parent_category_id"]], 
                _dataSet.Tables[ConfigurationManager.AppSettings["childTable"]].Columns[ConfigurationManager.AppSettings["child_category_id"]]
            ));

            _childBindingSource.DataSource = _parentBindingSource;
            _childBindingSource.DataMember = "FK_Category_Participants";
            dataGridViewChild.DataSource = _childBindingSource;
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                // check if to delete or not
                DialogResult _dialogResult = MessageBox.Show("Do you want to delete?\n P.S. You can not undo", "Delete confirmation", MessageBoxButtons.YesNo);

                if (_dialogResult == DialogResult.Yes)
                {
                    _childBindingSource.RemoveCurrent();
                    MessageBox.Show("Delete Done !!");
                }
                else
                {
                    MessageBox.Show("Delete Canceled !!");
                }
            }
            catch
            {
                MessageBox.Show("Delete not working !!");
            }
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            try
            {
                // update
                _childDataAdapter.Update(_dataSet.Tables[ConfigurationManager.AppSettings["childTable"]]);
                
                // clear dataSet
                _dataSet.Tables[ConfigurationManager.AppSettings["childTable"]].Clear();
   
                // fill dataSet with new data
                _childDataAdapter.Fill(_dataSet, ConfigurationManager.AppSettings["childTable"]);

                MessageBox.Show("Update Done !!");
            }
            catch
            {
                MessageBox.Show("Update not working !!");
            }
        }

        private void childLabel_Click(object sender, EventArgs e)
        {

        }
    }
}
