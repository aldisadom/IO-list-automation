#pragma once
#ifndef _TREND_DATA_H_
#define _TREND_DATA_H_

extern struct Trend_str Trend_data;

// get data from memory to wstring
std::wstring Trend_data_get_data_switch(int iCol, int index);
// put data from wstring to memory
void Trend_data_put_data_switch(int iCol, int index, wstring cell_text);


//check if there is data in any variable
int Trend_data_valid_row_check(int row);

void Global_Polynom_calc();

#endif