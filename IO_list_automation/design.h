#pragma once
#ifndef _DESIGN_H_
#define _DESIGN_H_

void Project_resize_data(int size);
void Project_delete_row(int row);


int Project_read_data();
void Project_data_extract_useful_data();

int Project_put_data_listview();
void Project_get_data_listview(bool not_hidden);
void Project_update_data_listview(int row);
void Project_delete_list();
int Project_save_data(bool not_hidden);
int Project_Load_data();

#endif

