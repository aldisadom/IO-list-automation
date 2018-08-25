#pragma once
#ifndef _SIGNALS_H_
#define _SIGNALS_H_




std::wstring Signals_get_data_switch(int iCol, int index);
int Signals_get_data_design();
void Signals_put_data_switch(int iCol, int index, wstring cell_text);


int Signals_valid_row_check(int row);
KKS_str Signals_KKS_trim(wstring KKS);
int Signals_all_KKS_trim();
int Signals_learn_data();
int Signals_find_function();

#endif