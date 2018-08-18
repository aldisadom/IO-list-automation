#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_

void Project_resize_data(int size);
void Project_delete_row(int row);


int Project_read_data();
void Project_data_extract_useful_data();

void Project_put_data_listview();
void Project_get_data_listview(bool visible);
void Project_delete_list();
int Project_save_data(bool visible, std::string file_name);
int Project_Load_data();

#endif

