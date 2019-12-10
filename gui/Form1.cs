using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Threading;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace gui
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            pictureBox1.ImageLocation = @"C:\Users\Lenovo\Desktop\Studia\Semestr VII\PKSS\schemat.png";
        }

        public void FontSetter()
        {
            Fzm.AutoSize = false;
            Fzm.Height = 25;
            Fzm.Width = 60;
            Fzm.Font = new Font("Arial", 15);
        }

        private void PictureBox1_Click(object sender, EventArgs e)
        {
            
        }

        void readingFromLog()
        {
            bool started = false;
            using (var reader = new StreamReader(@"C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\logi.csv"))
            {
                while (!reader.EndOfStream)
                {
                    var line = reader.ReadLine();
                    var values = line.Split(',');

                    if (started)
                    {
                        Tzad.Text = values[1];
                        Tzad1.Text = values[1];
                        Fzm.Text = values[2];
                        Tzm.Text = values[3];
                        Tpm.Text = values[4];
                        Tpco.Text = values[5];
                        Tzco.Text = values[6];
                        T0.Text = values[7];
                        Tcob0.Text = values[8];
                        Tcob1.Text = values[9];
                        Tr0.Text = values[10];
                        Tr1.Text = values[11];
                        Thread.Sleep(500);
                        Application.DoEvents();
                    }
                    started = true;
                }
            }
        }

        private void Start_Click(object sender, EventArgs e)
        {
            readingFromLog();
        }

        private void Tpm_Click(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {

            string P_wymiennika = pw.Text;
            string I_wymiennika = iw.Text;
            string D_wymiennika = dw.Text;

            string filePath = @"C:\Users\Lenovo\Desktop\c_level\Debug\PIDwymiennika.csv";
            var csv = new StringBuilder();
            var newLine = string.Format("{0},{1},{2}", P_wymiennika, I_wymiennika, D_wymiennika);
            var final = "1 " + newLine;
            csv.AppendLine(final);
            File.WriteAllText(filePath, csv.ToString());

            Process p = Process.Start("C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\c_level.exe");
            readingFromLog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Tzm_Click(object sender, EventArgs e)
        {

        }

        private void Pidbut1_Click(object sender, EventArgs e)
        {
            string P_wymiennika = pb1.Text;
            string I_wymiennika = ib1.Text;
            string D_wymiennika = db1.Text;

            string filePath = @"C:\Users\Lenovo\Desktop\c_level\Debug\PIDbudynku1.csv";
            var csv = new StringBuilder();
            var newLine = string.Format("{0},{1},{2}", P_wymiennika, I_wymiennika, D_wymiennika);
            var final = "1 " + newLine;
            csv.AppendLine(final);
            File.WriteAllText(filePath, csv.ToString());

            Process p = Process.Start("C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\c_level.exe");
        }
    }
}
