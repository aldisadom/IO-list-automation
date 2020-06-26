#pragma once
#ifndef _OBJECTS_H_
#define _OBJECTS_H_


// get data from memory to wstring
std::wstring Objects_get_data_switch(int iCol, int index);
// put data from wstring to memory
void Objects_put_data_switch(int iCol, int index, wstring cell_text);


//check if there is data in any variable
int Objects_valid_row_check(int row);


//find unique objects in signals data
int Objects_find_uniques();
//find what kind of object it is
int Objects_find_objects();
//find operative marking
int Objects_find_operatyv();
//transfer objects data back to signals
int Objects_transfer_to_signals(bool test_mode);

#endif