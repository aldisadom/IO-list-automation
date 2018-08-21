#pragma once

#include "config.h"
#include "signals.h"


namespace IOlistautomation {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for KKS_edit
	/// </summary>
	public ref class KKS_edit : public System::Windows::Forms::Form
	{
	public:
		int return_value=0;

		KKS_edit(void)
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
		~KKS_edit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  KKS_in_label;
	private: System::Windows::Forms::Label^  KKS2_label;
	private: System::Windows::Forms::Label^  KKS1_label;
	private: System::Windows::Forms::Label^  KKS_out_label;
	private: System::Windows::Forms::TextBox^  KKS_delete_box1;



	protected:

	protected:





	public:
		
	private: System::Windows::Forms::TextBox^  KKS_delete_box2;
	private: System::Windows::Forms::Button^  OK_button;

	private: System::Windows::Forms::Button^  Cancel_button;


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
			this->label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->KKS_in_label = (gcnew System::Windows::Forms::Label());
			this->KKS2_label = (gcnew System::Windows::Forms::Label());
			this->KKS1_label = (gcnew System::Windows::Forms::Label());
			this->KKS_out_label = (gcnew System::Windows::Forms::Label());
			this->KKS_delete_box1 = (gcnew System::Windows::Forms::TextBox());
			this->KKS_delete_box2 = (gcnew System::Windows::Forms::TextBox());
			this->OK_button = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label
			// 
			this->label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(127, 3);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(86, 18);
			this->label->TabIndex = 0;
			this->label->Text = L"KKS_input";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(63, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"KKS1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(217, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"KKS2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KKS_in_label
			// 
			this->KKS_in_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->KKS_in_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KKS_in_label->Location = System::Drawing::Point(12, 19);
			this->KKS_in_label->Name = L"KKS_in_label";
			this->KKS_in_label->Size = System::Drawing::Size(309, 21);
			this->KKS_in_label->TabIndex = 3;
			this->KKS_in_label->Text = L"KKS_in";
			this->KKS_in_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KKS2_label
			// 
			this->KKS2_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->KKS2_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KKS2_label->Location = System::Drawing::Point(163, 64);
			this->KKS2_label->Name = L"KKS2_label";
			this->KKS2_label->Size = System::Drawing::Size(158, 23);
			this->KKS2_label->TabIndex = 5;
			this->KKS2_label->Text = L"KKS2";
			this->KKS2_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KKS1_label
			// 
			this->KKS1_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->KKS1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KKS1_label->Location = System::Drawing::Point(12, 64);
			this->KKS1_label->Name = L"KKS1_label";
			this->KKS1_label->Size = System::Drawing::Size(152, 23);
			this->KKS1_label->TabIndex = 4;
			this->KKS1_label->Text = L"KKS1";
			this->KKS1_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KKS_out_label
			// 
			this->KKS_out_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->KKS_out_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KKS_out_label->Location = System::Drawing::Point(12, 84);
			this->KKS_out_label->Name = L"KKS_out_label";
			this->KKS_out_label->Size = System::Drawing::Size(309, 21);
			this->KKS_out_label->TabIndex = 6;
			this->KKS_out_label->Text = L"KKS_out";
			this->KKS_out_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KKS_delete_box1
			// 
			this->KKS_delete_box1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->KKS_delete_box1->Location = System::Drawing::Point(15, 108);
			this->KKS_delete_box1->Name = L"KKS_delete_box1";
			this->KKS_delete_box1->Size = System::Drawing::Size(55, 20);
			this->KKS_delete_box1->TabIndex = 7;
			this->KKS_delete_box1->Text = L"0";
			this->KKS_delete_box1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->KKS_delete_box1->TextChanged += gcnew System::EventHandler(this, &KKS_edit::KKS_delete_box1_TextChanged);
			// 
			// KKS_delete_box2
			// 
			this->KKS_delete_box2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->KKS_delete_box2->Location = System::Drawing::Point(266, 108);
			this->KKS_delete_box2->Name = L"KKS_delete_box2";
			this->KKS_delete_box2->Size = System::Drawing::Size(55, 20);
			this->KKS_delete_box2->TabIndex = 8;
			this->KKS_delete_box2->Text = L"0";
			this->KKS_delete_box2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->KKS_delete_box2->TextChanged += gcnew System::EventHandler(this, &KKS_edit::KKS_delete_box2_TextChanged);
			// 
			// OK_button
			// 
			this->OK_button->Location = System::Drawing::Point(89, 108);
			this->OK_button->Name = L"OK_button";
			this->OK_button->Size = System::Drawing::Size(55, 23);
			this->OK_button->TabIndex = 9;
			this->OK_button->Text = L"OK";
			this->OK_button->UseVisualStyleBackColor = true;
			this->OK_button->Click += gcnew System::EventHandler(this, &KKS_edit::OK_button_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->Location = System::Drawing::Point(196, 108);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(55, 23);
			this->Cancel_button->TabIndex = 10;
			this->Cancel_button->Text = L"Cancel";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &KKS_edit::Cancel_button_Click);
			// 
			// KKS_edit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 133);
			this->ControlBox = false;
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->OK_button);
			this->Controls->Add(this->KKS_delete_box2);
			this->Controls->Add(this->KKS_delete_box1);
			this->Controls->Add(this->KKS_out_label);
			this->Controls->Add(this->KKS2_label);
			this->Controls->Add(this->KKS1_label);
			this->Controls->Add(this->KKS_in_label);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"KKS_edit";
			this->Text = L"KKS_edit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void KKS_init(void)
		{
			if (parameters.KKS_del1 == 0)
			{
				this->KKS_delete_box1->Text = L"";
			}
			else
			{
				this->KKS_delete_box1->Text = string_to_system_string(to_string(parameters.KKS_del1));
			}
			if (parameters.KKS_del2 == 0)
			{
				this->KKS_delete_box1->Text = L"";
			}
			else
			{
				this->KKS_delete_box2->Text = string_to_system_string(to_string(parameters.KKS_del2));
			}
			test.KKS = Signals_KKS_trim(test.test_KKS);

			this->KKS1_label->Text = wstring_to_system_string(test.KKS.Part1);
			this->KKS2_label->Text = wstring_to_system_string(test.KKS.Part2);
			this->KKS_out_label->Text = wstring_to_system_string(test.KKS.Full);
			this->KKS_in_label->Text = wstring_to_system_string(test.test_KKS);
		}

		private: System::Void KKS_delete_box1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ texts = safe_cast<TextBox^>(sender)->Text;
			string text_value = system_string_to_string(texts);

			int number = atoi(text_value.c_str());
			text_value = to_string(number);
			if (number == 0)
			{
				this->KKS_delete_box1->Text = L"";
			}
			else
			{
				this->KKS_delete_box1->Text = string_to_system_string(text_value);
			}
			parameters.KKS_del1 = number;
			
			test.KKS= Signals_KKS_trim(test.test_KKS);			

			this->KKS1_label->Text = wstring_to_system_string(test.KKS.Part1);
			this->KKS2_label->Text = wstring_to_system_string(test.KKS.Part2);
			this->KKS_out_label->Text = wstring_to_system_string(test.KKS.Full);
			this->KKS_in_label->Text = wstring_to_system_string(test.test_KKS);
		}

		private: System::Void KKS_delete_box2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ texts = safe_cast<TextBox^>(sender)->Text;
			string text_value = system_string_to_string(texts);

			int number = atoi(text_value.c_str());
			text_value = to_string(number);
			if (number == 0)
			{
				this->KKS_delete_box2->Text = L"";
			}
			else
			{
				this->KKS_delete_box2->Text = string_to_system_string(text_value);
			}
			parameters.KKS_del2 = number;

			test.KKS = Signals_KKS_trim(test.test_KKS);

			this->KKS1_label->Text = wstring_to_system_string(test.KKS.Part1);
			this->KKS2_label->Text = wstring_to_system_string(test.KKS.Part2);
			this->KKS_out_label->Text = wstring_to_system_string(test.KKS.Full);
			this->KKS_in_label->Text = wstring_to_system_string(test.test_KKS);
		}

		private: System::Void OK_button_Click(System::Object^  sender, System::EventArgs^  e) {
			return_value = 0;
			this->Close();
		}

		private: System::Void Cancel_button_Click(System::Object^  sender, System::EventArgs^  e) {
			return_value = 1;
			this->Close();
		}
};
}
