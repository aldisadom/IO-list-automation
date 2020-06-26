#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_

#include "config.h"


// get data from memory to wstring
std::wstring Project_get_data_switch(int iCol, int index);
// put data from wstring to memory
void Project_put_data_switch(int iCol, int index, project_str &project_data, std::wstring cell_text);


//check if there is data in any variable
int Project_valid_row_check(int row);


//read data from design file
int Project_read_data(bool put_data, char* test_mode, project_str &project_data);


// compares current data with new data
int Project_compare_data(char* test_mode);
#endif

