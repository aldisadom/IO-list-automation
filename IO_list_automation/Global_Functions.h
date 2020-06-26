#pragma once
#ifndef _GLOBAL_FUNCTIONS_H_
#define _GLOBAL_FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>

#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>

#include <algorithm>

#include <vector>
#include <CommCtrl.h>
#include "Strings.h"

struct color_change_array_str
{
	bool changed = false;
	bool column_changed[50] = { false };
};

// get grid based on function index
System::Windows::Forms::DataGridView^ Global_function_grid(int index_function);

wstring String_remove_trailing_zero(wstring text);

// get function text based on function index
const char* Global_function_txt(int index_function, int language);
// get selected cpu name
const char* Global_get_CPU_name(int index_cpu);

//delete memory row based on function index
void Global_delete_data_row(int index_function, int row);
//delete all memory data based on function index
void Global_delete_all_data(int index_function);

//save data based on function index
void Global_choose_save(int index_function, bool auto_save, std::string file_name_global);
//load data based on function index
void Global_choose_Load(int index_function, std::string file_name_global);




// --------Global function----------------------------------------------------
//paste data to grid
int Global_paste(const char* function_text, System::Windows::Forms::DataGridView^ grid);

// saving data to file
int Global_save(int index_function, bool auto_save, std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);
//loading data from file	
int Global_load(int index_function, std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);


//store collumn width from grid view based on function index
void Global_get_width_list(int index_function, const int &number_collums, vector <int> &collumn_with);

//color list view
void Global_color_data_listview(int index_function, int &valid_entries, const int &number_collums, vector <color_change_array_str> &color_array, int color_entries);
//put data from memory to gridview based on function index
void Global_put_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);
//get data from gridview to memory based on function index
void Global_get_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with, bool data_for_save);

//check if cell data is valit and then return it as wstring
std::wstring Global_get_cell_value(int row, int col, System::Windows::Forms::DataGridView^ grid);

//get module type index
int Global_Module_index(std::wstring module_name);
//return module type from index
std::wstring Global_Module_type(int  module_index);


void Global_Filter_text_changed(wstring text, int column, int index_function);
void Global_Filter_drop_down(int index_function, int filter_column, vector <wstring> &unique_texts);
#endif


