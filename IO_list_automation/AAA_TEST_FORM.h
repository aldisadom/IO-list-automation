#pragma once

namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AAA_TEST_FORM
	/// </summary>
	public ref class AAA_TEST_FORM : public System::Windows::Forms::Form
	{
	public:
		AAA_TEST_FORM(void)
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
		~AAA_TEST_FORM()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:













	private: System::Windows::Forms::TextBox^  PID_Test_start_par;
	private: System::Windows::Forms::TextBox^  PID_Test_area_par;








	private: System::Windows::Forms::TextBox^  FC_Test_start_par;
	private: System::Windows::Forms::TextBox^  FC_Test_area_par;








	private: System::Windows::Forms::TextBox^  AI_Test_start_par;
	private: System::Windows::Forms::TextBox^  AI_Test_area_par;








	private: System::Windows::Forms::TextBox^  MOT_Test_start_par;
	private: System::Windows::Forms::TextBox^  Mot_Test_area_par;








	private: System::Windows::Forms::TextBox^  HC_Test_start_par;
	private: System::Windows::Forms::TextBox^  HC_Test_area_par;
















	private: System::Windows::Forms::TextBox^  VLV_Test_start_par;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  VLV_Test_area_par;
	private: System::Windows::Forms::Label^  label;

	private: System::Windows::Forms::TextBox^  PID_Test_stop_par;

	private: System::Windows::Forms::TextBox^  FC_Test_stop_par;

private: System::Windows::Forms::TextBox^  AI_Test_stop_par;

private: System::Windows::Forms::TextBox^  MOT_Test_stop_par;

private: System::Windows::Forms::TextBox^  HC_Test_stop_par;

	private: System::Windows::Forms::TextBox^  VLV_Test_stop_par;
	private: System::Windows::Forms::Label^  label1;






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
			this->PID_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->Mot_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// PID_Test_start_par
			// 
			this->PID_Test_start_par->Location = System::Drawing::Point(99, 174);
			this->PID_Test_start_par->Name = L"PID_Test_start_par";
			this->PID_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_par->TabIndex = 158;
			this->PID_Test_start_par->Text = L"0";
			this->PID_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_par
			// 
			this->PID_Test_area_par->Location = System::Drawing::Point(58, 174);
			this->PID_Test_area_par->Name = L"PID_Test_area_par";
			this->PID_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_par->TabIndex = 157;
			this->PID_Test_area_par->Text = L"0";
			this->PID_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_par
			// 
			this->FC_Test_start_par->Location = System::Drawing::Point(99, 148);
			this->FC_Test_start_par->Name = L"FC_Test_start_par";
			this->FC_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_par->TabIndex = 148;
			this->FC_Test_start_par->Text = L"0";
			this->FC_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_par
			// 
			this->FC_Test_area_par->Location = System::Drawing::Point(58, 148);
			this->FC_Test_area_par->Name = L"FC_Test_area_par";
			this->FC_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_par->TabIndex = 147;
			this->FC_Test_area_par->Text = L"0";
			this->FC_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_par
			// 
			this->AI_Test_start_par->Location = System::Drawing::Point(99, 122);
			this->AI_Test_start_par->Name = L"AI_Test_start_par";
			this->AI_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_par->TabIndex = 138;
			this->AI_Test_start_par->Text = L"0";
			this->AI_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_par
			// 
			this->AI_Test_area_par->Location = System::Drawing::Point(58, 122);
			this->AI_Test_area_par->Name = L"AI_Test_area_par";
			this->AI_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_par->TabIndex = 137;
			this->AI_Test_area_par->Text = L"0";
			this->AI_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_par
			// 
			this->MOT_Test_start_par->Location = System::Drawing::Point(99, 96);
			this->MOT_Test_start_par->Name = L"MOT_Test_start_par";
			this->MOT_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_par->TabIndex = 128;
			this->MOT_Test_start_par->Text = L"0";
			this->MOT_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Mot_Test_area_par
			// 
			this->Mot_Test_area_par->Location = System::Drawing::Point(58, 96);
			this->Mot_Test_area_par->Name = L"Mot_Test_area_par";
			this->Mot_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->Mot_Test_area_par->TabIndex = 127;
			this->Mot_Test_area_par->Text = L"0";
			this->Mot_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_par
			// 
			this->HC_Test_start_par->Location = System::Drawing::Point(99, 70);
			this->HC_Test_start_par->Name = L"HC_Test_start_par";
			this->HC_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_par->TabIndex = 118;
			this->HC_Test_start_par->Text = L"0";
			this->HC_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_par
			// 
			this->HC_Test_area_par->Location = System::Drawing::Point(58, 70);
			this->HC_Test_area_par->Name = L"HC_Test_area_par";
			this->HC_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_par->TabIndex = 117;
			this->HC_Test_area_par->Text = L"0";
			this->HC_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_par
			// 
			this->VLV_Test_start_par->Location = System::Drawing::Point(99, 44);
			this->VLV_Test_start_par->Name = L"VLV_Test_start_par";
			this->VLV_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_par->TabIndex = 96;
			this->VLV_Test_start_par->Text = L"0";
			this->VLV_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(111, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 15);
			this->label4->TabIndex = 95;
			this->label4->Text = L"start";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_par
			// 
			this->VLV_Test_area_par->Location = System::Drawing::Point(58, 44);
			this->VLV_Test_area_par->Name = L"VLV_Test_area_par";
			this->VLV_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_par->TabIndex = 93;
			this->VLV_Test_area_par->Text = L"0";
			this->VLV_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(58, 27);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(32, 15);
			this->label->TabIndex = 92;
			this->label->Text = L"Area";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_stop_par
			// 
			this->PID_Test_stop_par->Location = System::Drawing::Point(147, 174);
			this->PID_Test_stop_par->Name = L"PID_Test_stop_par";
			this->PID_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_par->TabIndex = 180;
			this->PID_Test_stop_par->Text = L"0";
			this->PID_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_par
			// 
			this->FC_Test_stop_par->Location = System::Drawing::Point(147, 148);
			this->FC_Test_stop_par->Name = L"FC_Test_stop_par";
			this->FC_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_par->TabIndex = 179;
			this->FC_Test_stop_par->Text = L"0";
			this->FC_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_par
			// 
			this->AI_Test_stop_par->Location = System::Drawing::Point(147, 122);
			this->AI_Test_stop_par->Name = L"AI_Test_stop_par";
			this->AI_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_par->TabIndex = 178;
			this->AI_Test_stop_par->Text = L"0";
			this->AI_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_par
			// 
			this->MOT_Test_stop_par->Location = System::Drawing::Point(147, 96);
			this->MOT_Test_stop_par->Name = L"MOT_Test_stop_par";
			this->MOT_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_par->TabIndex = 177;
			this->MOT_Test_stop_par->Text = L"0";
			this->MOT_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_par
			// 
			this->HC_Test_stop_par->Location = System::Drawing::Point(147, 70);
			this->HC_Test_stop_par->Name = L"HC_Test_stop_par";
			this->HC_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_par->TabIndex = 176;
			this->HC_Test_stop_par->Text = L"0";
			this->HC_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_par
			// 
			this->VLV_Test_stop_par->Location = System::Drawing::Point(147, 44);
			this->VLV_Test_stop_par->Name = L"VLV_Test_stop_par";
			this->VLV_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_par->TabIndex = 175;
			this->VLV_Test_stop_par->Text = L"0";
			this->VLV_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(159, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 15);
			this->label1->TabIndex = 174;
			this->label1->Text = L"stop";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AAA_TEST_FORM
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1040, 410);
			this->Controls->Add(this->PID_Test_stop_par);
			this->Controls->Add(this->FC_Test_stop_par);
			this->Controls->Add(this->AI_Test_stop_par);
			this->Controls->Add(this->MOT_Test_stop_par);
			this->Controls->Add(this->HC_Test_stop_par);
			this->Controls->Add(this->VLV_Test_stop_par);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PID_Test_start_par);
			this->Controls->Add(this->PID_Test_area_par);
			this->Controls->Add(this->FC_Test_start_par);
			this->Controls->Add(this->FC_Test_area_par);
			this->Controls->Add(this->AI_Test_start_par);
			this->Controls->Add(this->AI_Test_area_par);
			this->Controls->Add(this->MOT_Test_start_par);
			this->Controls->Add(this->Mot_Test_area_par);
			this->Controls->Add(this->HC_Test_start_par);
			this->Controls->Add(this->HC_Test_area_par);
			this->Controls->Add(this->VLV_Test_start_par);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->VLV_Test_area_par);
			this->Controls->Add(this->label);
			this->Name = L"AAA_TEST_FORM";
			this->Text = L"AAA_TEST_FORM";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
