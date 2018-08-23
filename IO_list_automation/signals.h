#pragma once
#ifndef _SIGNALS_H_
#define _SIGNALS_H_

wstring Signals_get_data_switch(int iCol, int index);
int Signals_get_data_design();

void Signals_resize_data(int size);
void Project_delete_row(int row);
int Signals_valid_row_check(int row);
KKS_str Signals_KKS_trim(wstring KKS);
int Signals_all_KKS_trim();
int Signals_learn_data();
int Signals_find_function();


void Signals_put_data_listview();
void Signals_get_data_listview();


int Signals_save_data(bool auto_save, std::string file_name_global);
int Signals_Load_data(std::string file_name_global);

#endif