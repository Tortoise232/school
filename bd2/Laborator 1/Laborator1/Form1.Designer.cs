namespace Laborator1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.employeesGrid = new System.Windows.Forms.DataGridView();
            this.addressGrid = new System.Windows.Forms.DataGridView();
            this.update_tables = new System.Windows.Forms.Button();
            this.employeesLabel = new System.Windows.Forms.Label();
            this.addressLabel = new System.Windows.Forms.Label();
            this.acquisitionsLabel = new System.Windows.Forms.Label();
            this.departmentsLabel = new System.Windows.Forms.Label();
            this.acquisitionGrid = new System.Windows.Forms.DataGridView();
            this.departmentsGrid = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.employeesGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.addressGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.acquisitionGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.departmentsGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // employeesGrid
            // 
            this.employeesGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.employeesGrid.Location = new System.Drawing.Point(801, 57);
            this.employeesGrid.Margin = new System.Windows.Forms.Padding(4);
            this.employeesGrid.Name = "employeesGrid";
            this.employeesGrid.Size = new System.Drawing.Size(696, 257);
            this.employeesGrid.TabIndex = 0;
            // 
            // addressGrid
            // 
            this.addressGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.addressGrid.Location = new System.Drawing.Point(801, 380);
            this.addressGrid.Margin = new System.Windows.Forms.Padding(4);
            this.addressGrid.Name = "addressGrid";
            this.addressGrid.Size = new System.Drawing.Size(696, 257);
            this.addressGrid.TabIndex = 1;
            // 
            // update_tables
            // 
            this.update_tables.Location = new System.Drawing.Point(24, 678);
            this.update_tables.Margin = new System.Windows.Forms.Padding(4);
            this.update_tables.Name = "update_tables";
            this.update_tables.Size = new System.Drawing.Size(109, 28);
            this.update_tables.TabIndex = 2;
            this.update_tables.Text = "UpdateTables";
            this.update_tables.UseVisualStyleBackColor = true;
            this.update_tables.Click += new System.EventHandler(this.Update_Click);
            // 
            // employeesLabel
            // 
            this.employeesLabel.AutoSize = true;
            this.employeesLabel.Location = new System.Drawing.Point(800, 23);
            this.employeesLabel.Name = "employeesLabel";
            this.employeesLabel.Size = new System.Drawing.Size(158, 17);
            this.employeesLabel.TabIndex = 3;
            this.employeesLabel.Text = "Department employees:";
            this.employeesLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // addressLabel
            // 
            this.addressLabel.AutoSize = true;
            this.addressLabel.Location = new System.Drawing.Point(798, 338);
            this.addressLabel.Name = "addressLabel";
            this.addressLabel.Size = new System.Drawing.Size(130, 17);
            this.addressLabel.TabIndex = 4;
            this.addressLabel.Text = "Employee Address:";
            this.addressLabel.Click += new System.EventHandler(this.addressLabel_Click);
            // 
            // acquisitionsLabel
            // 
            this.acquisitionsLabel.AutoSize = true;
            this.acquisitionsLabel.Location = new System.Drawing.Point(21, 338);
            this.acquisitionsLabel.Name = "acquisitionsLabel";
            this.acquisitionsLabel.Size = new System.Drawing.Size(157, 17);
            this.acquisitionsLabel.TabIndex = 5;
            this.acquisitionsLabel.Text = "Department acquisition:";
            this.acquisitionsLabel.Click += new System.EventHandler(this.label3_Click);
            // 
            // departmentsLabel
            // 
            this.departmentsLabel.AutoSize = true;
            this.departmentsLabel.Location = new System.Drawing.Point(21, 23);
            this.departmentsLabel.Name = "departmentsLabel";
            this.departmentsLabel.Size = new System.Drawing.Size(89, 17);
            this.departmentsLabel.TabIndex = 7;
            this.departmentsLabel.Text = "Departments";
            this.departmentsLabel.Click += new System.EventHandler(this.label5_Click);
            // 
            // acquisitionGrid
            // 
            this.acquisitionGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.acquisitionGrid.Location = new System.Drawing.Point(24, 380);
            this.acquisitionGrid.Name = "acquisitionGrid";
            this.acquisitionGrid.RowTemplate.Height = 24;
            this.acquisitionGrid.Size = new System.Drawing.Size(696, 257);
            this.acquisitionGrid.TabIndex = 9;
            // 
            // departmentsGrid
            // 
            this.departmentsGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.departmentsGrid.Location = new System.Drawing.Point(24, 57);
            this.departmentsGrid.Name = "departmentsGrid";
            this.departmentsGrid.RowTemplate.Height = 24;
            this.departmentsGrid.Size = new System.Drawing.Size(696, 257);
            this.departmentsGrid.TabIndex = 8;
            this.departmentsGrid.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1813, 854);
            this.Controls.Add(this.acquisitionGrid);
            this.Controls.Add(this.departmentsGrid);
            this.Controls.Add(this.departmentsLabel);
            this.Controls.Add(this.acquisitionsLabel);
            this.Controls.Add(this.addressLabel);
            this.Controls.Add(this.employeesLabel);
            this.Controls.Add(this.update_tables);
            this.Controls.Add(this.addressGrid);
            this.Controls.Add(this.employeesGrid);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.employeesGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.addressGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.acquisitionGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.departmentsGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView employeesGrid;
        private System.Windows.Forms.DataGridView addressGrid;
        private System.Windows.Forms.Button update_tables;
        private System.Windows.Forms.Label employeesLabel;
        private System.Windows.Forms.Label addressLabel;
        private System.Windows.Forms.Label acquisitionsLabel;
        private System.Windows.Forms.Label departmentsLabel;
        private System.Windows.Forms.DataGridView acquisitionGrid;
        private System.Windows.Forms.DataGridView departmentsGrid;
    }
}

