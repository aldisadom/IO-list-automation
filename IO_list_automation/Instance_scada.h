#pragma once
#ifndef _INSTANCE_SCADA_H_
#define _INSTANCE_SCADA_H_

// add one line to instance grid
void Instance_scada_grid_add_line(int &grid_row_index, System::Windows::Forms::DataGridView^ grid);
// add data to instance grid
void Instance_scada_grid_write_cell(int &grid_row_index, int collumn, wstring cell_text, System::Windows::Forms::DataGridView^ grid);


int Instance_scada_gen(bool test_mode, wstring gen_test_mode);

#endif