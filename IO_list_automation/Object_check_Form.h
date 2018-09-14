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
	/// Summary for Object_check_Form
	/// </summary>
	public ref class Object_check_Form : public System::Windows::Forms::Form
	{
	public:
		Object_check_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		int return_value=0;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Object_check_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  IO_button;
	protected:
	private: System::Windows::Forms::Button^  Object_button;
	private: System::Windows::Forms::TextBox^  Text_io;
	private: System::Windows::Forms::TextBox^  Text_object;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  Text_KKS;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  Exit_button;

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
			this->IO_button = (gcnew System::Windows::Forms::Button());
			this->Object_button = (gcnew System::Windows::Forms::Button());
			this->Text_io = (gcnew System::Windows::Forms::TextBox());
			this->Text_object = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Text_KKS = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// IO_button
			// 
			this->IO_button->Location = System::Drawing::Point(202, 90);
			this->IO_button->Name = L"IO_button";
			this->IO_button->Size = System::Drawing::Size(126, 23);
			this->IO_button->TabIndex = 0;
			this->IO_button->Text = L"Copy From IO";
			this->IO_button->UseVisualStyleBackColor = true;
			this->IO_button->Click += gcnew System::EventHandler(this, &Object_check_Form::IO_button_Click);
			// 
			// Object_button
			// 
			this->Object_button->Location = System::Drawing::Point(202, 185);
			this->Object_button->Name = L"Object_button";
			this->Object_button->Size = System::Drawing::Size(126, 23);
			this->Object_button->TabIndex = 1;
			this->Object_button->Text = L"Copy From Objects";
			this->Object_button->UseVisualStyleBackColor = true;
			this->Object_button->Click += gcnew System::EventHandler(this, &Object_check_Form::Object_button_Click);
			// 
			// Text_io
			// 
			this->Text_io->Location = System::Drawing::Point(12, 64);
			this->Text_io->Name = L"Text_io";
			this->Text_io->Size = System::Drawing::Size(497, 20);
			this->Text_io->TabIndex = 2;
			// 
			// Text_object
			// 
			this->Text_object->Location = System::Drawing::Point(12, 159);
			this->Text_object->Name = L"Text_object";
			this->Text_object->Size = System::Drawing::Size(497, 20);
			this->Text_object->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(239, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Text IO";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(225, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Text Objects";
			// 
			// Text_KKS
			// 
			this->Text_KKS->Location = System::Drawing::Point(80, 24);
			this->Text_KKS->Name = L"Text_KKS";
			this->Text_KKS->Size = System::Drawing::Size(116, 20);
			this->Text_KKS->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(121, 5);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"KKS";
			// 
			// Exit_button
			// 
			this->Exit_button->Cursor = System::Windows::Forms::Cursors::Default;
			this->Exit_button->Location = System::Drawing::Point(438, 5);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(71, 23);
			this->Exit_button->TabIndex = 8;
			this->Exit_button->Text = L"Exit";
			this->Exit_button->UseVisualStyleBackColor = true;
			this->Exit_button->Click += gcnew System::EventHandler(this, &Object_check_Form::Exit_button_Click);
			// 
			// Object_check_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 214);
			this->ControlBox = false;
			this->Controls->Add(this->Exit_button);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Text_KKS);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Text_object);
			this->Controls->Add(this->Text_io);
			this->Controls->Add(this->Object_button);
			this->Controls->Add(this->IO_button);
			this->Name = L"Object_check_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Object_check_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void Object_check_init(void)
	{
		this->Text_object->Text = wstring_to_system_string(test.Object_text);
		this->Text_io->Text = wstring_to_system_string(test.IO_text);
		this->Text_KKS->Text = wstring_to_system_string(test.KKS.Full);
	}

	private: System::Void IO_button_Click(System::Object^  sender, System::EventArgs^  e) {

		test.KKS.Full = system_string_to_wstring(this->Text_KKS->Text);
		test.text_to_copy = system_string_to_wstring (this->Text_io->Text);
		this->Close();
	}
	private: System::Void Object_button_Click(System::Object^  sender, System::EventArgs^  e) {

		test.KKS.Full = system_string_to_wstring(this->Text_KKS->Text);
		test.text_to_copy = system_string_to_wstring(this->Text_object->Text);
		this->Close();
	}


	private: System::Void Exit_button_Click(System::Object^  sender, System::EventArgs^  e) {
		return_value = 1;
		this->Close();
	}


};
}
