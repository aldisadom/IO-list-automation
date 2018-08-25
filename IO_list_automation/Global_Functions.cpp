#include "config.h"
#include "MainWindow.h"
#include "signals.h"
#include "design.h"
#include "objects.h"
#include "Global_Functions.h"

using namespace std;
using namespace IOlistautomation;


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




	default: return GlobalForm::forma->Design_grid;
		break;
	}
}


// get function text based on function index
const char* Global_function_txt(int index_function, int language)
{
	switch (index_function)
	{
	case Design_grid_index:	return  design_txt[language];
		break;
	case Signals_grid_index:return signals_txt[language];
		break;
	case Objects_grid_index:return  objects_txt[language];
		break;



	default:	return design_txt[language];
		break;
	}
}
// get confirm text based on function index
const wchar_t* Global_confirm_txt(int index_function, int language)
{
	switch (index_function)
	{
	case Design_grid_index:	return conf_design_overwrite[language];
		break;
	case Signals_grid_index:return conf_signal_overwrite[language];
		break;
	case Objects_grid_index:return conf_objects_overwrite[language];
		break;



	default:	return conf_design_overwrite[language];
		break;
	}
}
// get extension text based on function index
string Global_function_extension_txt(int index_function)
{
	switch (index_function)
	{
	case Design_grid_index:	return ".psave";
		break;
	case Signals_grid_index:return ".ssave";
		break;
	case Objects_grid_index:return ".osave";
		break;



	default:	return  ".psave";
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



	default:  return Project_get_data_switch(iCol, index);
		break;
	}

}
//// put data to cell based on function index
void Global_put_data_switch(int index_function,int iCol, int index, wstring cell_text)
{
	switch (index_function)
	{
	case Design_grid_index:	 Project_put_data_switch(iCol, index,cell_text);
		break;
	case Signals_grid_index: Signals_put_data_switch(iCol, index, cell_text);
		break;
	case Objects_grid_index: Objects_put_data_switch(iCol, index, cell_text);
		break;


	default:	 Project_put_data_switch(iCol, index, cell_text);
		break;
	}
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
		break;
	case Signals_grid_index: signals.data = {};
		break;
	case Objects_grid_index: objects.data = {};
		break;



	default:	 project.data = {};
		break;
	}
}


//save data based on function index
void Global_choose_save(int index_function, bool auto_save, std::string file_name_global)
{
	switch (index_function)
	{
	case Design_grid_index:	 Global_save(index_function, auto_save, file_name_global, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		break;
	case Signals_grid_index: Global_save(index_function, auto_save, file_name_global, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
		break;
	case Objects_grid_index: Global_save(index_function, auto_save, file_name_global, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
		break;



	default:	 Global_save(index_function, auto_save, file_name_global, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		break;
	}
}
//load data based on function index
void Global_choose_Load(int index_function, std::string file_name_global)
{
	switch (index_function)
	{
	case Design_grid_index:	 Global_load(index_function, file_name_global, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		break;
	case Signals_grid_index: Global_load(index_function, file_name_global, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
		break;
	case Objects_grid_index: Global_load(index_function, file_name_global, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
		break;



	default:	 Global_load(index_function, file_name_global, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		break;
	}
}




// --------Global function----------------------------------------------------

// saving data to file
int Global_save (int index_function, bool auto_save, std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with)
{
	const char* funcion_text = Global_function_txt(index_function, lang);
	string extension = Global_function_extension_txt(index_function);
	string filter = "Save document | *";

	// for knowing what function it is saved and its used for restoration
	string file_type = Global_function_txt(index_function, 1);


	filter.append(extension); //add extension to filter

	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = string_to_system_string(filter) +
		"|All Files|*.*";

	sfd->FileName = string_to_system_string(file_type);

	// first line is function text
	wstring cell_text = system_string_to_wstring(sfd->FileName);

	std::string file_name = "_autosave";
	file_name.append(extension);

	if (valid_entries <= 1) //if there is no data no need to save, check if there is atleast 2 entries because one line in grid is empty
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, funcion_text);
		err_write_show(err_txt);
		return 1;
	}

	FILE* outFile;
	int iCol;

	
	// when autosave=1 use _autosave.extension
	if (auto_save == 0) 
	{
		if (file_name_global.compare(" ") == 0) // when no global file name open save dialog
		{
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				file_name = system_string_to_string(sfd->FileName);
			}
			else
			{
				strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
				err_write(err_txt);
				return 1;
			}
		}
		else // when global file name, add extension 
		{
			file_name = file_name_global;
			file_name.append(extension);
		}
		Show_progress(prog_save[lang], valid_entries);
	}
	//create file with UTF-8 encoding
	fopen_s(&outFile, file_name.c_str(), "w+,ccs=UTF-8");

	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	info_write(info_txt);

	if (outFile == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_file_save[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, funcion_text);
		err_write_show(err_txt);
		return 1;
	}

	cell_text.append(L"\n");
	const wchar_t* x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);
	cell_text = L"";

	// second line is collums names
	for ( iCol = 0; iCol <= number_collums; iCol++)
	{
		cell_text.append(column_name[iCol]);
		cell_text.append(separator);
	}
	cell_text.append(L"\n");
	x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);
	cell_text = L"";

	// third line is collums width
	for (unsigned int iCol = 0; iCol < collumn_with.size(); iCol++)
	{
		cell_text.append(int_to_wstring(collumn_with[iCol],0));
		cell_text.append(separator);
	}

	cell_text.append(L"\n");
	x = cell_text.c_str();
	fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);

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
		cell_text_write.append(L"\n");
		x = cell_text_write.c_str();
		fwrite(x, wcslen(x) * sizeof(wchar_t), 1, outFile);

		set_progress_value(index);
	}
	fclose(outFile);

	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_save_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	return 0;
}
//loading data from file	
int Global_load(int index_function,  std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with)
{
	const char* funcion_text = Global_function_txt(index_function, lang);
	string extension = Global_function_extension_txt(index_function);
	string filter = "Load document | *";

	// for knowing what function it is saved and its used for restoration
	string file_type = Global_function_txt(index_function, 1);

	filter.append(extension); //add extension to filter

	OpenFileDialog^ importfile = gcnew OpenFileDialog();
	importfile->Filter = string_to_system_string(filter) +
		"|All Files|*.*";
	

	if (valid_entries > 1) //if there is data ask if ok to overwrite, check if there is atleast 2 entries because one line in grid is empty
	{
		if (show_confirm_window(Global_confirm_txt(index_function,lang)) == IDOK)
		{			
			strcpy_s(info_txt, sizeof info_txt, info_erase_data[lang]);
			strcat_s(info_txt, sizeof info_txt, info_separator);
			strcat_s(info_txt, sizeof info_txt, funcion_text);
			info_write(info_txt);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	Global_delete_all_data(index_function); // delete all data

	Show_progress(prog_load[lang], 500); //making guess that load data is 500 long

	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	info_write(info_txt);

	FILE* inFile;
	string file_name;

	if (file_name_global.compare(" ") == 0) // when no global file name open load dialog
	{
		if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			file_name = system_string_to_string(importfile->FileName);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
			return 1;
		}
	}
	else // when global file name, add extension 
	{
		file_name = file_name_global;
		file_name.append(extension);
	}

	//create file with UTF-8 encoding
	fopen_s(&inFile, file_name.c_str(), "r+,ccs=UTF-8");
	if (inFile == NULL)
	{
		strcpy_s(err_txt, sizeof err_txt, err_cant_open[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, funcion_text);
		err_write_show(err_txt);
		return 1;
	}

	wchar_t x[1024];
	wchar_t * cell_text;
	wchar_t *next_token1 = NULL;
	int iCol = 0;
	int index = 0;

	fgetws(x, sizeof x, inFile);



	string testas = funcion_text;
	std::wstring wsTmp(testas.begin(), testas.end());

	// check if first line matches function that is called
	if (wcsstr(x, wsTmp.c_str()) == NULL)
	{
		fclose(inFile);

		strcpy_s(err_txt, sizeof err_txt, err_wrong_file[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, funcion_text);
		err_write_show(err_txt);
		return 1;
	}
	fgetws(x, sizeof x, inFile);

	// needs editing, check column names if ok and get with of columns
	cell_text = wcstok_s(x, separator, &next_token1);
	if (cell_text == NULL)
	{
		fclose(inFile);

		strcpy_s(err_txt, sizeof err_txt, err_corrupted_file[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, funcion_text);
		err_write_show(err_txt);
		return 1;
	}

	// check collumns names if all doesnt match, corrupted
	while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
	{
		if (iCol > number_collums)
		{
			break;
		}
		if (wcsstr(column_name[iCol].c_str(),cell_text) == NULL)
		{
			fclose(inFile);

			strcpy_s(err_txt, sizeof err_txt, err_corrupted_file[lang]);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, funcion_text);
			err_write_show(err_txt);
			return 1;
		}
		iCol++;
		cell_text = wcstok_s(NULL, separator, &next_token1);
	}

	fgetws(x, sizeof x, inFile);

	// needs editing, check column names if ok and get with of columns
	cell_text = wcstok_s(x, separator, &next_token1);

	collumn_with.resize(number_collums+1);
	// check collumns names if all doesnt match, corrupted
	iCol = 0;
	while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
	{
		if (iCol > number_collums)
		{
			break;
		}
		collumn_with[iCol] = _wtoi(cell_text);
		iCol++;
		cell_text = wcstok_s(NULL, separator, &next_token1);
	}

	int a = 0;
	
	while (fgetws(x, sizeof x, inFile) != NULL)  // continue till end of file
	{
		//extend memory data at each line
		valid_entries = index;
		Global_resize_data(index_function,index + 1);
		iCol = 0;

		cell_text = wcstok_s(x, separator, &next_token1);
		while (cell_text != NULL && wcsstr(cell_text, L"\n") == NULL)
		{
			if (wcscmp(cell_text, L" ") != 0) // if there is thext between separators, put data to memory
			{
				Global_put_data_switch(index_function,iCol, index, cell_text);
			}
			iCol++;
			cell_text = wcstok_s(NULL, separator, &next_token1);
		}
		a++;
		index++;
		if (a > 500) //if overfills start progress all over from 0
		{
			a = a - 500;
		}
		set_progress_value(a);
	}
	fclose(inFile);

	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_load_data[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	// after load put data to gridview
	Global_put_data_listview(index_function, valid_entries, number_collums, column_name, collumn_with);

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
void Global_put_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);

	//before puting data clear list
	Global_delete_list(index_function, collumn_with);
	GlobalForm::forma->Update();

	const char* funcion_text = Global_function_txt(index_function,lang);

	int iCol;

	Show_progress(prog_grid_put[lang], valid_entries);

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	info_write(info_txt);


	// Add the columns.
	grid->ColumnCount = number_collums + 1;

	for (iCol = 0; iCol <= number_collums; iCol++)
	{
		// Load the names of the column headings from the string resources.
		grid->Columns[iCol]->Name = wstring_to_system_string(column_name[iCol]);
	}

	wstring cell_text = L"";

	int grid_cell = 0;
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
	Hide_progress();

	strcpy_s(info_txt, sizeof info_txt, info_put_to_grid[lang]);
	strcat_s(info_txt, sizeof info_txt, info_separator);
	strcat_s(info_txt, sizeof info_txt, funcion_text);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);

	GlobalForm::forma->tabControl1->SelectedIndex = index_function;

	Global_put_width_list(index_function,number_collums, collumn_with);

	GlobalForm::forma->Update();
}
//get data from gridview to memory based on function index
void Global_get_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with)
{
	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
	const char* funcion_text = Global_function_txt(index_function,lang);

	// if there is data get it
	if (grid->RowCount > 0)
	{
		valid_entries = grid->RowCount - 1;
		Global_resize_data(index_function, valid_entries + 1);

		Show_progress(prog_grid_take[lang], valid_entries);

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, funcion_text);
		info_write(info_txt);

		wstring cell_text = L"";

		int iCol;

		for (int index = 0; index <= valid_entries; index++)
		{

			// fill all cells with data
			for (iCol = 0; iCol <= number_collums; iCol++)
			{
				cell_text = system_string_to_wstring(grid->Rows[index]->Cells[iCol]->FormattedValue->ToString());
				Global_put_data_switch(index_function, iCol, index, cell_text);
			}
			set_progress_value(index);
		}
		Hide_progress();

		strcpy_s(info_txt, sizeof info_txt, info_extract_from_grid[lang]);
		strcat_s(info_txt, sizeof info_txt, info_separator);
		strcat_s(info_txt, sizeof info_txt, funcion_text);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
		info_write(info_txt);

		if (unstable_release == 1 && valid_entries>1)
		{
			Global_choose_save(index_function,true, " ");
		}
		Global_get_width_list(index_function, number_collums, collumn_with);
	}
	else
	{
		Global_delete_all_data(index_function);
	}
}
