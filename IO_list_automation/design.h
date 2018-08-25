#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_


// get data from memory to wstring
std::wstring Project_get_data_switch(int iCol, int index);
// put data from wstring to memory
void Project_put_data_switch(int iCol, int index, std::wstring cell_text);


//check if there is data in any variable
int Project_valid_row_check(int row);


//read data from design file
int Project_read_data();

#endif

