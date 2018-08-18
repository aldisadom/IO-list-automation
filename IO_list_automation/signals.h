#pragma once
#ifndef _SIGNALS_H_
#define _SIGNALS_H_

void dummy_function();
int Signals_get_data_design();

void Signals_resize_data(int size);
void Project_delete_row(int row);
int Signals_invalid_row_check(int row);
KKS_str Signals_KKS_trim(wstring KKS);
int Signals_all_KKS_trim();
int Signals_learn_data();


void Signals_put_data_listview();
void Signals_get_data_listview(bool visible);
void Signals_delete_list();


int Signals_save_data(bool visible, std::string file_name);
int Signals_Load_data();

#endif