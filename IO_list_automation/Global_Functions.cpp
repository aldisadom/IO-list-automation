#include "config.h"
#include "MainWindow.h"
#include "signals.h"
#include "design.h"
#include "objects.h"
#include "Trend_data.h"
#include "Global_Functions.h"
#include <codecvt>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")


using namespace std;
using namespace IOlistautomation;

HANDLE hMapFile_out;
LPCTSTR pBuf_out;

HANDLE hMapFile_in;
LPCTSTR pBuf_in;

int create_shared_memmory(wstring name, DWORD buff_size)
{
	wstring texts;

	hMapFile_out = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		buff_size,                // maximum object size (low-order DWORD)
		name.c_str());                 // name of mapping object

	if (hMapFile_out == NULL)
	{
		texts = str.Error.Create_memory_map_obj.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);
		return 1;
	}
	pBuf_out = (LPTSTR)MapViewOfFile(hMapFile_out,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		buff_size);

	if (pBuf_out == NULL)
	{
		texts = str.Error.Create_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);

		CloseHandle(hMapFile_out);
		return 1;
	}

	LPWSTR szMsg = L"asdfghjkl 123456789";
	CopyMemory((PVOID)pBuf_out, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));

	return 0;
}

int read_shared_memory(wstring name, DWORD buff_size)
{
	wstring texts;

	hMapFile_in = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   // read/write access
		FALSE,                 // do not inherit the name
		name.c_str());               // name of mapping object

	if (hMapFile_in == NULL)
	{
		texts = str.Error.Open_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);
		return 1;
	}

	pBuf_in = (LPTSTR)MapViewOfFile(hMapFile_in, // handle to map object
		FILE_MAP_ALL_ACCESS,  // read/write permission
		0,
		0,
		buff_size);

	if (pBuf_in == NULL)
	{
		texts = str.Error.Create_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);

		CloseHandle(hMapFile_in);

		return 1;
	}

	return 0;
}

void clear_shared_memmory()
{
	UnmapViewOfFile(pBuf_in);
	CloseHandle(hMapFile_in);

	UnmapViewOfFile(pBuf_out);
	CloseHandle(hMapFile_out);
}


wstring String_remove_trailing_zero(wstring text)
{
	wstring str = text;
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	int a = str.size() - 1;
	int b = str.find(L".");
	if (a == b)
	{
		str.erase(b);
	}
	return str;
}
// --------Need to add more casses if there is added more tabs in gridview----------------

// get grid based on function index
System::Windows::Forms::DataGridView^ Global_function_grid(int index_function)
{
	switch (index_function)
	{
	case Design_grid_index:	return GlobalForm::forma->Design_grid;
		break;
	case Signals_grid_index:return GlobalForm::forma->Signals_grid;
		break;
	case Objects_grid_index:return GlobalForm::forma->Object_grid;
		break;
	case Trend_data_grid_index:return GlobalForm::forma->Trend_data_grid;
		break;



	default: return GlobalForm::forma->Design_grid;
		break;
	}
}


// get function text based on function index
wstring Global_function_txt(int index_function, int language)
{
	switch (index_function)
	{
	case Design_grid_index:	return  str.General.design_txt.s[language];
		break;
	case Signals_grid_index:return str.General.signals_txt.s[language];
		break;
	case Objects_grid_index:return  str.General.objects_txt.s[language];
		break;



	default:	return str.General.design_txt.s[language];
		break;
	}
}
// get confirm text based on function index
wstring Global_confirm_txt(int index_function, int language)
{
	switch (index_function)
	{
	case Design_grid_index:	return str.Confirm.design_overwrite.s[language];
		break;
	case Signals_grid_index:return str.Confirm.signal_overwrite.s[language];
		break;
	case Objects_grid_index:return str.Confirm.objects_overwrite.s[language];
		break;



	default:	return str.Confirm.design_overwrite.s[language];
		break;
	}
}
// get extension text based on function index
wstring Global_function_extension_txt(int index_function)
{
	switch (index_function)
	{
	case Design_grid_index:	return L".psave";
		break;
	case Signals_grid_index:return L".ssave";
		break;
	case Objects_grid_index:return L".osave";
		break;



	default:	return  L".psave";
		break;
	}
}


// check if row is valid based on function index
int Global_valid_row_check(int index_function, int index)
{
	switch (index_function)
	{
	case Design_grid_index:	 return Project_valid_row_check(index);
		break;
	case Signals_grid_index: return Signals_valid_row_check(index);
		break;
	case Objects_grid_index: return Objects_valid_row_check(index);
		break;
	case Trend_data_grid_index:return Trend_data_valid_row_check(index);
		break;


	default: return Project_valid_row_check(index);
		break;
	}
}
//// get cell data based on function index
wstring Global_get_data_switch(int index_function, int iCol, int index)
{
	switch (index_function)
	{
	case Design_grid_index:	 return Project_get_data_switch(iCol, index);
		break;
	case Signals_grid_index: return Signals_get_data_switch(iCol, index);
		break;
	case Objects_grid_index: return Objects_get_data_switch(iCol, index);
		break;
	case Trend_data_grid_index:return Trend_data_get_data_switch(iCol, index);
		break;


	default:  return Project_get_data_switch(iCol, index);
		break;
	}

}
//// put data to cell based on function index
void Global_put_data_switch(int index_function,int iCol, int index, wstring cell_text)
{
	switch (index_function)
	{
	case Design_grid_index:	 Project_put_data_switch(iCol, index, project,cell_text);
		break;
	case Signals_grid_index: Signals_put_data_switch(iCol, index, cell_text);
		break;
	case Objects_grid_index: Objects_put_data_switch(iCol, index, cell_text);
		break;
	case Trend_data_grid_index: Trend_data_put_data_switch(iCol, index, cell_text);
		break;

	default:	 Project_put_data_switch(iCol, index, project, cell_text);
		break;
	}
}
// get selected cpu name
wstring Global_get_CPU_name(int index_cpu)
{
	switch (index_cpu)
	{
	case Beckhoff_index:
		return L"Beckhoff";
		break;
	case Siemens_index:
		return L"Siemens";
		break;
	case Schneider_index:
		return L"Schneider";
		break;
	case ABB_800xA_index:
		return L"ABB 800xA";
		break;

	default:
		err_prog();
		return L" ";
		break;
	}
	return 0;
}
// get selected scada name
wstring Global_get_scada_name(int index_scada)
{
	switch (index_scada)
	{
	case System_platform_index:
		return L"System platform";
		break;
	case WinCC_index:
		return L"WinCC";
		break;
	default:
		err_prog();
		return L" ";
		break;
	}
	return 0;
}
//resize memory data based on function index
void Global_resize_data(int index_function, int size)
{
	switch (index_function)
	{
	case Design_grid_index:	project.data.resize(size);
		break;
	case Signals_grid_index: signals.data.resize(size);
		break;
	case Objects_grid_index: objects.data.resize(size);
		break;
	case Trend_data_grid_index: Trend_data.data.resize(size);
		break;


	default:	 project.data.resize(size);
		break;
	}
}

//delete memory row based on function index
void Global_delete_data_row(int index_function, int row)
{
	switch (index_function)
	{
	case Design_grid_index:	project.data.erase(project.data.begin() + row);
		break;
	case Signals_grid_index: signals.data.erase(signals.data.begin() + row);
		break;
	case Objects_grid_index: objects.data.erase(objects.data.begin() + row);
		break;
	case Trend_data_grid_index: Trend_data.data.erase(Trend_data.data.begin() + row);
		break;


	default:	 project.data.erase(project.data.begin() + row);
		break;
	}
}
//delete all memory data based on function index
void Global_delete_all_data(int index_function)
{
	switch (index_function)
	{
	case Design_grid_index:	project.data = {};
							project.valid_entries = 0;
		break;
	case Signals_grid_index: signals.data = {};
							 signals.valid_entries = 0;
		break;
	case Objects_grid_index: objects.data = {};
							 objects.valid_entries = 0;
		break;
	case Trend_data_grid_index: Trend_data.data = {};
								Trend_data.valid_entries = 0;
							 break;


	default:	 project.data = {};
		break;
	}
}


//save data based on function index
void Global_choose_save(int index_function, bool auto_save, std::wstring file_name_global)
{
	switch (index_function)
	{
	case Design_grid_index:	 Global_save(index_function, auto_save, file_name_global, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		break;
	case Signals_grid_index: Global_save(index_function, auto_save, file_name_global, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
		break;
	case Objects_grid_index: Global_save(index_function, auto_save, file_name_global, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
		break;
	case Trend_data_grid_index: Global_save(index_function, auto_save, file_name_global, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.column_name_EN, Trend_data.column_name_LT, Trend_data.collumn_with);
		break;


	default:	 Global_save(index_function, auto_save, file_name_global, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		break;
	}
}
//load data based on function index
void Global_choose_Load(int index_function, std::wstring file_name_global)
{
	switch (index_function)
	{
	case Design_grid_index:	 Global_load(index_function, file_name_global, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		break;
	case Signals_grid_index: Global_load(index_function, file_name_global, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
		break;
	case Objects_grid_index: Global_load(index_function, file_name_global, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
		break;
	case Trend_data_grid_index: Global_load(index_function, file_name_global, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.column_name_EN, Trend_data.column_name_LT, Trend_data.collumn_with);
		break;


	default:	 Global_load(index_function, file_name_global, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		break;
	}
}




// --------Global function----------------------------------------------------
// saving data to file
int Global_save (int index_function, bool auto_save, std::wstring file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name_EN, const vector <wstring> &column_name_LT, vector <int> &collumn_with)
{
	wstring texts;
	Global_get_data_listview(index_function,valid_entries, number_collums, collumn_with, true);

	wstring funcion_text = Global_function_txt(index_function, lang);
	wstring extension = Global_function_extension_txt(index_function);
	wstring filter = L"Save document | *";

	// for knowing what function it is saved and its used for restoration
	wstring file_type = Global_function_txt(index_function, 1);


	filter.append(extension); //add extension to filter

	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = wstring_to_system_string(filter) +
		"|All Files|*.*";

	sfd->FileName = wstring_to_system_string(file_type);

	// first line is function text
	wstring cell_text = system_string_to_wstring(sfd->FileName);

	std::wstring file_name = L"_autosave";
	file_name.append(extension);

	if (valid_entries <= 1) //if there is no data no need to save, check if there is atleast 2 entries because one line in grid is empty
	{
		wstring texts = str.Error.no_data_save.s[lang];
		texts.append(error_separator);
		texts.append(funcion_text);
		err_write_show(texts);
		return 1;
	}
	int iCol;
	
	// when autosave=1 use _autosave.extension
	if (auto_save == 0) 
	{
		if (file_name_global.compare(L" ") == 0) // when no global file name open save dialog
		{
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				file_name = system_string_to_wstring(sfd->FileName);
			}
			else
			{
				texts = str.Error.canceled_selection.s[lang];
				err_write(texts);
				return 1;
			}
		}
		else // when global file name, add extension 
		{
			file_name = file_name_global;
			file_name.append(extension);
		}
		Show_progress(str.Progress.save.s[lang], valid_entries);
	}
	//create file with UTF-8 encoding
	std::wofstream file_out(file_name, std::ios::binary);
	std::locale utf16_locale(file_out.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::generate_header>);
	file_out.imbue(utf16_locale);

	texts = str.Info.save_data.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	info_write(texts);

	if (!file_out)
	{
		texts = str.Error.no_file_save.s[lang];
		texts.append(error_separator);
		texts.append(funcion_text);
		err_write_show(texts);
		return 1;
	}

	cell_text.append(L"\r\n");
	file_out << cell_text;
	cell_text = L"";

	// second line is collums names
	wstring column_name = L"";
	for ( iCol = 0; iCol <= number_collums; iCol++)
	{
		column_name = column_name_EN[iCol];
		cell_text.append(column_name);
		cell_text.append(separator);
	}
	cell_text.append(L"\r\n");
	file_out << cell_text;
	cell_text = L"";

	// third line is collums width
	for (unsigned int iCol = 0; iCol < collumn_with.size(); iCol++)
	{
		cell_text.append(int_to_wstring(collumn_with[iCol],0));
		cell_text.append(separator);
	}

	cell_text.append(L"\r\n");
	file_out << cell_text;

	wstring cell_text_write;
	for (int index = 0; index <= valid_entries; index++)
	{
		cell_text_write = L"";
		// fill all cells with data
		for (iCol = 0; iCol <= number_collums; iCol++)
		{
			cell_text = Global_get_data_switch(index_function,iCol, index);
			if (cell_text.empty() == 1) // if empty put space, because of loading when separators are nearby they are skipped 
			{
				cell_text = LPWSTR(L" ");
			}
			cell_text_write.append(cell_text);
			cell_text_write.append(separator);

		}
		// write all row data to file
		cell_text_write.append(L"\r\n");
		file_out << cell_text_write;
		set_progress_value(index);
	}
	file_out.close();

	Hide_progress();

	texts = str.Info.save_data.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	return 0;
}
//loading data from file	
int Global_load(int index_function,  std::wstring file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name_EN, const vector <wstring> &column_name_LT, vector <int> &collumn_with)
{
	wstring texts;
	wstring funcion_text = Global_function_txt(index_function, lang);
	wstring extension = Global_function_extension_txt(index_function);
	wstring filter = L"Load document | *";

	// for knowing what function it is saved and its used for restoration
	wstring file_type = Global_function_txt(index_function, 1);

	filter.append(extension); //add extension to filter

	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = wstring_to_system_string(filter) +
		"|All Files|*.*";
	
	
	if (valid_entries > 1) //if there is data ask if ok to overwrite, check if there is atleast 2 entries because one line in grid is empty
	{
		int result = show_confirm_window(Global_confirm_txt(index_function, lang));
		if (result == IDYES)
		{
			texts = str.Info.erase_data.s[lang];
			texts.append(info_separator);
			texts.append(funcion_text);
			info_write(texts);
		}
		else
		{
			texts = str.Error.canceled_selection.s[lang];
			err_write(texts);
			return 1;
		}
	}
	Global_delete_all_data(index_function); // delete all data

	wstring file_name;

	if (file_name_global.compare(L" ") == 0) // when no global file name open load dialog
	{
		if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			file_name = system_string_to_wstring(importfile->FileName);
		}
		else
		{
			texts = str.Error.canceled_selection.s[lang];
			err_write(texts);
			return 1;
		}
	}
	else // when global file name, add extension 
	{
		file_name = file_name_global;
		file_name.append(extension);
	}


	Show_progress(str.Progress.load.s[lang], 500); //making guess that load data is 500 long

	texts = str.Info.load_data.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	info_write(texts);


	//create file with UTF-8 encoding
	std::wifstream file_in(file_name);
	file_in.imbue(std::locale(file_in.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
	if (!file_in)
	{
		texts = str.Error.cant_open.s[lang];
		texts.append(error_separator);
		texts.append(funcion_text);
		err_write_show(texts);
		return 1;
	}

	int iCol = 0;
	int index = 0;

	wstring lines;
	wstring cell_text;
	std::getline(file_in, lines);

	// check if first line matches function that is called
	if (lines.find(funcion_text) < 0)
	{
		file_in.close();
		texts = str.Error.wrong_file.s[lang];
		texts.append(error_separator);
		texts.append(funcion_text);
		err_write_show(texts);
		return 1;
	}
	int separator_loc = 0;

	std::getline(file_in, lines);
	separator_loc = lines.find(separator);
	if (separator_loc < 0)
	{
		file_in.close();
		texts = str.Error.corrupted_file.s[lang];
		texts.append(error_separator);
		texts.append(funcion_text);
		err_write_show(texts);
		return 1;
	}
	cell_text = lines.substr(0, separator_loc);

	wstring column_name = L"";
	// check collumns names if all doesnt match, corrupted

	while (!lines.empty() && lines.compare(L"\n") != 0 && lines.compare(L"\r\n") != 0 && lines.compare(L"\r") != 0)
	{
		if (iCol > number_collums)
		{
			break;
		}
		column_name = column_name_EN[iCol];

		if (cell_text.compare(column_name) < 0)
		{
			if (parameters.try_import_if_corupt < 1)
			{
				file_in.close();			
				texts = str.Error.corrupted_file.s[lang];
				texts.append(error_separator);
				texts.append(funcion_text);
				err_write_show(texts);
				return 1;
			}
			else
			{
				texts = str.Error.corrupted_file_continue.s[lang];
				texts.append(error_separator);
				texts.append(funcion_text);
				err_write_show(texts);
			}
		}
		iCol++;
		lines=lines.substr(separator_loc+1);
		separator_loc = lines.find(separator);
		cell_text = lines.substr(0, separator_loc);		
	}	
	
	std::getline(file_in, lines);

	// needs editing, check column names if ok and get with of columns
	separator_loc = lines.find(separator);

	collumn_with.resize(number_collums+1);
	// get collumn with
	iCol = 0;
	while (!lines.empty() && lines.compare(L"\n") != 0 && lines.compare(L"\r\n") != 0 && lines.compare(L"\r") != 0)
	{
		cell_text = lines.substr(0, separator_loc);
		lines=lines.substr(separator_loc + 1);
		separator_loc = lines.find(separator);

		if (iCol > number_collums)
		{
			break;
		}
		collumn_with[iCol] = wstring_to_long(cell_text);
		iCol++;		
	}

	int a = 0;
	
	while (std::getline(file_in, lines))  // continue till end of file
	{
		//extend memory data at each line
		valid_entries = index;
		Global_resize_data(index_function,index + 1);
		iCol = 0;
		separator_loc = lines.find(separator);

		while (!lines.empty() && lines.compare(L"\n") != 0 && lines.compare(L"\r\n") != 0 && lines.compare(L"\r") != 0)
		{
			cell_text = lines.substr(0, separator_loc);
			lines=lines.substr(separator_loc + 1);
			separator_loc = lines.find(separator);

			if (cell_text.compare(L" ") != 0) // if there is thext between separators, put data to memory
			{
				Global_put_data_switch(index_function,iCol, index, cell_text);
			}
			iCol++;
		}
		a++;
		index++;
		if (a > 500) //if overfills start progress all over from 0
		{
			a = a - 500;
		}
		set_progress_value(a);
	}
	file_in.close();

	Hide_progress();

	texts = str.Info.load_data.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	// after load put data to gridview
	Global_put_data_listview(index_function, valid_entries, number_collums, column_name_EN, column_name_LT, collumn_with);

	return 0;
}


//restore collumn width from memory based on function index
void Global_put_width_list(int index_function, const int &number_collums, vector <int> &collumn_with)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	int a = collumn_with.size()-1;
	if (a > number_collums)
	{
		a = number_collums;
	}
	grid->AutoResizeColumns();

	// if automatic cullumn with, do not resize by data
	if (parameters.auto_column_with == 0)
	{		
		for (int i = 0; i <= a; i++)
		{
			if (collumn_with[i] > 0)
			{
				grid->Columns[i]->Width = collumn_with[i];
			}
		}
	}

}
//store collumn width from grid view based on function index
void Global_get_width_list(int index_function, const int &number_collums, vector <int> &collumn_with)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	int a = grid->ColumnCount-1;
	collumn_with.resize(number_collums+1);
	if (a > number_collums)
	{
		a = number_collums;
	}
	for (int i = 0; i <= a; i++)
	{
		collumn_with[i] = grid->Columns[i]->Width;  
	}
}
//delette grid based on function index
void Global_delete_list(int index_function, vector <int> &collumn_with)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	grid->Rows->Clear();
	grid->Columns->Clear();
}


//put data from memory to gridview based on function index
void Global_put_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name_EN, const vector <wstring> &column_name_LT, vector <int> &collumn_with)
{
	wstring texts;
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);

	//before puting data clear list
	Global_delete_list(index_function, collumn_with);
	GlobalForm::forma->Update();

	wstring funcion_text = Global_function_txt(index_function,lang);

	int iCol;

	Show_progress(str.Progress.grid_put.s[lang], valid_entries);
	texts = str.Info.put_to_grid.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	info_write(texts);

	// Add the columns.
	grid->ColumnCount = number_collums + 1;
	wstring column_name = L"";

	for (iCol = 0; iCol <= number_collums; iCol++)
	{
		// Load the names of the column headings from the string resources.
		if (parameters.Language = LT_index)
			column_name = column_name_LT[iCol];
		else
			column_name = column_name_EN[iCol];
		grid->Columns[iCol]->Name = wstring_to_system_string(column_name);
	}

	wstring cell_text = L"";

	int grid_cell = 0;
	if (valid_entries > 0)
	{
		for (int index = 0; index <= valid_entries; index++)
		{

			if (Global_valid_row_check(index_function, index) == 1)
			{
				grid->Rows->Add();

				// fill all cells with data
				for (iCol = 0; iCol <= number_collums; iCol++)
				{
					cell_text = Global_get_data_switch(index_function, iCol, index);

					String^ textas = wstring_to_system_string(cell_text);

					// Insert items into the list.
					grid->Rows[grid_cell]->Cells[iCol]->Value = textas;
				}
				grid_cell++;
			}
			set_progress_value(index);
		}
	}
	Hide_progress();
	texts = str.Info.put_to_grid.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	GlobalForm::forma->tabControl1->SelectedIndex = index_function;

	Global_put_width_list(index_function,number_collums, collumn_with);

	GlobalForm::forma->Update();
	
	GlobalForm::forma->Global_Change_filter_position(index_function);
}


//colors list view
void Global_color_data_listview(int index_function, int &valid_entries, const int &number_collums, vector <color_change_array_str> &color_array, int color_entries)
{
	wstring texts;
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);

	wstring funcion_text = Global_function_txt(index_function, lang);

	int iCol;
	int rows_check;
	rows_check = min(valid_entries, color_entries);

	Show_progress(str.Progress.grid_color.s[lang], rows_check);
	texts = str.Info.color_grid.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	info_write(texts);

	if (rows_check > 0)
	{
		for (int index = 0; index <= rows_check; index++)
		{
			if (color_array[index].changed == false)
				continue;

			// color cell
			for (iCol = 0; iCol <= number_collums; iCol++)
			{		
				if (color_array[index].column_changed[iCol] == true)
					grid->Rows[index]->Cells[iCol]->Style->BackColor= grid->Rows[index]->Cells[iCol]->Style->BackColor.Yellow;
			}

			set_progress_value(index);
		}
	}
	Hide_progress();
	texts = str.Info.color_grid.s[lang];
	texts.append(info_separator);
	texts.append(funcion_text);
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	GlobalForm::forma->tabControl1->SelectedIndex = index_function;

	GlobalForm::forma->Update();
}

//get data from gridview to memory based on function index
void Global_get_data_listview(int index_function, int &valid_entries, const int &number_collums, vector <int> &collumn_with, bool data_for_save)
{
	wstring texts;
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	wstring funcion_text = Global_function_txt(index_function,lang);

	

	// if there is data get it
	if (grid->RowCount > 0)
	{
		valid_entries = grid->RowCount - 1;
		Global_resize_data(index_function, valid_entries + 1);

		Show_progress(str.Progress.grid_take.s[lang], valid_entries);
		texts = str.Info.extract_from_grid.s[lang];
		texts.append(info_separator);
		texts.append(funcion_text);
		info_write(texts);

		wstring cell_text = L"";

		int iCol;

		for (int index = 0; index <= valid_entries; index++)
		{

			// fill all cells with data
			for (iCol = 0; iCol <= number_collums; iCol++)
			{
				cell_text = Global_get_cell_value(index, iCol, grid);
		//		cell_text = system_string_to_wstring(grid->Rows[index]->Cells[iCol]->FormattedValue->ToString());
				Global_put_data_switch(index_function, iCol, index, cell_text);
			}
			set_progress_value(index);
		}
		Hide_progress();
		texts = str.Info.extract_from_grid.s[lang];
		texts.append(info_separator);
		texts.append(funcion_text);
		texts.append(error_separator);
		texts.append(str.General.done_txt.s[lang]);
		info_write(texts);

		if (unstable_release == 1 && valid_entries>1 && data_for_save == false)
		{
			Global_choose_save(index_function,true, L" ");
		}
		Global_get_width_list(index_function, number_collums, collumn_with);
	}
	else
	{
		Global_delete_all_data(index_function);
	}
}


int Global_paste(wstring function_text, System::Windows::Forms::DataGridView^ grid)
{
	wstring texts;
	System::Windows::Forms::IDataObject^ dataInclipboard = System::Windows::Forms::Clipboard::GetDataObject();

	String^ stringInclipboard = (System::String ^)dataInclipboard->GetData(DataFormats::UnicodeText);
	if (stringInclipboard == nullptr)
	{
		// no row data
		texts = str.Error.clickboard_no_data.s[lang];
		err_write_show(texts);
		return 1;
	}

	int sel_row_max = grid->SelectedCells[0]->RowIndex;
	int sel_col_max = grid->SelectedCells[0]->ColumnIndex;
	int sel_row_min = sel_row_max;
	int sel_col_min = sel_col_max;

	int a = 0;
	int b = 0;
	//get selected min and max cells
	for (int i = 0; i <grid->SelectedCells->Count; i++)
	{
		a = grid->SelectedCells[i]->RowIndex;
		b = grid->SelectedCells[i]->ColumnIndex;

		if (a > sel_row_max)
		{
			sel_row_max = a;
		}
		else if (a < sel_row_min)
		{
			sel_row_min = a;
		}

		if (b > sel_col_max)
		{
			sel_col_max = b;
		}
		else if (b < sel_col_min)
		{
			sel_col_min = b;
		}
	}


	int max_row = grid->RowCount-1;
	int max_collumn = grid->ColumnCount-1;

	cli::array <wchar_t>^ separators = {'\n' };
	cli::array <wchar_t>^ columnsplitter = { '\t' };
	cli::array <String^>^ rowsInclipboard = stringInclipboard->Split(separators);

	int rows_in_board = rowsInclipboard->Length;
	if (rows_in_board < 1)
	{
		// no row data
		texts = str.Error.clickboard_no_data.s[lang];
		err_write_show(texts);
		return 1;
	}

	cli::array <String^>^ cellsInrow = rowsInclipboard[0]->Split(columnsplitter);
	int col_in_board = cellsInrow->Length;
	if (col_in_board < 1)
	{
		// no collumn data
		texts = str.Error.clickboard_no_data.s[lang];
		err_write_show(texts);
		return 1;
	}
	int size_rows = 0;
	int size_cols = 0;
	
	wstring text;

	text = function_text;
	text.append(error_separator);
	text.append(L"Clipboard:Rows ");
	text.append(to_wstring(rows_in_board));
	text.append(L" Cols ");
	text.append(to_wstring(col_in_board));
	text.append(L" Sel: [");
	text.append(to_wstring(sel_row_min));
	text.append(L";");
	text.append(to_wstring(sel_col_min));
	text.append(L"] - [");
	text.append(to_wstring(sel_row_max));
	text.append(L";");
	text.append(to_wstring(sel_col_max));
	text.append(L"]");
	
	if (parameters.paste_sel_match > 0)
	{
		size_rows = sel_row_max - sel_row_min+1;
		size_cols = sel_col_max - sel_col_min +1;

		if ((size_rows != rows_in_board) || (size_cols != col_in_board))
		{
			// diferent size selected
			texts = str.Error.clickboard_no_match.s[lang];
			texts.append(info_separator);
			texts.append(text);
			err_write_show(texts);
			return 1;
		}

	}
	else
	{
		size_rows = max_row - sel_row_min + 1;
		size_cols = max_collumn - sel_col_min + 1;

		if ((size_rows < rows_in_board) || (size_cols < col_in_board))
		{
			// to much data to paste, select other
			texts = str.Error.clickboard_overrange.s[lang];
			texts.append(info_separator);
			texts.append(text);
			err_write_show(texts);
			return 1;
		}
	}

	// write info how much data is pasted
	texts = str.Info.paste_data.s[lang];
	texts.append(error_separator);
	texts.append(text);
	info_write(texts);
	   
	int j = 0;
	// paste this one data to all selected cells, is one row selected
	if (col_in_board == 1 && rows_in_board == 1 )
	{
		size_rows = sel_row_max - sel_row_min + 1;

		Show_progress(str.Progress.paste.s[lang], size_rows);
		rows_in_board = size_rows;
		for (int i = 0; i<rows_in_board; i++)
		{
			grid->Rows[sel_row_min + i]->Cells[sel_col_min]->Value = cellsInrow[0];
			set_progress_value(i);
		}
	}
	else
	{
		Show_progress(str.Progress.paste.s[lang], rows_in_board);
		for (int i = 0; i<rows_in_board; i++)
		{
			cellsInrow = rowsInclipboard[i]->Split(columnsplitter);
			for (j = 0; j < cellsInrow->Length - 1; j++)
			{
				grid->Rows[sel_row_min + i]->Cells[sel_col_min + j]->Value = cellsInrow[j];
			}
			cellsInrow = cellsInrow[j]->Split('\r');
			grid->Rows[sel_row_min + i]->Cells[sel_col_min + j]->Value = cellsInrow[0];
			set_progress_value(i);
		}
	}
	

	Hide_progress();

	return 0;
}

//check if cell data is valit and then return it as wstring
std::wstring Global_get_cell_value(int row, int col, System::Windows::Forms::DataGridView^ grid)
{
	if (grid->Rows[row]->Cells[col]->Value != nullptr)
	{
		return  system_string_to_wstring(grid->Rows[row]->Cells[col]->Value->ToString());
	}
	return L"";
}

//get module type index
int Global_Module_index(std::wstring module_name)
{
	int result = module_name.find(L"DI");
	if (result >= 0)
	{
		return DI_index;
	}

	result = module_name.find(L"DO");
	if (result >= 0)
	{
		return DO_index;
	}

	result = module_name.find(L"AI");
	if (result >= 0)
	{
		return AI_index;
	}

	result = module_name.find(L"AO");
	if (result >= 0)
	{
		return AO_index;
	}

	return -1;
}

//return module type from index
std::wstring Global_Module_type(int  module_index)
{
	switch (module_index)
	{
	case AI_index:	
		return L"AI";
		break;
	case AO_index: 
		return L"AO";
		break;
	case DI_index: 
		return L"DI";
		break;
	case DO_index:
		return L"DO";
		break;

	}
	return L"";
}

void Global_Filter_drop_down(int index_function,int filter_column, vector <wstring> &unique_texts)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	int column_count = grid->ColumnCount;
	int valid_entries = grid->RowCount - 1;

	vector <wstring> filter_texts = { L"" };
//	vector <wstring> unique_texts = { L"" };
	filter_texts.resize(valid_entries);
//	unique_texts.resize(valid_entries);

	wstring text_cell = L"";

	if (valid_entries > 1)
	{
		column_count = min(column_count, Filter_Count - 1);			
		for (int j = 0; j < valid_entries; j++)
		{	
			if (grid->Rows[j]->Cells[filter_column]->Visible == true)
				filter_texts[j] = Global_get_cell_value(j, filter_column, grid);
		}

		// sort and find uniques then transfer further
		std::sort(filter_texts.begin(), filter_texts.end());
		unique_copy(filter_texts.begin(), filter_texts.end(), back_inserter(unique_texts));

		// check if first data is empty, then delete it
		if (unique_texts[0].empty() == 1)
		{
			unique_texts.erase(unique_texts.begin());
		}
	}
	unique_texts.push_back(L"*NULL*");
}

void Global_Filter_apply(int index_function, filter_str filter)
{

	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	int column_count = grid->ColumnCount;
	int valid_entries = grid->RowCount-1;		

	vector <bool> hiden_rows = { false };
	hiden_rows.resize(valid_entries);
	wstring filter_text = L"";
	wstring text_cell = L"";
	int result = 0;
	bool search_blank = false;

	if (valid_entries > 1)
	{
		column_count = min(column_count, Filter_Count-1);
		for (int i = 0; i < column_count; i++)
		{
			filter_text = filter.Filter_text[i];
			if (filter_text.empty() == false && filter_text.compare(L"") != 0)
			{
				search_blank = filter_text.compare(L"*NULL*") == 0;
				if (search_blank == false)
				{
					for (int j = 0; j < valid_entries; j++)
					{
						if (hiden_rows[j] == false)
						{
							text_cell = Global_get_cell_value(j, i, grid);
							result = text_cell.find(filter_text);
							hiden_rows[j] = result < 0;
						}
					}
				}
				else
				{
					for (int j = 0; j < valid_entries; j++)
					{
						if (hiden_rows[j] == false)
						{
							text_cell = Global_get_cell_value(j, i, grid);
							hiden_rows[j] = (text_cell.empty() == false && text_cell.compare(L"") != 0);
						}
					}
				}
			}
		}

		for (int j = 0; j < valid_entries; j++)
		{
			grid->Rows[j]->Visible = hiden_rows[j] == false;
		}
	}
}

void Global_Filter_text_changed(wstring text, int column, int index_function)
{

	switch (index_function)
	{
	case Design_grid_index:
		design_filter.Filter_text[column] = text;
		Global_Filter_apply(index_function, design_filter);
		break;
	case Signals_grid_index:
		signal_filter.Filter_text[column] = text;
		Global_Filter_apply(index_function, signal_filter);
		break;
	case Objects_grid_index:
		object_filter.Filter_text[column] = text;
		Global_Filter_apply(index_function, object_filter);
		break;
	}
	
}

int Global_trend_data_check(int valid_entries)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(Trend_data_grid_index);
	if (grid->RowCount < Max_Trend_data)
	{
		for (int index = grid->RowCount; index <= Max_Trend_data; index++)
		{
			grid->Rows->Add();
		}
		return 1;
	}
	if (Trend_data.valid_entries < 1)
	{
		Trend_data.valid_entries = valid_entries + 1;

		if (valid_entries > 0)
		{
			for (int index = 0; index <= valid_entries; index++)
			{
				grid->Rows->Add();
			}
		}
		return 2;
	}
	return 0;
}


int Plot_data_to_file(int index_function, int col_from, int col_to)
{
	wstring texts;
	int iCol;
	string file_name;

	file_name = "_plot.txt";
	System::Windows::Forms::DataGridView^ grid;
	grid = Global_function_grid(index_function);

	int number_rows = grid->RowCount;
	int number_collums = grid->ColumnCount;

	if (number_rows < 1 && (col_to < col_from || col_to>number_collums))
		return 0;

	//create file with UTF-8 encoding
	std::wofstream file_out(file_name, std::ios::binary);
	std::locale utf16_locale(file_out.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::generate_header>);
	file_out.imbue(utf16_locale);

	texts = str.Info.dump_declare.s[lang];
	texts.append(info_separator);
	texts.append(Global_get_CPU_name(parameters.CPU));
	info_write(texts);

	Show_progress(str.Progress.dump_data.s[lang], number_rows);

	wstring cell_text_write, cell_text;
	for (int index = 0; index < number_rows; index++)
	{
		cell_text_write = L"";
		cell_text = Global_get_cell_value(index, col_from, grid);
		if (cell_text != L"")
		{
			// fill all cells with data
			for (iCol = col_from; iCol <= col_to; iCol++)
			{
				cell_text = Global_get_cell_value(index, iCol, grid);
				cell_text_write.append(cell_text);
				cell_text_write.append(separator);
			}
			// write all row data to file
			cell_text_write.append(L"\r\n");
			file_out << cell_text_write;
		}
		set_progress_value(index);
	}

	Hide_progress();
	texts = str.Info.dump_declare.s[lang];
	texts.append(info_separator);
	texts.append(Global_get_CPU_name(parameters.CPU));
	texts.append(error_separator);
	texts.append(str.General.done_txt.s[lang]);
	info_write(texts);

	file_out.close();
	return 0;

}

int Global_show_trend_data()
{
	wstring texts;

	create_shared_memmory(L"IO-automationas_out", 255);
	texts = str.Info.show_trend.s[lang];
	info_write(texts);

	int result = system("Trend_plot.exe");
	if (result != 0)
	{
		texts = str.Error.show_trend.s[lang];
		err_write_show(texts);
	}

	clear_shared_memmory();

	return result;
}

