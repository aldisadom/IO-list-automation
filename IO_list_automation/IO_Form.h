#pragma once
#include "config.h"
#include "Global_Functions.h"
#include "IO_declare.h"

namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for IO_Form
	/// </summary>
	public ref class IO_Form : public System::Windows::Forms::Form
	{
	public:
		IO_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IO_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	public: System::Windows::Forms::DataGridView^  Grid_Module;
	public: System::Windows::Forms::TabControl^  tabControl1;
	private:

	public:




	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	public: System::Windows::Forms::DataGridView^  Grid_IO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column0;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;

	public:







	public:





	public:





	public:




	private:


	private:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Grid_Module = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Grid_IO = (gcnew System::Windows::Forms::DataGridView());
			this->Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_Module))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_IO))->BeginInit();
			this->SuspendLayout();
			// 
			// Grid_Module
			// 
			this->Grid_Module->AllowUserToAddRows = false;
			this->Grid_Module->AllowUserToDeleteRows = false;
			this->Grid_Module->AllowUserToResizeColumns = false;
			this->Grid_Module->AllowUserToResizeRows = false;
			this->Grid_Module->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_Module->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_Module->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_Module->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column0,
					this->Column1, this->Column2, this->Column5, this->Column3, this->Column4, this->Column6, this->Column7
			});
			this->Grid_Module->Location = System::Drawing::Point(0, 0);
			this->Grid_Module->Name = L"Grid_Module";
			this->Grid_Module->Size = System::Drawing::Size(993, 441);
			this->Grid_Module->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(1, 34);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(997, 460);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Grid_Module);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(989, 434);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Modules";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->Grid_IO);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(989, 434);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"IO";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Grid_IO
			// 
			this->Grid_IO->AllowUserToAddRows = false;
			this->Grid_IO->AllowUserToDeleteRows = false;
			this->Grid_IO->AllowUserToResizeColumns = false;
			this->Grid_IO->AllowUserToResizeRows = false;
			this->Grid_IO->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_IO->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_IO->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_IO->ColumnHeadersVisible = false;
			this->Grid_IO->Location = System::Drawing::Point(-2, -3);
			this->Grid_IO->Name = L"Grid_IO";
			this->Grid_IO->ReadOnly = true;
			this->Grid_IO->Size = System::Drawing::Size(993, 441);
			this->Grid_IO->TabIndex = 1;
			// 
			// Column0
			// 
			this->Column0->HeaderText = L"CPU";
			this->Column0->Name = L"Column0";
			this->Column0->Width = 54;
			// 
			// Column1
			// 
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle1;
			this->Column1->HeaderText = L"Rack example";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column1->Width = 81;
			// 
			// Column2
			// 
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle2;
			this->Column2->HeaderText = L"Module example";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column2->Width = 81;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"";
			this->Column5->MinimumWidth = 20;
			this->Column5->Name = L"Column5";
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column5->Width = 20;
			// 
			// Column3
			// 
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->DefaultCellStyle = dataGridViewCellStyle3;
			this->Column3->HeaderText = L"Rack";
			this->Column3->Name = L"Column3";
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column3->Width = 39;
			// 
			// Column4
			// 
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle4;
			this->Column4->HeaderText = L"Module";
			this->Column4->Name = L"Column4";
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column4->Width = 48;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Type";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 56;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"input count";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 78;
			// 
			// IO_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(999, 490);
			this->Controls->Add(this->tabControl1);
			this->KeyPreview = true;
			this->Name = L"IO_Form";
			this->Text = L"IO_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_Module))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_IO))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void KeyDown_event(Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{

			if ((e->KeyCode == Keys::Delete) || (e->KeyCode == Keys::Back))
			{
				int index_function = this->tabControl1->SelectedIndex;
				if (index_function == 0)
				{
					System::Windows::Forms::DataGridView^ grid = this->Grid_Module;
					if (grid->SelectedCells->Count > 1)
					{
						for (int i = 0; i < (grid->SelectedCells->Count); i++)
						{
							grid->SelectedCells[i]->Value = L"";
						}
					}
				}
			}
			else if ((e->Modifiers == Keys::Control) && (e->KeyCode == Keys::V))
			{
				int index_function = this->tabControl1->SelectedIndex;
				if (index_function == 0)
				{
					System::Windows::Forms::DataGridView^ grid = this->Grid_Module;
					if (grid->SelectedCells->Count > 0)
					{
						Global_paste("IO_modules", this->Grid_Module);
					}
					this->Update();
				}
			}
		}

		public: void IO_form_init()
		{
			this->KeyDown += gcnew KeyEventHandler(this, &IO_Form::KeyDown_event);
			this->Grid_Module->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &IO_Form::Module_cell_edit);

			this->Grid_IO->ColumnCount = 10;
		}

	private: System::Void Module_cell_edit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int col = e->ColumnIndex;
		if (col == 5)
		{
			int row = e->RowIndex;

			wstring module_name = Global_get_cell_value(row, col, this->Grid_Module);
			wstring check_module_name = L"";

			int index_module = 0;

			for (int i = 0; i <= signals.valid_entries; i++)
			{
				IO_generate_module(signals.data[i].Cabinet, signals.data[i].Module_name, check_module_name);

				if (module_name.compare(check_module_name) == 0)
				{
					this->Grid_Module->Rows[row]->Cells[col + 1]->Value = wstring_to_system_string(signals.data[i].Module_type);
					break;
				}
			}
		}
		else if (col == 6)
		{
			int row = e->RowIndex;

			wstring module_name = Global_get_cell_value(row, col, this->Grid_Module);

			int index_module = Global_Module_index(module_name);

			switch (index_module)
			{
			case DI_index:
				this->Grid_Module->Rows[row]->Cells[col + 1]->Value = default_DI_size;
				break;
			case DO_index:
				this->Grid_Module->Rows[row]->Cells[col + 1]->Value = default_DO_size;
				break;
			case AI_index:
				this->Grid_Module->Rows[row]->Cells[col + 1]->Value = default_AI_size;
				break;
			case AO_index:
				this->Grid_Module->Rows[row]->Cells[col + 1]->Value = default_AO_size;
				break;
			}	
		}
	}

};
}
