#pragma once
#ifndef _SIGNALS_H_
#define _SIGNALS_H_



// get data from memory to wstring
std::wstring Signals_get_data_switch(int iCol, int index);
// put data from wstring to memory
void Signals_put_data_switch(int iCol, int index, wstring cell_text);


//check if there is data in any variable
int Signals_valid_row_check(int row);

//get data from project to signals
int Signals_get_data_design();


//KKS triming algorithm removes back ant front parts, and splits into two parts
KKS_str Signals_KKS_trim(wstring KKS_text);
//trims all KKS data in signals
int Signals_all_KKS_trim();


//reads learning data for object and function recognition
int Signals_learn_data();
//finds functions in signal data
int Signals_find_function();

int Signals_multi_cpu();

#endif