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



//resize memory data based on function index
void Global_resize_data(int index_function, int size);
//delete memory row based on function index
void Global_delete_data_row(int index_function, int row);


//save data based on function index
void Global_choose_save(int index_function, bool auto_save, std::string file_name_global);
//load data based on function index
void Global_choose_Load(int index_function, std::string file_name_global);




// --------Global function----------------------------------------------------

// saving data to file
int Global_save(int index_function, bool auto_save, std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);
//loading data from file	
int Global_load(int index_function, std::string file_name_global, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);


//store collumn width from grid view based on function index
void Global_get_width_list(int index_function, const int &number_collums, vector <int> &collumn_with);


//put data from memory to gridview based on function index
void Global_put_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);
//get data from gridview to memory based on function index
void Global_get_data_listview(int index_function, int &valid_entries, const int &number_collums, const vector <wstring> &column_name, vector <int> &collumn_with);

#endif
