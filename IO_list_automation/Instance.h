#pragma once
#ifndef _INSTANCE_H_
#define _INSTANCE_H_

// add one line to instance grid
void Instance_grid_add_line(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
// add data to instance grid
void Instance_grid_write_cell(int &grid_row_index, int collumn, wstring cell_text, System::Windows::Forms::DataGridView^ grid);


int Instance_gen(bool test_mode,int cpu_index);

#endif