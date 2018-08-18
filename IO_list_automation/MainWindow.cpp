#include "MainWindow.h"
#include "config.h"




using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;




[STAThreadAttribute]



void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// code before starting aplication
	cfg_reads(&parameters);
	if (parameters.clr_logs_on_start == 1)
	{
		reset_logs();
	}
	if (unstable_release == 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_unstable[lang]);
		err_write_show(err_txt);
	}

	// because forms designer gives error and cant eddit it sometimes
//	IOlistautomation::MainWindow flora;		

	strcpy_s(err_txt, sizeof err_txt, "---------------------------------------------------------");
	err_write(err_txt);

	GlobalForm::forma = gcnew IOlistautomation::MainWindow;
//	this->valveToolStripMenuItem2->BackColor = System::Drawing::Color::Aqua;

	GlobalForm::forma->ClientSize = System::Drawing::Size(parameters.width, parameters.height);

	Application::Run(GlobalForm::forma);
}
