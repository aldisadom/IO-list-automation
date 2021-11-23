#include "config.h"
#include "Instance_scada.h"

#include <stdio.h>
#include <stdlib.h>
#include "ResultForm.h"

#include "objects.h"
#include "signals.h"
#include "Declare.h"
#include "IO_declare.h"

#include "Instance_wincc.h"
#include "Global_Functions.h"


void Wincc_get_addr_siemens_data(long &Addres, wstring &Base_addres, wstring Obj_reference, wstring Adress_val)
{
	wstring Tmp_string = L"";
	Base_addres = Obj_reference;
	Base_addres.append(L".");
	Tmp_string = Adress_val;
	Tmp_string = Tmp_string.substr(0, Tmp_string.find(L".", 0));
	Base_addres.append(Tmp_string);
	Base_addres.append(L",");
	Tmp_string = Adress_val;
	Addres = Tmp_string.find(L" ", 0);
	Tmp_string = Tmp_string.substr(Addres + 1, Tmp_string.size() - Addres);
	Addres = wstring_to_long(Tmp_string);
}

void Wincc_get_addr_beckhoff_data(long &Addres, wstring &Base_addres, wstring Obj_reference, wstring Adress_val)
{
	wstring Tmp_string = L"";
	Base_addres = Obj_reference;
	Base_addres.append(L".");
	Tmp_string = Adress_val;
	Addres = Tmp_string.find(L"W", 0);
	Tmp_string = Tmp_string.substr(Addres + 1, Tmp_string.size() - Addres);
	Addres = wstring_to_long(Tmp_string);
	Addres = Addres + 400001;
}

int Init_Wincc_vlv(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Init_Wincc_mot(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Init_Wincc_pid(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Init_Wincc_hc(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}


int Init_Wincc_ai(int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}



int Instance_Wincc_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Instance_Wincc_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Instance_Wincc_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}


int Instance_Wincc_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}

int Instance_Wincc_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid)
{
	Display_no_function(L"");
	return 1;
}
