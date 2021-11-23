#pragma once
#ifndef _INSTANCE_WINCC_H_
#define _INSTANCE_WINCC_H_

int Init_Wincc_vlv(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_Wincc_mot(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_Wincc_pid(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_Wincc_hc(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Init_Wincc_ai(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);


int Instance_Wincc_vlv(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Wincc_mot(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Wincc_pid(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Wincc_hc(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
int Instance_Wincc_ai(int index_object, int &grid_row_index, System::Windows::Forms::DataGridView^ grid);


#endif