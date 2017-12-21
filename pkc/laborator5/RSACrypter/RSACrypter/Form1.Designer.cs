namespace RSACrypter
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
            this.qtextbox = new System.Windows.Forms.TextBox();
            this.totienttextbox = new System.Windows.Forms.TextBox();
            this.publicKey = new System.Windows.Forms.TextBox();
            this.ntextbox = new System.Windows.Forms.TextBox();
            this.privateKey = new System.Windows.Forms.TextBox();
            this.ptextbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.plainText = new System.Windows.Forms.RichTextBox();
            this.cipherText = new System.Windows.Forms.RichTextBox();
            this.encryptButton = new System.Windows.Forms.Button();
            this.decryptButton = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // qtextbox
            // 
            this.qtextbox.Location = new System.Drawing.Point(81, 21);
            this.qtextbox.Name = "qtextbox";
            this.qtextbox.Size = new System.Drawing.Size(56, 22);
            this.qtextbox.TabIndex = 0;
            this.qtextbox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // totienttextbox
            // 
            this.totienttextbox.Location = new System.Drawing.Point(81, 143);
            this.totienttextbox.Name = "totienttextbox";
            this.totienttextbox.Size = new System.Drawing.Size(56, 22);
            this.totienttextbox.TabIndex = 2;
            // 
            // publicKey
            // 
            this.publicKey.Location = new System.Drawing.Point(618, 24);
            this.publicKey.Name = "publicKey";
            this.publicKey.Size = new System.Drawing.Size(233, 22);
            this.publicKey.TabIndex = 3;
            // 
            // ntextbox
            // 
            this.ntextbox.Location = new System.Drawing.Point(81, 97);
            this.ntextbox.Name = "ntextbox";
            this.ntextbox.Size = new System.Drawing.Size(56, 22);
            this.ntextbox.TabIndex = 4;
            // 
            // privateKey
            // 
            this.privateKey.Location = new System.Drawing.Point(618, 61);
            this.privateKey.Name = "privateKey";
            this.privateKey.Size = new System.Drawing.Size(233, 22);
            this.privateKey.TabIndex = 5;
            // 
            // ptextbox
            // 
            this.ptextbox.Location = new System.Drawing.Point(81, 59);
            this.ptextbox.Name = "ptextbox";
            this.ptextbox.Size = new System.Drawing.Size(56, 22);
            this.ptextbox.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(55, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 17);
            this.label1.TabIndex = 7;
            this.label1.Text = "q:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(514, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 17);
            this.label2.TabIndex = 8;
            this.label2.Text = "Private key:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(516, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(80, 17);
            this.label3.TabIndex = 9;
            this.label3.Text = "Public key: ";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 146);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 17);
            this.label4.TabIndex = 10;
            this.label4.Text = "totient:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(55, 100);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(20, 17);
            this.label5.TabIndex = 11;
            this.label5.Text = "n:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(55, 59);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(20, 17);
            this.label6.TabIndex = 12;
            this.label6.Text = "p:";
            // 
            // plainText
            // 
            this.plainText.Location = new System.Drawing.Point(84, 234);
            this.plainText.Name = "plainText";
            this.plainText.Size = new System.Drawing.Size(452, 63);
            this.plainText.TabIndex = 13;
            this.plainText.Text = "";
            // 
            // cipherText
            // 
            this.cipherText.Location = new System.Drawing.Point(84, 346);
            this.cipherText.Name = "cipherText";
            this.cipherText.Size = new System.Drawing.Size(452, 63);
            this.cipherText.TabIndex = 14;
            this.cipherText.Text = "";
            // 
            // encryptButton
            // 
            this.encryptButton.Location = new System.Drawing.Point(570, 236);
            this.encryptButton.Name = "encryptButton";
            this.encryptButton.Size = new System.Drawing.Size(99, 60);
            this.encryptButton.TabIndex = 15;
            this.encryptButton.Text = "3NKRYP7";
            this.encryptButton.UseVisualStyleBackColor = true;
            this.encryptButton.Click += new System.EventHandler(this.encryptButton_Click);
            // 
            // decryptButton
            // 
            this.decryptButton.Location = new System.Drawing.Point(570, 346);
            this.decryptButton.Name = "decryptButton";
            this.decryptButton.Size = new System.Drawing.Size(99, 60);
            this.decryptButton.TabIndex = 16;
            this.decryptButton.Text = "D3NKRYP7";
            this.decryptButton.UseVisualStyleBackColor = true;
            this.decryptButton.Click += new System.EventHandler(this.decryptButton_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(81, 214);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(69, 17);
            this.label7.TabIndex = 17;
            this.label7.Text = "Plain text:";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(81, 326);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(75, 17);
            this.label8.TabIndex = 18;
            this.label8.Text = "Cipher text";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(872, 549);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.decryptButton);
            this.Controls.Add(this.encryptButton);
            this.Controls.Add(this.cipherText);
            this.Controls.Add(this.plainText);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ptextbox);
            this.Controls.Add(this.privateKey);
            this.Controls.Add(this.ntextbox);
            this.Controls.Add(this.publicKey);
            this.Controls.Add(this.totienttextbox);
            this.Controls.Add(this.qtextbox);
            this.Name = "Form1";
            this.Text = "RSA Encryptor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox qtextbox;
        private System.Windows.Forms.TextBox totienttextbox;
        private System.Windows.Forms.TextBox publicKey;
        private System.Windows.Forms.TextBox ntextbox;
        private System.Windows.Forms.TextBox privateKey;
        private System.Windows.Forms.TextBox ptextbox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RichTextBox plainText;
        private System.Windows.Forms.RichTextBox cipherText;
        private System.Windows.Forms.Button encryptButton;
        private System.Windows.Forms.Button decryptButton;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
    }
}

