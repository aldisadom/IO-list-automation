#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_


void Project_resize_data(int size);
void Project_delete_row(int row);

std::wstring Project_get_data_switch(int iCol, int index);

int Project_read_data();
void Project_data_extract_useful_data();

void Project_get_data_listview();

int Project_valid_row_check(int row);

int Project_save_data(bool auto_save, std::string file_name_global);
int Project_Load_data(std::string file_name_global);

#endif

