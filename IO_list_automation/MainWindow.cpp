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

	strcpy_s(err_txt, sizeof err_txt, "---------------------------------------------------------");
	err_write(err_txt);

	GlobalForm::forma = gcnew IOlistautomation::MainWindow;
	GlobalForm::forma->ClientSize = System::Drawing::Size(parameters.width, parameters.height);

	GlobalForm::forma->Main_init();


	Application::Run(GlobalForm::forma);
}
