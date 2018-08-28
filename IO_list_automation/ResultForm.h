#pragma once

namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ResultForm
	/// </summary>
	public ref class ResultForm : public System::Windows::Forms::Form
	{
	public:
		ResultForm(void)
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
		~ResultForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	public: System::Windows::Forms::DataGridView^  Grid_AI;
	private:


	private: System::Windows::Forms::TabPage^  tabPage2;

	private:


	private: System::Windows::Forms::TabPage^  tabPage3;

	private:


	private: System::Windows::Forms::TabPage^  tabPage4;

	private:


	private: System::Windows::Forms::TabPage^  tabPage5;

	private:


	private: System::Windows::Forms::TabPage^  tabPage6;

	private:


	private: System::Windows::Forms::TabPage^  tabPage7;
	public: System::Windows::Forms::DataGridView^  Grid_HC;
	private:
	public: System::Windows::Forms::DataGridView^  Grid_VLV;
	public: System::Windows::Forms::DataGridView^  Grid_MOT;
	public: System::Windows::Forms::DataGridView^  Grid_PID;
	public: System::Windows::Forms::DataGridView^  Grid_FC;
	public: System::Windows::Forms::DataGridView^  Grid_SCADA;

	private:



	protected:

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->Grid_AI = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->Grid_HC = (gcnew System::Windows::Forms::DataGridView());
			this->Grid_VLV = (gcnew System::Windows::Forms::DataGridView());
			this->Grid_MOT = (gcnew System::Windows::Forms::DataGridView());
			this->Grid_PID = (gcnew System::Windows::Forms::DataGridView());
			this->Grid_FC = (gcnew System::Windows::Forms::DataGridView());
			this->Grid_SCADA = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_AI))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_HC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_VLV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_MOT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_PID))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_FC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_SCADA))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(919, 498);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Grid_AI);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(911, 472);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"AI";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// Grid_AI
			// 
			this->Grid_AI->AllowUserToAddRows = false;
			this->Grid_AI->AllowUserToDeleteRows = false;
			this->Grid_AI->AllowUserToResizeColumns = false;
			this->Grid_AI->AllowUserToResizeRows = false;
			this->Grid_AI->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_AI->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_AI->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_AI->ColumnHeadersVisible = false;
			this->Grid_AI->Location = System::Drawing::Point(0, 0);
			this->Grid_AI->Name = L"Grid_AI";
			this->Grid_AI->ReadOnly = true;
			this->Grid_AI->Size = System::Drawing::Size(915, 479);
			this->Grid_AI->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->Grid_HC);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(911, 472);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"HC";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->Grid_VLV);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(911, 472);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"VLV";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->Grid_MOT);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(911, 472);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"MOT";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->Grid_PID);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(911, 472);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"PID";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->Grid_FC);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(911, 472);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"FC";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->Grid_SCADA);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(911, 472);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"SCADA";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// Grid_HC
			// 
			this->Grid_HC->AllowUserToAddRows = false;
			this->Grid_HC->AllowUserToDeleteRows = false;
			this->Grid_HC->AllowUserToResizeColumns = false;
			this->Grid_HC->AllowUserToResizeRows = false;
			this->Grid_HC->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_HC->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_HC->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_HC->ColumnHeadersVisible = false;
			this->Grid_HC->Location = System::Drawing::Point(-2, -3);
			this->Grid_HC->Name = L"Grid_HC";
			this->Grid_HC->ReadOnly = true;
			this->Grid_HC->Size = System::Drawing::Size(915, 479);
			this->Grid_HC->TabIndex = 1;
			// 
			// Grid_VLV
			// 
			this->Grid_VLV->AllowUserToAddRows = false;
			this->Grid_VLV->AllowUserToDeleteRows = false;
			this->Grid_VLV->AllowUserToResizeColumns = false;
			this->Grid_VLV->AllowUserToResizeRows = false;
			this->Grid_VLV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_VLV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_VLV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_VLV->ColumnHeadersVisible = false;
			this->Grid_VLV->Location = System::Drawing::Point(-2, -3);
			this->Grid_VLV->Name = L"Grid_VLV";
			this->Grid_VLV->ReadOnly = true;
			this->Grid_VLV->Size = System::Drawing::Size(915, 479);
			this->Grid_VLV->TabIndex = 1;
			// 
			// Grid_MOT
			// 
			this->Grid_MOT->AllowUserToAddRows = false;
			this->Grid_MOT->AllowUserToDeleteRows = false;
			this->Grid_MOT->AllowUserToResizeColumns = false;
			this->Grid_MOT->AllowUserToResizeRows = false;
			this->Grid_MOT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_MOT->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_MOT->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_MOT->ColumnHeadersVisible = false;
			this->Grid_MOT->Location = System::Drawing::Point(-2, -3);
			this->Grid_MOT->Name = L"Grid_MOT";
			this->Grid_MOT->ReadOnly = true;
			this->Grid_MOT->Size = System::Drawing::Size(915, 479);
			this->Grid_MOT->TabIndex = 1;
			// 
			// Grid_PID
			// 
			this->Grid_PID->AllowUserToAddRows = false;
			this->Grid_PID->AllowUserToDeleteRows = false;
			this->Grid_PID->AllowUserToResizeColumns = false;
			this->Grid_PID->AllowUserToResizeRows = false;
			this->Grid_PID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_PID->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_PID->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_PID->ColumnHeadersVisible = false;
			this->Grid_PID->Location = System::Drawing::Point(-2, -3);
			this->Grid_PID->Name = L"Grid_PID";
			this->Grid_PID->ReadOnly = true;
			this->Grid_PID->Size = System::Drawing::Size(915, 479);
			this->Grid_PID->TabIndex = 1;
			// 
			// Grid_FC
			// 
			this->Grid_FC->AllowUserToAddRows = false;
			this->Grid_FC->AllowUserToDeleteRows = false;
			this->Grid_FC->AllowUserToResizeColumns = false;
			this->Grid_FC->AllowUserToResizeRows = false;
			this->Grid_FC->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_FC->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_FC->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_FC->ColumnHeadersVisible = false;
			this->Grid_FC->Location = System::Drawing::Point(-2, -3);
			this->Grid_FC->Name = L"Grid_FC";
			this->Grid_FC->ReadOnly = true;
			this->Grid_FC->Size = System::Drawing::Size(915, 479);
			this->Grid_FC->TabIndex = 1;
			// 
			// Grid_SCADA
			// 
			this->Grid_SCADA->AllowUserToAddRows = false;
			this->Grid_SCADA->AllowUserToDeleteRows = false;
			this->Grid_SCADA->AllowUserToResizeColumns = false;
			this->Grid_SCADA->AllowUserToResizeRows = false;
			this->Grid_SCADA->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Grid_SCADA->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid_SCADA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_SCADA->ColumnHeadersVisible = false;
			this->Grid_SCADA->Location = System::Drawing::Point(-2, -3);
			this->Grid_SCADA->Name = L"Grid_SCADA";
			this->Grid_SCADA->ReadOnly = true;
			this->Grid_SCADA->Size = System::Drawing::Size(915, 479);
			this->Grid_SCADA->TabIndex = 1;
			// 
			// ResultForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(921, 497);
			this->Controls->Add(this->tabControl1);
			this->Name = L"ResultForm";
			this->Text = L"ResultForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_AI))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_HC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_VLV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_MOT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_PID))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_FC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid_SCADA))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
