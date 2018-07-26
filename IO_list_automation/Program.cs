using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using Excel = Microsoft.Office.Interop.Excel;
using System.IO;

namespace WindowsFormsApp1
{


    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
    public class design
    {
        public  List<string> cabinet = new List<string>();          //collumn 2
        public  List<string> Module = new List<string>();           //collumn 3
        public  List<string> Pin = new List<string>();              //collumn 4
        public  List<string> Chanel = new List<string>();           //collumn 5
        public  List<string> Function_text = new List<string>();    //collumn 6
        public  List<string> Page = new List<string>();             //collumn 7

        public void read_data()
        {
             OpenFileDialog importfile = new OpenFileDialog();
            //importfile.Filter = "Excel Documents (*.xls)|*.xls";
            //importfile.FileName = "Inventory_Adjustment_Export.xls";
            if (importfile.ShowDialog() == DialogResult.OK)
            {
                Excel.Application app = new Microsoft.Office.Interop.Excel.Application();
                Excel.Workbook workbook = app.Workbooks.Open(importfile.FileName, true, true);
                Excel.Worksheet worksheet = workbook.ActiveSheet;
                int rcount = worksheet.UsedRange.Rows.Count;
                int ColumnCount = worksheet.UsedRange.Columns.Count;
                string reiksme = " ";
                rcount = 10;
                for (int x = 0; x < ColumnCount; x++)
                {
                    for (int i = 0; i < rcount; i++)
                    {
                        reiksme = worksheet.Cells[i + 1, 1].Value;
                        if (reiksme == null)
                        {
                            cabinet.Add(" ");
                        }
                        else
                        {
                            cabinet.Add(reiksme);
                        }
                    }
                }
                workbook.Close();
                app.Quit();
            }
        }
    }
}
