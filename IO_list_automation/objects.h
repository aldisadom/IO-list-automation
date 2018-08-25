#pragma once
#ifndef _OBJECTS_H_
#define _OBJECTS_H_



void Objects_put_data_switch(int iCol, int index, wstring cell_text);
std::wstring Objects_get_data_switch(int iCol, int index);
int Objects_find_uniques();
int Objects_find_objects();
int Objects_find_operatyv();
int Objects_transfer_to_signals();




int Objects_valid_row_check(int row);


#endif