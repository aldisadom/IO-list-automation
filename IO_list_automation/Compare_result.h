#pragma once
#include "config.h"

namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Confirm_wnd
	/// </summary>
	public ref class Compare_result : public System::Windows::Forms::Form
	{
	public:
		Compare_result(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		int return_value = Result_Undefined;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Compare_result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Button_yes_all;
	protected:
	private: System::Windows::Forms::Button^  Button_yes;
	private: System::Windows::Forms::Button^  Button_no;
	private: System::Windows::Forms::Button^  Button_no_all;
	private: System::Windows::Forms::TextBox^  Text_design;
	private: System::Windows::Forms::TextBox^  Text_test;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->Button_yes_all = (gcnew System::Windows::Forms::Button());
			this->Button_yes = (gcnew System::Windows::Forms::Button());
			this->Button_no = (gcnew System::Windows::Forms::Button());
			this->Button_no_all = (gcnew System::Windows::Forms::Button());
			this->Text_design = (gcnew System::Windows::Forms::TextBox());
			this->Text_test = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Button_yes_all
			// 
			this->Button_yes_all->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_yes_all->Location = System::Drawing::Point(66, 199);
			this->Button_yes_all->Name = L"Button_yes_all";
			this->Button_yes_all->Size = System::Drawing::Size(75, 23);
			this->Button_yes_all->TabIndex = 0;
			this->Button_yes_all->Text = L"Yes All";
			this->Button_yes_all->UseVisualStyleBackColor = true;
			this->Button_yes_all->Click += gcnew System::EventHandler(this, &Compare_result::Button_yes_all_Click);
			// 
			// Button_yes
			// 
			this->Button_yes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_yes->Location = System::Drawing::Point(147, 199);
			this->Button_yes->Name = L"Button_yes";
			this->Button_yes->Size = System::Drawing::Size(75, 23);
			this->Button_yes->TabIndex = 1;
			this->Button_yes->Text = L"Yes";
			this->Button_yes->UseVisualStyleBackColor = true;
			this->Button_yes->Click += gcnew System::EventHandler(this, &Compare_result::Button_yes_Click);
			// 
			// Button_no
			// 
			this->Button_no->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_no->Location = System::Drawing::Point(364, 199);
			this->Button_no->Name = L"Button_no";
			this->Button_no->Size = System::Drawing::Size(75, 23);
			this->Button_no->TabIndex = 2;
			this->Button_no->Text = L"NO";
			this->Button_no->UseVisualStyleBackColor = true;
			this->Button_no->Click += gcnew System::EventHandler(this, &Compare_result::Button_no_Click);
			// 
			// Button_no_all
			// 
			this->Button_no_all->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_no_all->Location = System::Drawing::Point(445, 199);
			this->Button_no_all->Name = L"Button_no_all";
			this->Button_no_all->Size = System::Drawing::Size(75, 23);
			this->Button_no_all->TabIndex = 3;
			this->Button_no_all->Text = L"No All";
			this->Button_no_all->UseVisualStyleBackColor = true;
			this->Button_no_all->Click += gcnew System::EventHandler(this, &Compare_result::Button_no_all_Click);
			// 
			// Text_design
			// 
			this->Text_design->Location = System::Drawing::Point(314, 32);
			this->Text_design->Multiline = true;
			this->Text_design->Name = L"Text_design";
			this->Text_design->Size = System::Drawing::Size(257, 161);
			this->Text_design->TabIndex = 5;
			// 
			// Text_test
			// 
			this->Text_test->Location = System::Drawing::Point(12, 32);
			this->Text_test->Multiline = true;
			this->Text_test->Name = L"Text_test";
			this->Text_test->Size = System::Drawing::Size(257, 161);
			this->Text_test->TabIndex = 4;
			this->Text_test->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(275, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"-->";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(44, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(166, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"From compared document";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(411, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Current data";
			// 
			// Compare_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 234);
			this->ControlBox = false;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Text_design);
			this->Controls->Add(this->Text_test);
			this->Controls->Add(this->Button_no_all);
			this->Controls->Add(this->Button_no);
			this->Controls->Add(this->Button_yes);
			this->Controls->Add(this->Button_yes_all);
			this->Name = L"Compare_result";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Confirm_wnd";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: void Confirm_check_init(wstring test_text, wstring text_design)
		{
			this->Text_design->Text = wstring_to_system_string(text_design);
			this->Text_test->Text = wstring_to_system_string(test_text);
		}

	private: System::Void Button_yes_all_Click(System::Object^  sender, System::EventArgs^  e) {
		return_value = Result_Yes_all;
		this->Close();
	}
	private: System::Void Button_yes_Click(System::Object^  sender, System::EventArgs^  e) {
		return_value = Result_Yes;
		this->Close();
	}
private: System::Void Button_no_Click(System::Object^  sender, System::EventArgs^  e) {
	return_value = Result_No;
	this->Close();
}
private: System::Void Button_no_all_Click(System::Object^  sender, System::EventArgs^  e) {
	return_value = Result_No_all;
	this->Close();
}


};
}
