#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_


std::wstring Project_get_data_switch(int iCol, int index);
void Project_put_data_switch(int iCol, int index, std::wstring cell_text);

int Project_valid_row_check(int row);



int Project_read_data();
void Project_data_extract_useful_data();


#endif

