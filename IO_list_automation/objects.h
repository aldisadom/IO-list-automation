#pragma once
#ifndef _OBJECTS_H_
#define _OBJECTS_H_

int Objects_find_uniques();
int Objects_find_objects();
int Objects_find_operatyv();
int Objects_transfer_to_signals();

void Object_resize_data(int size);
void Objects_put_data_listview();
void Objects_get_data_listview();
void Objects_delete_list();



int Objects_save_data(bool auto_save, std::string file_name_global);
int Objects_Load_data(std::string file_name_global);

#endif