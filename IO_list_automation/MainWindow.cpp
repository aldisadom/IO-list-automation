#include "MainWindow.h"
#include "config.h"
//#include "Python.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThreadAttribute]

void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	init_strings();
	wstring texts;
	// code before starting aplication
	cfg_reads(&parameters, L" ");
	
	if (parameters.clr_logs_on_start == 1)
	{
		reset_logs();
	}
	if (unstable_release == 1)
	{
		texts = str.Error.unstable.s[lang];
		err_write_show(texts);
	}
	texts = L"---------------------------------------------------------";
	err_write(texts);

	GlobalForm::forma = gcnew IOlistautomation::MainWindow;
	GlobalForm::forma->ClientSize = System::Drawing::Size(parameters.width, parameters.height);

	GlobalForm::forma->Main_init();


	Application::Run(GlobalForm::forma);
}
