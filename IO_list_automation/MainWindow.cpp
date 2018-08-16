#include "MainWindow.h"
#include "config.h"




using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;




[STAThreadAttribute]



void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	GlobalForm::forma = gcnew IOlistautomation::MainWindow;

	// code before starting aplication
	cfg_reads(&parameters);
	if (parameters.clr_logs_on_start == 1)
	{
		reset_logs();
	}
	if (unstable_release == 1)
	{
		strcpy_s(err_txt, sizeof err_txt, "Si programos versija nera pilnai testuota tad atsargiai naudotis !!!");
		err_write_show(err_txt);
	}
	if (parameters.debug == 1)
	{
		// because forms designer gives error and cant eddit it
		IOlistautomation::MainWindow flora;		
	}
	
	Application::Run(GlobalForm::forma);
}
