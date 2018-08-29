#include "config.h"
#include "Instance.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "ResultForm.h"

#include "signals.h"
#include "IO_declare.h"

using namespace std;

std::wstring IO_generate_signal(int index)
{
	wstring text = signals.data[index].Cabinet;
	text.append(L"_");
	text.append(signals.data[index].Module);
	text.append(L"_");
	text.append(signals.data[index].Channel);

	return text;
}
