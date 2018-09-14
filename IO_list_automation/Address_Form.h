#pragma once

#include "declare.h"
#include "config.h"

namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Address_Form
	/// </summary>
	public ref class Address_Form : public System::Windows::Forms::Form
	{
	public:
		Address_Form(void)
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
		~Address_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  VLV_CPU_area_w1;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  label;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  VLV_CPU_start_w1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  VLV_CPU_start_w2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  VLV_CPU_area_w2;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  VLV_CPU_start_val;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  VLV_CPU_area_val;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  VLV_CPU_start_cmd;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  VLV_CPU_area_cmd;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  VLV_CPU_start_par;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  VLV_CPU_area_par;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  HC_CPU_start_par;

	private: System::Windows::Forms::TextBox^  HC_CPU_area_par;
	private: System::Windows::Forms::TextBox^  HC_CPU_start_val;



	private: System::Windows::Forms::TextBox^  HC_CPU_area_val;
	private: System::Windows::Forms::TextBox^  HC_CPU_start_cmd;


	private: System::Windows::Forms::TextBox^  HC_CPU_area_cmd;
	private: System::Windows::Forms::TextBox^  HC_CPU_start_w2;


	private: System::Windows::Forms::TextBox^  HC_CPU_area_w2;
	private: System::Windows::Forms::TextBox^  HC_CPU_start_w1;


	private: System::Windows::Forms::TextBox^  HC_CPU_area_w1;
	private: System::Windows::Forms::TextBox^  MOT_CPU_start_par;



	private: System::Windows::Forms::TextBox^  MOT_CPU_area_par;
	private: System::Windows::Forms::TextBox^  MOT_CPU_start_val;


	private: System::Windows::Forms::TextBox^  MOT_CPU_area_val;
	private: System::Windows::Forms::TextBox^  MOT_CPU_start_cmd;


	private: System::Windows::Forms::TextBox^  MOT_CPU_area_cmd;
	private: System::Windows::Forms::TextBox^  MOT_CPU_start_w2;


	private: System::Windows::Forms::TextBox^  MOT_CPU_area_w2;
	private: System::Windows::Forms::TextBox^  MOT_CPU_start_w1;
	private: System::Windows::Forms::TextBox^  MOT_CPU_area_w1;



private: System::Windows::Forms::TextBox^  AI_CPU_start_par;


	private: System::Windows::Forms::TextBox^  AI_CPU_area_par;
private: System::Windows::Forms::TextBox^  AI_CPU_start_val;


	private: System::Windows::Forms::TextBox^  AI_CPU_area_val;
private: System::Windows::Forms::TextBox^  AI_CPU_start_cmd;


	private: System::Windows::Forms::TextBox^  AI_CPU_area_cmd;
private: System::Windows::Forms::TextBox^  AI_CPU_start_w2;


	private: System::Windows::Forms::TextBox^  AI_CPU_area_w2;
private: System::Windows::Forms::TextBox^  AI_CPU_start_w1;


	private: System::Windows::Forms::TextBox^  AI_CPU_area_w1;
private: System::Windows::Forms::TextBox^  FC_CPU_start_par;


private: System::Windows::Forms::TextBox^  FC_CPU_area_par;
private: System::Windows::Forms::TextBox^  FC_CPU_start_val;


private: System::Windows::Forms::TextBox^  FC_CPU_area_val;
private: System::Windows::Forms::TextBox^  FC_CPU_start_cmd;



private: System::Windows::Forms::TextBox^  FC_CPU_area_cmd;
private: System::Windows::Forms::TextBox^  FC_CPU_start_w2;


private: System::Windows::Forms::TextBox^  FC_CPU_area_w2;
private: System::Windows::Forms::TextBox^  FC_CPU_start_w1;



private: System::Windows::Forms::TextBox^  FC_CPU_area_w1;
private: System::Windows::Forms::TextBox^  PID_CPU_start_par;


private: System::Windows::Forms::TextBox^  PID_CPU_area_par;
private: System::Windows::Forms::TextBox^  PID_CPU_start_val;


private: System::Windows::Forms::TextBox^  PID_CPU_area_val;
private: System::Windows::Forms::TextBox^  PID_CPU_start_cmd;


private: System::Windows::Forms::TextBox^  PID_CPU_area_cmd;
private: System::Windows::Forms::TextBox^  PID_CPU_start_w2;


private: System::Windows::Forms::TextBox^  PID_CPU_area_w2;
private: System::Windows::Forms::TextBox^  PID_CPU_start_w1;


private: System::Windows::Forms::TextBox^  PID_CPU_area_w1;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  Number_pid;

private: System::Windows::Forms::Label^  Number_fc;
private: System::Windows::Forms::Label^  Number_ai;



private: System::Windows::Forms::Label^  Number_mot;

private: System::Windows::Forms::Label^  Number_hc;

private: System::Windows::Forms::Label^  Number_vlv;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::TextBox^  PID_Test_stop_w1;
private: System::Windows::Forms::TextBox^  FC_Test_stop_w1;
private: System::Windows::Forms::TextBox^  AI_Test_stop_w1;
private: System::Windows::Forms::TextBox^  MOT_Test_stop_w1;
private: System::Windows::Forms::TextBox^  HC_Test_stop_w1;
private: System::Windows::Forms::TextBox^  VLV_Test_stop_w1;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  PID_Test_start_w1;
private: System::Windows::Forms::TextBox^  PID_Test_area_w1;
private: System::Windows::Forms::TextBox^  FC_Test_start_w1;
private: System::Windows::Forms::TextBox^  FC_Test_area_w1;
private: System::Windows::Forms::TextBox^  AI_Test_start_w1;
private: System::Windows::Forms::TextBox^  AI_Test_area_w1;
private: System::Windows::Forms::TextBox^  MOT_Test_start_w1;
private: System::Windows::Forms::TextBox^  MOT_Test_area_w1;

private: System::Windows::Forms::TextBox^  HC_Test_start_w1;
private: System::Windows::Forms::TextBox^  HC_Test_area_w1;
private: System::Windows::Forms::TextBox^  VLV_Test_start_w1;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::TextBox^  VLV_Test_area_w1;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::TextBox^  PID_Test_stop_w2;
private: System::Windows::Forms::TextBox^  FC_Test_stop_w2;
private: System::Windows::Forms::TextBox^  AI_Test_stop_w2;
private: System::Windows::Forms::TextBox^  MOT_Test_stop_w2;
private: System::Windows::Forms::TextBox^  HC_Test_stop_w2;
private: System::Windows::Forms::TextBox^  VLV_Test_stop_w2;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TextBox^  PID_Test_start_w2;
private: System::Windows::Forms::TextBox^  PID_Test_area_w2;
private: System::Windows::Forms::TextBox^  FC_Test_start_w2;
private: System::Windows::Forms::TextBox^  FC_Test_area_w2;
private: System::Windows::Forms::TextBox^  AI_Test_start_w2;
private: System::Windows::Forms::TextBox^  AI_Test_area_w2;
private: System::Windows::Forms::TextBox^  MOT_Test_start_w2;
private: System::Windows::Forms::TextBox^  MOT_Test_area_w2;

private: System::Windows::Forms::TextBox^  HC_Test_start_w2;
private: System::Windows::Forms::TextBox^  HC_Test_area_w2;
private: System::Windows::Forms::TextBox^  VLV_Test_start_w2;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  VLV_Test_area_w2;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  PID_Test_stop_cmd;
private: System::Windows::Forms::TextBox^  FC_Test_stop_cmd;
private: System::Windows::Forms::TextBox^  AI_Test_stop_cmd;
private: System::Windows::Forms::TextBox^  MOT_Test_stop_cmd;
private: System::Windows::Forms::TextBox^  HC_Test_stop_cmd;
private: System::Windows::Forms::TextBox^  VLV_Test_stop_cmd;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::TextBox^  PID_Test_start_cmd;
private: System::Windows::Forms::TextBox^  PID_Test_area_cmd;
private: System::Windows::Forms::TextBox^  FC_Test_start_cmd;
private: System::Windows::Forms::TextBox^  FC_Test_area_cmd;
private: System::Windows::Forms::TextBox^  AI_Test_start_cmd;
private: System::Windows::Forms::TextBox^  AI_Test_area_cmd;
private: System::Windows::Forms::TextBox^  MOT_Test_start_cmd;
private: System::Windows::Forms::TextBox^  MOT_Test_area_cmd;

private: System::Windows::Forms::TextBox^  HC_Test_start_cmd;
private: System::Windows::Forms::TextBox^  HC_Test_area_cmd;
private: System::Windows::Forms::TextBox^  VLV_Test_start_cmd;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  VLV_Test_area_cmd;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::TextBox^  PID_Test_stop_val;
private: System::Windows::Forms::TextBox^  FC_Test_stop_val;
private: System::Windows::Forms::TextBox^  AI_Test_stop_val;
private: System::Windows::Forms::TextBox^  MOT_Test_stop_val;
private: System::Windows::Forms::TextBox^  HC_Test_stop_val;
private: System::Windows::Forms::TextBox^  VLV_Test_stop_val;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  PID_Test_start_val;
private: System::Windows::Forms::TextBox^  PID_Test_area_val;
private: System::Windows::Forms::TextBox^  FC_Test_start_val;
private: System::Windows::Forms::TextBox^  FC_Test_area_val;
private: System::Windows::Forms::TextBox^  AI_Test_start_val;
private: System::Windows::Forms::TextBox^  AI_Test_area_val;
private: System::Windows::Forms::TextBox^  MOT_Test_start_val;
private: System::Windows::Forms::TextBox^  MOT_Test_area_val;

private: System::Windows::Forms::TextBox^  HC_Test_start_val;
private: System::Windows::Forms::TextBox^  HC_Test_area_val;
private: System::Windows::Forms::TextBox^  VLV_Test_start_val;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  VLV_Test_area_val;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::TextBox^  PID_Test_stop_par;
private: System::Windows::Forms::TextBox^  FC_Test_stop_par;
private: System::Windows::Forms::TextBox^  AI_Test_stop_par;
private: System::Windows::Forms::TextBox^  MOT_Test_stop_par;
private: System::Windows::Forms::TextBox^  HC_Test_stop_par;
private: System::Windows::Forms::TextBox^  VLV_Test_stop_par;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::TextBox^  PID_Test_start_par;
private: System::Windows::Forms::TextBox^  PID_Test_area_par;
private: System::Windows::Forms::TextBox^  FC_Test_start_par;
private: System::Windows::Forms::TextBox^  FC_Test_area_par;
private: System::Windows::Forms::TextBox^  AI_Test_start_par;
private: System::Windows::Forms::TextBox^  AI_Test_area_par;
private: System::Windows::Forms::TextBox^  MOT_Test_start_par;
private: System::Windows::Forms::TextBox^  MOT_Test_area_par;

private: System::Windows::Forms::TextBox^  HC_Test_start_par;
private: System::Windows::Forms::TextBox^  HC_Test_area_par;
private: System::Windows::Forms::TextBox^  VLV_Test_start_par;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  VLV_Test_area_par;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Button^  Check_button;
private: System::Windows::Forms::Button^  Done_button;
private: System::Windows::Forms::Button^  Cancel_button;


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
			this->VLV_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->VLV_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->HC_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->HC_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->AI_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->FC_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_start_par = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_area_par = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_start_val = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_area_val = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->PID_CPU_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->Number_pid = (gcnew System::Windows::Forms::Label());
			this->Number_fc = (gcnew System::Windows::Forms::Label());
			this->Number_ai = (gcnew System::Windows::Forms::Label());
			this->Number_mot = (gcnew System::Windows::Forms::Label());
			this->Number_hc = (gcnew System::Windows::Forms::Label());
			this->Number_vlv = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_w1 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_w2 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_w2 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_w2 = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_cmd = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_cmd = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_cmd = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_val = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_val = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_val = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_stop_par = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->PID_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->PID_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->FC_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->AI_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->MOT_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->HC_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->VLV_Test_start_par = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->VLV_Test_area_par = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->Check_button = (gcnew System::Windows::Forms::Button());
			this->Done_button = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// VLV_CPU_area_w1
			// 
			this->VLV_CPU_area_w1->Location = System::Drawing::Point(207, 41);
			this->VLV_CPU_area_w1->Name = L"VLV_CPU_area_w1";
			this->VLV_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->VLV_CPU_area_w1->TabIndex = 9;
			this->VLV_CPU_area_w1->Text = L"0";
			this->VLV_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(207, 24);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(32, 15);
			this->label->TabIndex = 8;
			this->label->Text = L"Area";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(201, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 195);
			this->label3->TabIndex = 12;
			this->label3->Text = L"W1";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// VLV_CPU_start_w1
			// 
			this->VLV_CPU_start_w1->BackColor = System::Drawing::SystemColors::Window;
			this->VLV_CPU_start_w1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->VLV_CPU_start_w1->Location = System::Drawing::Point(248, 41);
			this->VLV_CPU_start_w1->Name = L"VLV_CPU_start_w1";
			this->VLV_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->VLV_CPU_start_w1->TabIndex = 15;
			this->VLV_CPU_start_w1->Text = L"0";
			this->VLV_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(260, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 15);
			this->label4->TabIndex = 14;
			this->label4->Text = L"start";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_CPU_start_w2
			// 
			this->VLV_CPU_start_w2->Location = System::Drawing::Point(346, 41);
			this->VLV_CPU_start_w2->Name = L"VLV_CPU_start_w2";
			this->VLV_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->VLV_CPU_start_w2->TabIndex = 20;
			this->VLV_CPU_start_w2->Text = L"0";
			this->VLV_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(358, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 15);
			this->label5->TabIndex = 19;
			this->label5->Text = L"start";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(296, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 195);
			this->label6->TabIndex = 18;
			this->label6->Text = L"W2";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// VLV_CPU_area_w2
			// 
			this->VLV_CPU_area_w2->Location = System::Drawing::Point(305, 41);
			this->VLV_CPU_area_w2->Name = L"VLV_CPU_area_w2";
			this->VLV_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->VLV_CPU_area_w2->TabIndex = 17;
			this->VLV_CPU_area_w2->Text = L"0";
			this->VLV_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(305, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 15);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Area";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_CPU_start_val
			// 
			this->VLV_CPU_start_val->Location = System::Drawing::Point(542, 41);
			this->VLV_CPU_start_val->Name = L"VLV_CPU_start_val";
			this->VLV_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->VLV_CPU_start_val->TabIndex = 30;
			this->VLV_CPU_start_val->Text = L"0";
			this->VLV_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(554, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 15);
			this->label2->TabIndex = 29;
			this->label2->Text = L"start";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(492, 6);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 195);
			this->label8->TabIndex = 28;
			this->label8->Text = L"value";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// VLV_CPU_area_val
			// 
			this->VLV_CPU_area_val->Location = System::Drawing::Point(501, 41);
			this->VLV_CPU_area_val->Name = L"VLV_CPU_area_val";
			this->VLV_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->VLV_CPU_area_val->TabIndex = 27;
			this->VLV_CPU_area_val->Text = L"0";
			this->VLV_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(501, 24);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 15);
			this->label9->TabIndex = 26;
			this->label9->Text = L"Area";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_CPU_start_cmd
			// 
			this->VLV_CPU_start_cmd->Location = System::Drawing::Point(444, 41);
			this->VLV_CPU_start_cmd->Name = L"VLV_CPU_start_cmd";
			this->VLV_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->VLV_CPU_start_cmd->TabIndex = 25;
			this->VLV_CPU_start_cmd->Text = L"0";
			this->VLV_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(456, 25);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 15);
			this->label10->TabIndex = 24;
			this->label10->Text = L"start";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(394, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 195);
			this->label11->TabIndex = 23;
			this->label11->Text = L"cmd";
			this->label11->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// VLV_CPU_area_cmd
			// 
			this->VLV_CPU_area_cmd->Location = System::Drawing::Point(403, 41);
			this->VLV_CPU_area_cmd->Name = L"VLV_CPU_area_cmd";
			this->VLV_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->VLV_CPU_area_cmd->TabIndex = 22;
			this->VLV_CPU_area_cmd->Text = L"0";
			this->VLV_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(403, 24);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(32, 15);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Area";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(589, 6);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(101, 195);
			this->label13->TabIndex = 33;
			this->label13->Text = L"parameters";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// VLV_CPU_start_par
			// 
			this->VLV_CPU_start_par->Location = System::Drawing::Point(641, 41);
			this->VLV_CPU_start_par->Name = L"VLV_CPU_start_par";
			this->VLV_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->VLV_CPU_start_par->TabIndex = 35;
			this->VLV_CPU_start_par->Text = L"0";
			this->VLV_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(652, 25);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(30, 15);
			this->label14->TabIndex = 34;
			this->label14->Text = L"start";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_CPU_area_par
			// 
			this->VLV_CPU_area_par->Location = System::Drawing::Point(599, 41);
			this->VLV_CPU_area_par->Name = L"VLV_CPU_area_par";
			this->VLV_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->VLV_CPU_area_par->TabIndex = 32;
			this->VLV_CPU_area_par->Text = L"0";
			this->VLV_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(599, 24);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 15);
			this->label15->TabIndex = 31;
			this->label15->Text = L"Area";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HC_CPU_start_par
			// 
			this->HC_CPU_start_par->Location = System::Drawing::Point(641, 67);
			this->HC_CPU_start_par->Name = L"HC_CPU_start_par";
			this->HC_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->HC_CPU_start_par->TabIndex = 45;
			this->HC_CPU_start_par->Text = L"0";
			this->HC_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_area_par
			// 
			this->HC_CPU_area_par->Location = System::Drawing::Point(599, 67);
			this->HC_CPU_area_par->Name = L"HC_CPU_area_par";
			this->HC_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->HC_CPU_area_par->TabIndex = 44;
			this->HC_CPU_area_par->Text = L"0";
			this->HC_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_start_val
			// 
			this->HC_CPU_start_val->Location = System::Drawing::Point(542, 67);
			this->HC_CPU_start_val->Name = L"HC_CPU_start_val";
			this->HC_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->HC_CPU_start_val->TabIndex = 43;
			this->HC_CPU_start_val->Text = L"0";
			this->HC_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_area_val
			// 
			this->HC_CPU_area_val->Location = System::Drawing::Point(501, 67);
			this->HC_CPU_area_val->Name = L"HC_CPU_area_val";
			this->HC_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->HC_CPU_area_val->TabIndex = 42;
			this->HC_CPU_area_val->Text = L"0";
			this->HC_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_start_cmd
			// 
			this->HC_CPU_start_cmd->Location = System::Drawing::Point(444, 67);
			this->HC_CPU_start_cmd->Name = L"HC_CPU_start_cmd";
			this->HC_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->HC_CPU_start_cmd->TabIndex = 41;
			this->HC_CPU_start_cmd->Text = L"0";
			this->HC_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_area_cmd
			// 
			this->HC_CPU_area_cmd->Location = System::Drawing::Point(403, 67);
			this->HC_CPU_area_cmd->Name = L"HC_CPU_area_cmd";
			this->HC_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->HC_CPU_area_cmd->TabIndex = 40;
			this->HC_CPU_area_cmd->Text = L"0";
			this->HC_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_start_w2
			// 
			this->HC_CPU_start_w2->Location = System::Drawing::Point(346, 67);
			this->HC_CPU_start_w2->Name = L"HC_CPU_start_w2";
			this->HC_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->HC_CPU_start_w2->TabIndex = 39;
			this->HC_CPU_start_w2->Text = L"0";
			this->HC_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_area_w2
			// 
			this->HC_CPU_area_w2->Location = System::Drawing::Point(305, 67);
			this->HC_CPU_area_w2->Name = L"HC_CPU_area_w2";
			this->HC_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->HC_CPU_area_w2->TabIndex = 38;
			this->HC_CPU_area_w2->Text = L"0";
			this->HC_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_start_w1
			// 
			this->HC_CPU_start_w1->Location = System::Drawing::Point(248, 67);
			this->HC_CPU_start_w1->Name = L"HC_CPU_start_w1";
			this->HC_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->HC_CPU_start_w1->TabIndex = 37;
			this->HC_CPU_start_w1->Text = L"0";
			this->HC_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_CPU_area_w1
			// 
			this->HC_CPU_area_w1->Location = System::Drawing::Point(207, 67);
			this->HC_CPU_area_w1->Name = L"HC_CPU_area_w1";
			this->HC_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->HC_CPU_area_w1->TabIndex = 36;
			this->HC_CPU_area_w1->Text = L"0";
			this->HC_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_start_par
			// 
			this->MOT_CPU_start_par->Location = System::Drawing::Point(641, 93);
			this->MOT_CPU_start_par->Name = L"MOT_CPU_start_par";
			this->MOT_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->MOT_CPU_start_par->TabIndex = 55;
			this->MOT_CPU_start_par->Text = L"0";
			this->MOT_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_area_par
			// 
			this->MOT_CPU_area_par->Location = System::Drawing::Point(599, 93);
			this->MOT_CPU_area_par->Name = L"MOT_CPU_area_par";
			this->MOT_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->MOT_CPU_area_par->TabIndex = 54;
			this->MOT_CPU_area_par->Text = L"0";
			this->MOT_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_start_val
			// 
			this->MOT_CPU_start_val->Location = System::Drawing::Point(542, 93);
			this->MOT_CPU_start_val->Name = L"MOT_CPU_start_val";
			this->MOT_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->MOT_CPU_start_val->TabIndex = 53;
			this->MOT_CPU_start_val->Text = L"0";
			this->MOT_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_area_val
			// 
			this->MOT_CPU_area_val->Location = System::Drawing::Point(501, 93);
			this->MOT_CPU_area_val->Name = L"MOT_CPU_area_val";
			this->MOT_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->MOT_CPU_area_val->TabIndex = 52;
			this->MOT_CPU_area_val->Text = L"0";
			this->MOT_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_start_cmd
			// 
			this->MOT_CPU_start_cmd->Location = System::Drawing::Point(444, 93);
			this->MOT_CPU_start_cmd->Name = L"MOT_CPU_start_cmd";
			this->MOT_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->MOT_CPU_start_cmd->TabIndex = 51;
			this->MOT_CPU_start_cmd->Text = L"0";
			this->MOT_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_area_cmd
			// 
			this->MOT_CPU_area_cmd->Location = System::Drawing::Point(403, 93);
			this->MOT_CPU_area_cmd->Name = L"MOT_CPU_area_cmd";
			this->MOT_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->MOT_CPU_area_cmd->TabIndex = 50;
			this->MOT_CPU_area_cmd->Text = L"0";
			this->MOT_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_start_w2
			// 
			this->MOT_CPU_start_w2->Location = System::Drawing::Point(346, 93);
			this->MOT_CPU_start_w2->Name = L"MOT_CPU_start_w2";
			this->MOT_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->MOT_CPU_start_w2->TabIndex = 49;
			this->MOT_CPU_start_w2->Text = L"0";
			this->MOT_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_area_w2
			// 
			this->MOT_CPU_area_w2->Location = System::Drawing::Point(305, 93);
			this->MOT_CPU_area_w2->Name = L"MOT_CPU_area_w2";
			this->MOT_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->MOT_CPU_area_w2->TabIndex = 48;
			this->MOT_CPU_area_w2->Text = L"0";
			this->MOT_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_start_w1
			// 
			this->MOT_CPU_start_w1->Location = System::Drawing::Point(248, 93);
			this->MOT_CPU_start_w1->Name = L"MOT_CPU_start_w1";
			this->MOT_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->MOT_CPU_start_w1->TabIndex = 47;
			this->MOT_CPU_start_w1->Text = L"0";
			this->MOT_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_CPU_area_w1
			// 
			this->MOT_CPU_area_w1->Location = System::Drawing::Point(207, 93);
			this->MOT_CPU_area_w1->Name = L"MOT_CPU_area_w1";
			this->MOT_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->MOT_CPU_area_w1->TabIndex = 46;
			this->MOT_CPU_area_w1->Text = L"0";
			this->MOT_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_start_par
			// 
			this->AI_CPU_start_par->Location = System::Drawing::Point(641, 119);
			this->AI_CPU_start_par->Name = L"AI_CPU_start_par";
			this->AI_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->AI_CPU_start_par->TabIndex = 65;
			this->AI_CPU_start_par->Text = L"0";
			this->AI_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_area_par
			// 
			this->AI_CPU_area_par->Location = System::Drawing::Point(599, 119);
			this->AI_CPU_area_par->Name = L"AI_CPU_area_par";
			this->AI_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->AI_CPU_area_par->TabIndex = 64;
			this->AI_CPU_area_par->Text = L"0";
			this->AI_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_start_val
			// 
			this->AI_CPU_start_val->Location = System::Drawing::Point(542, 119);
			this->AI_CPU_start_val->Name = L"AI_CPU_start_val";
			this->AI_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->AI_CPU_start_val->TabIndex = 63;
			this->AI_CPU_start_val->Text = L"0";
			this->AI_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_area_val
			// 
			this->AI_CPU_area_val->Location = System::Drawing::Point(501, 119);
			this->AI_CPU_area_val->Name = L"AI_CPU_area_val";
			this->AI_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->AI_CPU_area_val->TabIndex = 62;
			this->AI_CPU_area_val->Text = L"0";
			this->AI_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_start_cmd
			// 
			this->AI_CPU_start_cmd->Location = System::Drawing::Point(444, 119);
			this->AI_CPU_start_cmd->Name = L"AI_CPU_start_cmd";
			this->AI_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->AI_CPU_start_cmd->TabIndex = 61;
			this->AI_CPU_start_cmd->Text = L"0";
			this->AI_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_area_cmd
			// 
			this->AI_CPU_area_cmd->Location = System::Drawing::Point(403, 119);
			this->AI_CPU_area_cmd->Name = L"AI_CPU_area_cmd";
			this->AI_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->AI_CPU_area_cmd->TabIndex = 60;
			this->AI_CPU_area_cmd->Text = L"0";
			this->AI_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_start_w2
			// 
			this->AI_CPU_start_w2->Location = System::Drawing::Point(346, 119);
			this->AI_CPU_start_w2->Name = L"AI_CPU_start_w2";
			this->AI_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->AI_CPU_start_w2->TabIndex = 59;
			this->AI_CPU_start_w2->Text = L"0";
			this->AI_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_area_w2
			// 
			this->AI_CPU_area_w2->Location = System::Drawing::Point(305, 119);
			this->AI_CPU_area_w2->Name = L"AI_CPU_area_w2";
			this->AI_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->AI_CPU_area_w2->TabIndex = 58;
			this->AI_CPU_area_w2->Text = L"0";
			this->AI_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_start_w1
			// 
			this->AI_CPU_start_w1->Location = System::Drawing::Point(248, 119);
			this->AI_CPU_start_w1->Name = L"AI_CPU_start_w1";
			this->AI_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->AI_CPU_start_w1->TabIndex = 57;
			this->AI_CPU_start_w1->Text = L"0";
			this->AI_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_CPU_area_w1
			// 
			this->AI_CPU_area_w1->Location = System::Drawing::Point(207, 119);
			this->AI_CPU_area_w1->Name = L"AI_CPU_area_w1";
			this->AI_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->AI_CPU_area_w1->TabIndex = 56;
			this->AI_CPU_area_w1->Text = L"0";
			this->AI_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_start_par
			// 
			this->FC_CPU_start_par->Location = System::Drawing::Point(641, 145);
			this->FC_CPU_start_par->Name = L"FC_CPU_start_par";
			this->FC_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->FC_CPU_start_par->TabIndex = 75;
			this->FC_CPU_start_par->Text = L"0";
			this->FC_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_area_par
			// 
			this->FC_CPU_area_par->Location = System::Drawing::Point(599, 145);
			this->FC_CPU_area_par->Name = L"FC_CPU_area_par";
			this->FC_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->FC_CPU_area_par->TabIndex = 74;
			this->FC_CPU_area_par->Text = L"0";
			this->FC_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_start_val
			// 
			this->FC_CPU_start_val->Location = System::Drawing::Point(542, 145);
			this->FC_CPU_start_val->Name = L"FC_CPU_start_val";
			this->FC_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->FC_CPU_start_val->TabIndex = 73;
			this->FC_CPU_start_val->Text = L"0";
			this->FC_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_area_val
			// 
			this->FC_CPU_area_val->Location = System::Drawing::Point(501, 145);
			this->FC_CPU_area_val->Name = L"FC_CPU_area_val";
			this->FC_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->FC_CPU_area_val->TabIndex = 72;
			this->FC_CPU_area_val->Text = L"0";
			this->FC_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_start_cmd
			// 
			this->FC_CPU_start_cmd->Location = System::Drawing::Point(444, 145);
			this->FC_CPU_start_cmd->Name = L"FC_CPU_start_cmd";
			this->FC_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->FC_CPU_start_cmd->TabIndex = 71;
			this->FC_CPU_start_cmd->Text = L"0";
			this->FC_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_area_cmd
			// 
			this->FC_CPU_area_cmd->Location = System::Drawing::Point(403, 145);
			this->FC_CPU_area_cmd->Name = L"FC_CPU_area_cmd";
			this->FC_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->FC_CPU_area_cmd->TabIndex = 70;
			this->FC_CPU_area_cmd->Text = L"0";
			this->FC_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_start_w2
			// 
			this->FC_CPU_start_w2->Location = System::Drawing::Point(346, 145);
			this->FC_CPU_start_w2->Name = L"FC_CPU_start_w2";
			this->FC_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->FC_CPU_start_w2->TabIndex = 69;
			this->FC_CPU_start_w2->Text = L"0";
			this->FC_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_area_w2
			// 
			this->FC_CPU_area_w2->Location = System::Drawing::Point(305, 145);
			this->FC_CPU_area_w2->Name = L"FC_CPU_area_w2";
			this->FC_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->FC_CPU_area_w2->TabIndex = 68;
			this->FC_CPU_area_w2->Text = L"0";
			this->FC_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_start_w1
			// 
			this->FC_CPU_start_w1->Location = System::Drawing::Point(248, 145);
			this->FC_CPU_start_w1->Name = L"FC_CPU_start_w1";
			this->FC_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->FC_CPU_start_w1->TabIndex = 67;
			this->FC_CPU_start_w1->Text = L"0";
			this->FC_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_CPU_area_w1
			// 
			this->FC_CPU_area_w1->Location = System::Drawing::Point(207, 145);
			this->FC_CPU_area_w1->Name = L"FC_CPU_area_w1";
			this->FC_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->FC_CPU_area_w1->TabIndex = 66;
			this->FC_CPU_area_w1->Text = L"0";
			this->FC_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_start_par
			// 
			this->PID_CPU_start_par->Location = System::Drawing::Point(641, 171);
			this->PID_CPU_start_par->Name = L"PID_CPU_start_par";
			this->PID_CPU_start_par->Size = System::Drawing::Size(42, 20);
			this->PID_CPU_start_par->TabIndex = 85;
			this->PID_CPU_start_par->Text = L"0";
			this->PID_CPU_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_area_par
			// 
			this->PID_CPU_area_par->Location = System::Drawing::Point(599, 171);
			this->PID_CPU_area_par->Name = L"PID_CPU_area_par";
			this->PID_CPU_area_par->Size = System::Drawing::Size(32, 20);
			this->PID_CPU_area_par->TabIndex = 84;
			this->PID_CPU_area_par->Text = L"0";
			this->PID_CPU_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_start_val
			// 
			this->PID_CPU_start_val->Location = System::Drawing::Point(542, 171);
			this->PID_CPU_start_val->Name = L"PID_CPU_start_val";
			this->PID_CPU_start_val->Size = System::Drawing::Size(42, 20);
			this->PID_CPU_start_val->TabIndex = 83;
			this->PID_CPU_start_val->Text = L"0";
			this->PID_CPU_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_area_val
			// 
			this->PID_CPU_area_val->Location = System::Drawing::Point(501, 171);
			this->PID_CPU_area_val->Name = L"PID_CPU_area_val";
			this->PID_CPU_area_val->Size = System::Drawing::Size(32, 20);
			this->PID_CPU_area_val->TabIndex = 82;
			this->PID_CPU_area_val->Text = L"0";
			this->PID_CPU_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_start_cmd
			// 
			this->PID_CPU_start_cmd->Location = System::Drawing::Point(444, 171);
			this->PID_CPU_start_cmd->Name = L"PID_CPU_start_cmd";
			this->PID_CPU_start_cmd->Size = System::Drawing::Size(42, 20);
			this->PID_CPU_start_cmd->TabIndex = 81;
			this->PID_CPU_start_cmd->Text = L"0";
			this->PID_CPU_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_area_cmd
			// 
			this->PID_CPU_area_cmd->Location = System::Drawing::Point(403, 171);
			this->PID_CPU_area_cmd->Name = L"PID_CPU_area_cmd";
			this->PID_CPU_area_cmd->Size = System::Drawing::Size(32, 20);
			this->PID_CPU_area_cmd->TabIndex = 80;
			this->PID_CPU_area_cmd->Text = L"0";
			this->PID_CPU_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_start_w2
			// 
			this->PID_CPU_start_w2->Location = System::Drawing::Point(346, 171);
			this->PID_CPU_start_w2->Name = L"PID_CPU_start_w2";
			this->PID_CPU_start_w2->Size = System::Drawing::Size(42, 20);
			this->PID_CPU_start_w2->TabIndex = 79;
			this->PID_CPU_start_w2->Text = L"0";
			this->PID_CPU_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_area_w2
			// 
			this->PID_CPU_area_w2->Location = System::Drawing::Point(305, 171);
			this->PID_CPU_area_w2->Name = L"PID_CPU_area_w2";
			this->PID_CPU_area_w2->Size = System::Drawing::Size(32, 20);
			this->PID_CPU_area_w2->TabIndex = 78;
			this->PID_CPU_area_w2->Text = L"0";
			this->PID_CPU_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_start_w1
			// 
			this->PID_CPU_start_w1->Location = System::Drawing::Point(248, 171);
			this->PID_CPU_start_w1->Name = L"PID_CPU_start_w1";
			this->PID_CPU_start_w1->Size = System::Drawing::Size(42, 20);
			this->PID_CPU_start_w1->TabIndex = 77;
			this->PID_CPU_start_w1->Text = L"0";
			this->PID_CPU_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_CPU_area_w1
			// 
			this->PID_CPU_area_w1->Location = System::Drawing::Point(207, 171);
			this->PID_CPU_area_w1->Name = L"PID_CPU_area_w1";
			this->PID_CPU_area_w1->Size = System::Drawing::Size(32, 20);
			this->PID_CPU_area_w1->TabIndex = 76;
			this->PID_CPU_area_w1->Text = L"0";
			this->PID_CPU_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label16
			// 
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(156, 43);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(41, 18);
			this->label16->TabIndex = 86;
			this->label16->Text = L"VLV";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label17
			// 
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(156, 69);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(41, 18);
			this->label17->TabIndex = 87;
			this->label17->Text = L"HC";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label18
			// 
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(156, 95);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(45, 18);
			this->label18->TabIndex = 88;
			this->label18->Text = L"MOT";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label19
			// 
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(156, 121);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(41, 18);
			this->label19->TabIndex = 89;
			this->label19->Text = L"AI";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label20
			// 
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(156, 147);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(41, 18);
			this->label20->TabIndex = 90;
			this->label20->Text = L"FC";
			this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label21
			// 
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(156, 173);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(41, 18);
			this->label21->TabIndex = 91;
			this->label21->Text = L"PID";
			this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label22
			// 
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(43, 390);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(41, 18);
			this->label22->TabIndex = 172;
			this->label22->Text = L"PID";
			this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label23
			// 
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(43, 364);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(41, 18);
			this->label23->TabIndex = 171;
			this->label23->Text = L"FC";
			this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label24
			// 
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(43, 338);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(41, 18);
			this->label24->TabIndex = 170;
			this->label24->Text = L"AI";
			this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label25
			// 
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(43, 312);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(45, 18);
			this->label25->TabIndex = 169;
			this->label25->Text = L"MOT";
			this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label26
			// 
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(43, 286);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(41, 18);
			this->label26->TabIndex = 168;
			this->label26->Text = L"HC";
			this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label27
			// 
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(43, 260);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(41, 18);
			this->label27->TabIndex = 167;
			this->label27->Text = L"VLV";
			this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label42
			// 
			this->label42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->Location = System::Drawing::Point(88, 223);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(147, 195);
			this->label42->TabIndex = 94;
			this->label42->Text = L"W1";
			this->label42->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Number_pid
			// 
			this->Number_pid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_pid->Location = System::Drawing::Point(6, 390);
			this->Number_pid->Name = L"Number_pid";
			this->Number_pid->Size = System::Drawing::Size(41, 18);
			this->Number_pid->TabIndex = 178;
			this->Number_pid->Text = L"NR";
			this->Number_pid->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Number_fc
			// 
			this->Number_fc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_fc->Location = System::Drawing::Point(6, 364);
			this->Number_fc->Name = L"Number_fc";
			this->Number_fc->Size = System::Drawing::Size(41, 18);
			this->Number_fc->TabIndex = 177;
			this->Number_fc->Text = L"NR";
			this->Number_fc->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Number_ai
			// 
			this->Number_ai->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_ai->Location = System::Drawing::Point(6, 338);
			this->Number_ai->Name = L"Number_ai";
			this->Number_ai->Size = System::Drawing::Size(41, 18);
			this->Number_ai->TabIndex = 176;
			this->Number_ai->Text = L"NR";
			this->Number_ai->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Number_mot
			// 
			this->Number_mot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_mot->Location = System::Drawing::Point(6, 312);
			this->Number_mot->Name = L"Number_mot";
			this->Number_mot->Size = System::Drawing::Size(41, 18);
			this->Number_mot->TabIndex = 175;
			this->Number_mot->Text = L"NR";
			this->Number_mot->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Number_hc
			// 
			this->Number_hc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_hc->Location = System::Drawing::Point(6, 286);
			this->Number_hc->Name = L"Number_hc";
			this->Number_hc->Size = System::Drawing::Size(41, 18);
			this->Number_hc->TabIndex = 174;
			this->Number_hc->Text = L"NR";
			this->Number_hc->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Number_vlv
			// 
			this->Number_vlv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Number_vlv->Location = System::Drawing::Point(6, 260);
			this->Number_vlv->Name = L"Number_vlv";
			this->Number_vlv->Size = System::Drawing::Size(41, 18);
			this->Number_vlv->TabIndex = 173;
			this->Number_vlv->Text = L"NR";
			this->Number_vlv->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label31
			// 
			this->label31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(232, 223);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(147, 195);
			this->label31->TabIndex = 188;
			this->label31->Text = L"W2";
			this->label31->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label35
			// 
			this->label35->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(522, 223);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(147, 195);
			this->label35->TabIndex = 232;
			this->label35->Text = L"value";
			this->label35->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label41
			// 
			this->label41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->Location = System::Drawing::Point(378, 223);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(147, 195);
			this->label41->TabIndex = 210;
			this->label41->Text = L"cmd";
			this->label41->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label52
			// 
			this->label52->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(668, 223);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(147, 195);
			this->label52->TabIndex = 254;
			this->label52->Text = L"parameters";
			this->label52->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// PID_Test_stop_w1
			// 
			this->PID_Test_stop_w1->Enabled = false;
			this->PID_Test_stop_w1->Location = System::Drawing::Point(183, 388);
			this->PID_Test_stop_w1->Name = L"PID_Test_stop_w1";
			this->PID_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_w1->TabIndex = 275;
			this->PID_Test_stop_w1->Text = L"0";
			this->PID_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_w1
			// 
			this->FC_Test_stop_w1->Enabled = false;
			this->FC_Test_stop_w1->Location = System::Drawing::Point(183, 362);
			this->FC_Test_stop_w1->Name = L"FC_Test_stop_w1";
			this->FC_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_w1->TabIndex = 274;
			this->FC_Test_stop_w1->Text = L"0";
			this->FC_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_w1
			// 
			this->AI_Test_stop_w1->Enabled = false;
			this->AI_Test_stop_w1->Location = System::Drawing::Point(183, 336);
			this->AI_Test_stop_w1->Name = L"AI_Test_stop_w1";
			this->AI_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_w1->TabIndex = 273;
			this->AI_Test_stop_w1->Text = L"0";
			this->AI_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_w1
			// 
			this->MOT_Test_stop_w1->Enabled = false;
			this->MOT_Test_stop_w1->Location = System::Drawing::Point(183, 310);
			this->MOT_Test_stop_w1->Name = L"MOT_Test_stop_w1";
			this->MOT_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_w1->TabIndex = 272;
			this->MOT_Test_stop_w1->Text = L"0";
			this->MOT_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_w1
			// 
			this->HC_Test_stop_w1->Enabled = false;
			this->HC_Test_stop_w1->Location = System::Drawing::Point(183, 284);
			this->HC_Test_stop_w1->Name = L"HC_Test_stop_w1";
			this->HC_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_w1->TabIndex = 271;
			this->HC_Test_stop_w1->Text = L"0";
			this->HC_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_w1
			// 
			this->VLV_Test_stop_w1->Enabled = false;
			this->VLV_Test_stop_w1->Location = System::Drawing::Point(183, 258);
			this->VLV_Test_stop_w1->Name = L"VLV_Test_stop_w1";
			this->VLV_Test_stop_w1->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_w1->TabIndex = 270;
			this->VLV_Test_stop_w1->Text = L"0";
			this->VLV_Test_stop_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(195, 242);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 15);
			this->label1->TabIndex = 269;
			this->label1->Text = L"stop";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_start_w1
			// 
			this->PID_Test_start_w1->Enabled = false;
			this->PID_Test_start_w1->Location = System::Drawing::Point(135, 388);
			this->PID_Test_start_w1->Name = L"PID_Test_start_w1";
			this->PID_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_w1->TabIndex = 268;
			this->PID_Test_start_w1->Text = L"0";
			this->PID_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_w1
			// 
			this->PID_Test_area_w1->Enabled = false;
			this->PID_Test_area_w1->Location = System::Drawing::Point(94, 388);
			this->PID_Test_area_w1->Name = L"PID_Test_area_w1";
			this->PID_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_w1->TabIndex = 267;
			this->PID_Test_area_w1->Text = L"0";
			this->PID_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_w1
			// 
			this->FC_Test_start_w1->Enabled = false;
			this->FC_Test_start_w1->Location = System::Drawing::Point(135, 362);
			this->FC_Test_start_w1->Name = L"FC_Test_start_w1";
			this->FC_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_w1->TabIndex = 266;
			this->FC_Test_start_w1->Text = L"0";
			this->FC_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_w1
			// 
			this->FC_Test_area_w1->Enabled = false;
			this->FC_Test_area_w1->Location = System::Drawing::Point(94, 362);
			this->FC_Test_area_w1->Name = L"FC_Test_area_w1";
			this->FC_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_w1->TabIndex = 265;
			this->FC_Test_area_w1->Text = L"0";
			this->FC_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_w1
			// 
			this->AI_Test_start_w1->Enabled = false;
			this->AI_Test_start_w1->Location = System::Drawing::Point(135, 336);
			this->AI_Test_start_w1->Name = L"AI_Test_start_w1";
			this->AI_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_w1->TabIndex = 264;
			this->AI_Test_start_w1->Text = L"0";
			this->AI_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_w1
			// 
			this->AI_Test_area_w1->Enabled = false;
			this->AI_Test_area_w1->Location = System::Drawing::Point(94, 336);
			this->AI_Test_area_w1->Name = L"AI_Test_area_w1";
			this->AI_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_w1->TabIndex = 263;
			this->AI_Test_area_w1->Text = L"0";
			this->AI_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_w1
			// 
			this->MOT_Test_start_w1->Enabled = false;
			this->MOT_Test_start_w1->Location = System::Drawing::Point(135, 310);
			this->MOT_Test_start_w1->Name = L"MOT_Test_start_w1";
			this->MOT_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_w1->TabIndex = 262;
			this->MOT_Test_start_w1->Text = L"0";
			this->MOT_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_area_w1
			// 
			this->MOT_Test_area_w1->Enabled = false;
			this->MOT_Test_area_w1->Location = System::Drawing::Point(94, 310);
			this->MOT_Test_area_w1->Name = L"MOT_Test_area_w1";
			this->MOT_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->MOT_Test_area_w1->TabIndex = 261;
			this->MOT_Test_area_w1->Text = L"0";
			this->MOT_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_w1
			// 
			this->HC_Test_start_w1->Enabled = false;
			this->HC_Test_start_w1->Location = System::Drawing::Point(135, 284);
			this->HC_Test_start_w1->Name = L"HC_Test_start_w1";
			this->HC_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_w1->TabIndex = 260;
			this->HC_Test_start_w1->Text = L"0";
			this->HC_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_w1
			// 
			this->HC_Test_area_w1->Enabled = false;
			this->HC_Test_area_w1->Location = System::Drawing::Point(94, 284);
			this->HC_Test_area_w1->Name = L"HC_Test_area_w1";
			this->HC_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_w1->TabIndex = 259;
			this->HC_Test_area_w1->Text = L"0";
			this->HC_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_w1
			// 
			this->VLV_Test_start_w1->Enabled = false;
			this->VLV_Test_start_w1->Location = System::Drawing::Point(135, 258);
			this->VLV_Test_start_w1->Name = L"VLV_Test_start_w1";
			this->VLV_Test_start_w1->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_w1->TabIndex = 258;
			this->VLV_Test_start_w1->Text = L"0";
			this->VLV_Test_start_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(147, 242);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(30, 15);
			this->label28->TabIndex = 257;
			this->label28->Text = L"start";
			this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_w1
			// 
			this->VLV_Test_area_w1->Enabled = false;
			this->VLV_Test_area_w1->Location = System::Drawing::Point(94, 258);
			this->VLV_Test_area_w1->Name = L"VLV_Test_area_w1";
			this->VLV_Test_area_w1->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_w1->TabIndex = 256;
			this->VLV_Test_area_w1->Text = L"0";
			this->VLV_Test_area_w1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(94, 241);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(32, 15);
			this->label29->TabIndex = 255;
			this->label29->Text = L"Area";
			this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_stop_w2
			// 
			this->PID_Test_stop_w2->Enabled = false;
			this->PID_Test_stop_w2->Location = System::Drawing::Point(330, 388);
			this->PID_Test_stop_w2->Name = L"PID_Test_stop_w2";
			this->PID_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_w2->TabIndex = 296;
			this->PID_Test_stop_w2->Text = L"0";
			this->PID_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_w2
			// 
			this->FC_Test_stop_w2->Enabled = false;
			this->FC_Test_stop_w2->Location = System::Drawing::Point(330, 362);
			this->FC_Test_stop_w2->Name = L"FC_Test_stop_w2";
			this->FC_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_w2->TabIndex = 295;
			this->FC_Test_stop_w2->Text = L"0";
			this->FC_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_w2
			// 
			this->AI_Test_stop_w2->Enabled = false;
			this->AI_Test_stop_w2->Location = System::Drawing::Point(330, 336);
			this->AI_Test_stop_w2->Name = L"AI_Test_stop_w2";
			this->AI_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_w2->TabIndex = 294;
			this->AI_Test_stop_w2->Text = L"0";
			this->AI_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_w2
			// 
			this->MOT_Test_stop_w2->Enabled = false;
			this->MOT_Test_stop_w2->Location = System::Drawing::Point(330, 310);
			this->MOT_Test_stop_w2->Name = L"MOT_Test_stop_w2";
			this->MOT_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_w2->TabIndex = 293;
			this->MOT_Test_stop_w2->Text = L"0";
			this->MOT_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_w2
			// 
			this->HC_Test_stop_w2->Enabled = false;
			this->HC_Test_stop_w2->Location = System::Drawing::Point(330, 284);
			this->HC_Test_stop_w2->Name = L"HC_Test_stop_w2";
			this->HC_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_w2->TabIndex = 292;
			this->HC_Test_stop_w2->Text = L"0";
			this->HC_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_w2
			// 
			this->VLV_Test_stop_w2->Enabled = false;
			this->VLV_Test_stop_w2->Location = System::Drawing::Point(330, 258);
			this->VLV_Test_stop_w2->Name = L"VLV_Test_stop_w2";
			this->VLV_Test_stop_w2->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_w2->TabIndex = 291;
			this->VLV_Test_stop_w2->Text = L"0";
			this->VLV_Test_stop_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(342, 242);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(30, 15);
			this->label30->TabIndex = 290;
			this->label30->Text = L"stop";
			this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_start_w2
			// 
			this->PID_Test_start_w2->Enabled = false;
			this->PID_Test_start_w2->Location = System::Drawing::Point(282, 388);
			this->PID_Test_start_w2->Name = L"PID_Test_start_w2";
			this->PID_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_w2->TabIndex = 289;
			this->PID_Test_start_w2->Text = L"0";
			this->PID_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_w2
			// 
			this->PID_Test_area_w2->Enabled = false;
			this->PID_Test_area_w2->Location = System::Drawing::Point(241, 388);
			this->PID_Test_area_w2->Name = L"PID_Test_area_w2";
			this->PID_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_w2->TabIndex = 288;
			this->PID_Test_area_w2->Text = L"0";
			this->PID_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_w2
			// 
			this->FC_Test_start_w2->Enabled = false;
			this->FC_Test_start_w2->Location = System::Drawing::Point(282, 362);
			this->FC_Test_start_w2->Name = L"FC_Test_start_w2";
			this->FC_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_w2->TabIndex = 287;
			this->FC_Test_start_w2->Text = L"0";
			this->FC_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_w2
			// 
			this->FC_Test_area_w2->Enabled = false;
			this->FC_Test_area_w2->Location = System::Drawing::Point(241, 362);
			this->FC_Test_area_w2->Name = L"FC_Test_area_w2";
			this->FC_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_w2->TabIndex = 286;
			this->FC_Test_area_w2->Text = L"0";
			this->FC_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_w2
			// 
			this->AI_Test_start_w2->Enabled = false;
			this->AI_Test_start_w2->Location = System::Drawing::Point(282, 336);
			this->AI_Test_start_w2->Name = L"AI_Test_start_w2";
			this->AI_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_w2->TabIndex = 285;
			this->AI_Test_start_w2->Text = L"0";
			this->AI_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_w2
			// 
			this->AI_Test_area_w2->Enabled = false;
			this->AI_Test_area_w2->Location = System::Drawing::Point(241, 336);
			this->AI_Test_area_w2->Name = L"AI_Test_area_w2";
			this->AI_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_w2->TabIndex = 284;
			this->AI_Test_area_w2->Text = L"0";
			this->AI_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_w2
			// 
			this->MOT_Test_start_w2->Enabled = false;
			this->MOT_Test_start_w2->Location = System::Drawing::Point(282, 310);
			this->MOT_Test_start_w2->Name = L"MOT_Test_start_w2";
			this->MOT_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_w2->TabIndex = 283;
			this->MOT_Test_start_w2->Text = L"0";
			this->MOT_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_area_w2
			// 
			this->MOT_Test_area_w2->Enabled = false;
			this->MOT_Test_area_w2->Location = System::Drawing::Point(241, 310);
			this->MOT_Test_area_w2->Name = L"MOT_Test_area_w2";
			this->MOT_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->MOT_Test_area_w2->TabIndex = 282;
			this->MOT_Test_area_w2->Text = L"0";
			this->MOT_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_w2
			// 
			this->HC_Test_start_w2->Enabled = false;
			this->HC_Test_start_w2->Location = System::Drawing::Point(282, 284);
			this->HC_Test_start_w2->Name = L"HC_Test_start_w2";
			this->HC_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_w2->TabIndex = 281;
			this->HC_Test_start_w2->Text = L"0";
			this->HC_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_w2
			// 
			this->HC_Test_area_w2->Enabled = false;
			this->HC_Test_area_w2->Location = System::Drawing::Point(241, 284);
			this->HC_Test_area_w2->Name = L"HC_Test_area_w2";
			this->HC_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_w2->TabIndex = 280;
			this->HC_Test_area_w2->Text = L"0";
			this->HC_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_w2
			// 
			this->VLV_Test_start_w2->Enabled = false;
			this->VLV_Test_start_w2->Location = System::Drawing::Point(282, 258);
			this->VLV_Test_start_w2->Name = L"VLV_Test_start_w2";
			this->VLV_Test_start_w2->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_w2->TabIndex = 279;
			this->VLV_Test_start_w2->Text = L"0";
			this->VLV_Test_start_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(294, 242);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(30, 15);
			this->label32->TabIndex = 278;
			this->label32->Text = L"start";
			this->label32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_w2
			// 
			this->VLV_Test_area_w2->Enabled = false;
			this->VLV_Test_area_w2->Location = System::Drawing::Point(241, 258);
			this->VLV_Test_area_w2->Name = L"VLV_Test_area_w2";
			this->VLV_Test_area_w2->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_w2->TabIndex = 277;
			this->VLV_Test_area_w2->Text = L"0";
			this->VLV_Test_area_w2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(241, 241);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(32, 15);
			this->label33->TabIndex = 276;
			this->label33->Text = L"Area";
			this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_stop_cmd
			// 
			this->PID_Test_stop_cmd->Enabled = false;
			this->PID_Test_stop_cmd->Location = System::Drawing::Point(474, 388);
			this->PID_Test_stop_cmd->Name = L"PID_Test_stop_cmd";
			this->PID_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_cmd->TabIndex = 317;
			this->PID_Test_stop_cmd->Text = L"0";
			this->PID_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_cmd
			// 
			this->FC_Test_stop_cmd->Enabled = false;
			this->FC_Test_stop_cmd->Location = System::Drawing::Point(474, 362);
			this->FC_Test_stop_cmd->Name = L"FC_Test_stop_cmd";
			this->FC_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_cmd->TabIndex = 316;
			this->FC_Test_stop_cmd->Text = L"0";
			this->FC_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_cmd
			// 
			this->AI_Test_stop_cmd->Enabled = false;
			this->AI_Test_stop_cmd->Location = System::Drawing::Point(474, 336);
			this->AI_Test_stop_cmd->Name = L"AI_Test_stop_cmd";
			this->AI_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_cmd->TabIndex = 315;
			this->AI_Test_stop_cmd->Text = L"0";
			this->AI_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_cmd
			// 
			this->MOT_Test_stop_cmd->Enabled = false;
			this->MOT_Test_stop_cmd->Location = System::Drawing::Point(474, 310);
			this->MOT_Test_stop_cmd->Name = L"MOT_Test_stop_cmd";
			this->MOT_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_cmd->TabIndex = 314;
			this->MOT_Test_stop_cmd->Text = L"0";
			this->MOT_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_cmd
			// 
			this->HC_Test_stop_cmd->Enabled = false;
			this->HC_Test_stop_cmd->Location = System::Drawing::Point(474, 284);
			this->HC_Test_stop_cmd->Name = L"HC_Test_stop_cmd";
			this->HC_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_cmd->TabIndex = 313;
			this->HC_Test_stop_cmd->Text = L"0";
			this->HC_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_cmd
			// 
			this->VLV_Test_stop_cmd->Enabled = false;
			this->VLV_Test_stop_cmd->Location = System::Drawing::Point(474, 258);
			this->VLV_Test_stop_cmd->Name = L"VLV_Test_stop_cmd";
			this->VLV_Test_stop_cmd->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_cmd->TabIndex = 312;
			this->VLV_Test_stop_cmd->Text = L"0";
			this->VLV_Test_stop_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(486, 242);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(30, 15);
			this->label34->TabIndex = 311;
			this->label34->Text = L"stop";
			this->label34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_start_cmd
			// 
			this->PID_Test_start_cmd->Enabled = false;
			this->PID_Test_start_cmd->Location = System::Drawing::Point(426, 388);
			this->PID_Test_start_cmd->Name = L"PID_Test_start_cmd";
			this->PID_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_cmd->TabIndex = 310;
			this->PID_Test_start_cmd->Text = L"0";
			this->PID_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_cmd
			// 
			this->PID_Test_area_cmd->Enabled = false;
			this->PID_Test_area_cmd->Location = System::Drawing::Point(385, 388);
			this->PID_Test_area_cmd->Name = L"PID_Test_area_cmd";
			this->PID_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_cmd->TabIndex = 309;
			this->PID_Test_area_cmd->Text = L"0";
			this->PID_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_cmd
			// 
			this->FC_Test_start_cmd->Enabled = false;
			this->FC_Test_start_cmd->Location = System::Drawing::Point(426, 362);
			this->FC_Test_start_cmd->Name = L"FC_Test_start_cmd";
			this->FC_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_cmd->TabIndex = 308;
			this->FC_Test_start_cmd->Text = L"0";
			this->FC_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_cmd
			// 
			this->FC_Test_area_cmd->Enabled = false;
			this->FC_Test_area_cmd->Location = System::Drawing::Point(385, 362);
			this->FC_Test_area_cmd->Name = L"FC_Test_area_cmd";
			this->FC_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_cmd->TabIndex = 307;
			this->FC_Test_area_cmd->Text = L"0";
			this->FC_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_cmd
			// 
			this->AI_Test_start_cmd->Enabled = false;
			this->AI_Test_start_cmd->Location = System::Drawing::Point(426, 336);
			this->AI_Test_start_cmd->Name = L"AI_Test_start_cmd";
			this->AI_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_cmd->TabIndex = 306;
			this->AI_Test_start_cmd->Text = L"0";
			this->AI_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_cmd
			// 
			this->AI_Test_area_cmd->Enabled = false;
			this->AI_Test_area_cmd->Location = System::Drawing::Point(385, 336);
			this->AI_Test_area_cmd->Name = L"AI_Test_area_cmd";
			this->AI_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_cmd->TabIndex = 305;
			this->AI_Test_area_cmd->Text = L"0";
			this->AI_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_cmd
			// 
			this->MOT_Test_start_cmd->Enabled = false;
			this->MOT_Test_start_cmd->Location = System::Drawing::Point(426, 310);
			this->MOT_Test_start_cmd->Name = L"MOT_Test_start_cmd";
			this->MOT_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_cmd->TabIndex = 304;
			this->MOT_Test_start_cmd->Text = L"0";
			this->MOT_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_area_cmd
			// 
			this->MOT_Test_area_cmd->Enabled = false;
			this->MOT_Test_area_cmd->Location = System::Drawing::Point(385, 310);
			this->MOT_Test_area_cmd->Name = L"MOT_Test_area_cmd";
			this->MOT_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->MOT_Test_area_cmd->TabIndex = 303;
			this->MOT_Test_area_cmd->Text = L"0";
			this->MOT_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_cmd
			// 
			this->HC_Test_start_cmd->Enabled = false;
			this->HC_Test_start_cmd->Location = System::Drawing::Point(426, 284);
			this->HC_Test_start_cmd->Name = L"HC_Test_start_cmd";
			this->HC_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_cmd->TabIndex = 302;
			this->HC_Test_start_cmd->Text = L"0";
			this->HC_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_cmd
			// 
			this->HC_Test_area_cmd->Enabled = false;
			this->HC_Test_area_cmd->Location = System::Drawing::Point(385, 284);
			this->HC_Test_area_cmd->Name = L"HC_Test_area_cmd";
			this->HC_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_cmd->TabIndex = 301;
			this->HC_Test_area_cmd->Text = L"0";
			this->HC_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_cmd
			// 
			this->VLV_Test_start_cmd->Enabled = false;
			this->VLV_Test_start_cmd->Location = System::Drawing::Point(426, 258);
			this->VLV_Test_start_cmd->Name = L"VLV_Test_start_cmd";
			this->VLV_Test_start_cmd->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_cmd->TabIndex = 300;
			this->VLV_Test_start_cmd->Text = L"0";
			this->VLV_Test_start_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(438, 242);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(30, 15);
			this->label36->TabIndex = 299;
			this->label36->Text = L"start";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_cmd
			// 
			this->VLV_Test_area_cmd->Enabled = false;
			this->VLV_Test_area_cmd->Location = System::Drawing::Point(385, 258);
			this->VLV_Test_area_cmd->Name = L"VLV_Test_area_cmd";
			this->VLV_Test_area_cmd->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_cmd->TabIndex = 298;
			this->VLV_Test_area_cmd->Text = L"0";
			this->VLV_Test_area_cmd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->Location = System::Drawing::Point(385, 241);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(32, 15);
			this->label37->TabIndex = 297;
			this->label37->Text = L"Area";
			this->label37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_stop_val
			// 
			this->PID_Test_stop_val->Enabled = false;
			this->PID_Test_stop_val->Location = System::Drawing::Point(619, 388);
			this->PID_Test_stop_val->Name = L"PID_Test_stop_val";
			this->PID_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_val->TabIndex = 338;
			this->PID_Test_stop_val->Text = L"0";
			this->PID_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_val
			// 
			this->FC_Test_stop_val->Enabled = false;
			this->FC_Test_stop_val->Location = System::Drawing::Point(619, 362);
			this->FC_Test_stop_val->Name = L"FC_Test_stop_val";
			this->FC_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_val->TabIndex = 337;
			this->FC_Test_stop_val->Text = L"0";
			this->FC_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_val
			// 
			this->AI_Test_stop_val->Enabled = false;
			this->AI_Test_stop_val->Location = System::Drawing::Point(619, 336);
			this->AI_Test_stop_val->Name = L"AI_Test_stop_val";
			this->AI_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_val->TabIndex = 336;
			this->AI_Test_stop_val->Text = L"0";
			this->AI_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_val
			// 
			this->MOT_Test_stop_val->Enabled = false;
			this->MOT_Test_stop_val->Location = System::Drawing::Point(619, 310);
			this->MOT_Test_stop_val->Name = L"MOT_Test_stop_val";
			this->MOT_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_val->TabIndex = 335;
			this->MOT_Test_stop_val->Text = L"0";
			this->MOT_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_val
			// 
			this->HC_Test_stop_val->Enabled = false;
			this->HC_Test_stop_val->Location = System::Drawing::Point(619, 284);
			this->HC_Test_stop_val->Name = L"HC_Test_stop_val";
			this->HC_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_val->TabIndex = 334;
			this->HC_Test_stop_val->Text = L"0";
			this->HC_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_val
			// 
			this->VLV_Test_stop_val->Enabled = false;
			this->VLV_Test_stop_val->Location = System::Drawing::Point(619, 258);
			this->VLV_Test_stop_val->Name = L"VLV_Test_stop_val";
			this->VLV_Test_stop_val->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_val->TabIndex = 333;
			this->VLV_Test_stop_val->Text = L"0";
			this->VLV_Test_stop_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->Location = System::Drawing::Point(631, 242);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(30, 15);
			this->label38->TabIndex = 332;
			this->label38->Text = L"stop";
			this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_start_val
			// 
			this->PID_Test_start_val->Enabled = false;
			this->PID_Test_start_val->Location = System::Drawing::Point(571, 388);
			this->PID_Test_start_val->Name = L"PID_Test_start_val";
			this->PID_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_val->TabIndex = 331;
			this->PID_Test_start_val->Text = L"0";
			this->PID_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_val
			// 
			this->PID_Test_area_val->Enabled = false;
			this->PID_Test_area_val->Location = System::Drawing::Point(530, 388);
			this->PID_Test_area_val->Name = L"PID_Test_area_val";
			this->PID_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_val->TabIndex = 330;
			this->PID_Test_area_val->Text = L"0";
			this->PID_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_val
			// 
			this->FC_Test_start_val->Enabled = false;
			this->FC_Test_start_val->Location = System::Drawing::Point(571, 362);
			this->FC_Test_start_val->Name = L"FC_Test_start_val";
			this->FC_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_val->TabIndex = 329;
			this->FC_Test_start_val->Text = L"0";
			this->FC_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_val
			// 
			this->FC_Test_area_val->Enabled = false;
			this->FC_Test_area_val->Location = System::Drawing::Point(530, 362);
			this->FC_Test_area_val->Name = L"FC_Test_area_val";
			this->FC_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_val->TabIndex = 328;
			this->FC_Test_area_val->Text = L"0";
			this->FC_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_val
			// 
			this->AI_Test_start_val->Enabled = false;
			this->AI_Test_start_val->Location = System::Drawing::Point(571, 336);
			this->AI_Test_start_val->Name = L"AI_Test_start_val";
			this->AI_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_val->TabIndex = 327;
			this->AI_Test_start_val->Text = L"0";
			this->AI_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_val
			// 
			this->AI_Test_area_val->Enabled = false;
			this->AI_Test_area_val->Location = System::Drawing::Point(530, 336);
			this->AI_Test_area_val->Name = L"AI_Test_area_val";
			this->AI_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_val->TabIndex = 326;
			this->AI_Test_area_val->Text = L"0";
			this->AI_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_val
			// 
			this->MOT_Test_start_val->Enabled = false;
			this->MOT_Test_start_val->Location = System::Drawing::Point(571, 310);
			this->MOT_Test_start_val->Name = L"MOT_Test_start_val";
			this->MOT_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_val->TabIndex = 325;
			this->MOT_Test_start_val->Text = L"0";
			this->MOT_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_area_val
			// 
			this->MOT_Test_area_val->Enabled = false;
			this->MOT_Test_area_val->Location = System::Drawing::Point(530, 310);
			this->MOT_Test_area_val->Name = L"MOT_Test_area_val";
			this->MOT_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->MOT_Test_area_val->TabIndex = 324;
			this->MOT_Test_area_val->Text = L"0";
			this->MOT_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_val
			// 
			this->HC_Test_start_val->Enabled = false;
			this->HC_Test_start_val->Location = System::Drawing::Point(571, 284);
			this->HC_Test_start_val->Name = L"HC_Test_start_val";
			this->HC_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_val->TabIndex = 323;
			this->HC_Test_start_val->Text = L"0";
			this->HC_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_val
			// 
			this->HC_Test_area_val->Enabled = false;
			this->HC_Test_area_val->Location = System::Drawing::Point(530, 284);
			this->HC_Test_area_val->Name = L"HC_Test_area_val";
			this->HC_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_val->TabIndex = 322;
			this->HC_Test_area_val->Text = L"0";
			this->HC_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_val
			// 
			this->VLV_Test_start_val->Enabled = false;
			this->VLV_Test_start_val->Location = System::Drawing::Point(571, 258);
			this->VLV_Test_start_val->Name = L"VLV_Test_start_val";
			this->VLV_Test_start_val->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_val->TabIndex = 321;
			this->VLV_Test_start_val->Text = L"0";
			this->VLV_Test_start_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(583, 242);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(30, 15);
			this->label39->TabIndex = 320;
			this->label39->Text = L"start";
			this->label39->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_val
			// 
			this->VLV_Test_area_val->Enabled = false;
			this->VLV_Test_area_val->Location = System::Drawing::Point(530, 258);
			this->VLV_Test_area_val->Name = L"VLV_Test_area_val";
			this->VLV_Test_area_val->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_val->TabIndex = 319;
			this->VLV_Test_area_val->Text = L"0";
			this->VLV_Test_area_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->Location = System::Drawing::Point(530, 241);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(32, 15);
			this->label40->TabIndex = 318;
			this->label40->Text = L"Area";
			this->label40->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_stop_par
			// 
			this->PID_Test_stop_par->Enabled = false;
			this->PID_Test_stop_par->Location = System::Drawing::Point(764, 388);
			this->PID_Test_stop_par->Name = L"PID_Test_stop_par";
			this->PID_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->PID_Test_stop_par->TabIndex = 359;
			this->PID_Test_stop_par->Text = L"0";
			this->PID_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_stop_par
			// 
			this->FC_Test_stop_par->Enabled = false;
			this->FC_Test_stop_par->Location = System::Drawing::Point(764, 362);
			this->FC_Test_stop_par->Name = L"FC_Test_stop_par";
			this->FC_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->FC_Test_stop_par->TabIndex = 358;
			this->FC_Test_stop_par->Text = L"0";
			this->FC_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_stop_par
			// 
			this->AI_Test_stop_par->Enabled = false;
			this->AI_Test_stop_par->Location = System::Drawing::Point(764, 336);
			this->AI_Test_stop_par->Name = L"AI_Test_stop_par";
			this->AI_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->AI_Test_stop_par->TabIndex = 357;
			this->AI_Test_stop_par->Text = L"0";
			this->AI_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_stop_par
			// 
			this->MOT_Test_stop_par->Enabled = false;
			this->MOT_Test_stop_par->Location = System::Drawing::Point(764, 310);
			this->MOT_Test_stop_par->Name = L"MOT_Test_stop_par";
			this->MOT_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_stop_par->TabIndex = 356;
			this->MOT_Test_stop_par->Text = L"0";
			this->MOT_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_stop_par
			// 
			this->HC_Test_stop_par->Enabled = false;
			this->HC_Test_stop_par->Location = System::Drawing::Point(764, 284);
			this->HC_Test_stop_par->Name = L"HC_Test_stop_par";
			this->HC_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->HC_Test_stop_par->TabIndex = 355;
			this->HC_Test_stop_par->Text = L"0";
			this->HC_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_stop_par
			// 
			this->VLV_Test_stop_par->Enabled = false;
			this->VLV_Test_stop_par->Location = System::Drawing::Point(764, 258);
			this->VLV_Test_stop_par->Name = L"VLV_Test_stop_par";
			this->VLV_Test_stop_par->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_stop_par->TabIndex = 354;
			this->VLV_Test_stop_par->Text = L"0";
			this->VLV_Test_stop_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->Location = System::Drawing::Point(776, 242);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(30, 15);
			this->label43->TabIndex = 353;
			this->label43->Text = L"stop";
			this->label43->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PID_Test_start_par
			// 
			this->PID_Test_start_par->Enabled = false;
			this->PID_Test_start_par->Location = System::Drawing::Point(716, 388);
			this->PID_Test_start_par->Name = L"PID_Test_start_par";
			this->PID_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->PID_Test_start_par->TabIndex = 352;
			this->PID_Test_start_par->Text = L"0";
			this->PID_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// PID_Test_area_par
			// 
			this->PID_Test_area_par->Enabled = false;
			this->PID_Test_area_par->Location = System::Drawing::Point(675, 388);
			this->PID_Test_area_par->Name = L"PID_Test_area_par";
			this->PID_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->PID_Test_area_par->TabIndex = 351;
			this->PID_Test_area_par->Text = L"0";
			this->PID_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_start_par
			// 
			this->FC_Test_start_par->Enabled = false;
			this->FC_Test_start_par->Location = System::Drawing::Point(716, 362);
			this->FC_Test_start_par->Name = L"FC_Test_start_par";
			this->FC_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->FC_Test_start_par->TabIndex = 350;
			this->FC_Test_start_par->Text = L"0";
			this->FC_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FC_Test_area_par
			// 
			this->FC_Test_area_par->Enabled = false;
			this->FC_Test_area_par->Location = System::Drawing::Point(675, 362);
			this->FC_Test_area_par->Name = L"FC_Test_area_par";
			this->FC_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->FC_Test_area_par->TabIndex = 349;
			this->FC_Test_area_par->Text = L"0";
			this->FC_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_start_par
			// 
			this->AI_Test_start_par->Enabled = false;
			this->AI_Test_start_par->Location = System::Drawing::Point(716, 336);
			this->AI_Test_start_par->Name = L"AI_Test_start_par";
			this->AI_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->AI_Test_start_par->TabIndex = 348;
			this->AI_Test_start_par->Text = L"0";
			this->AI_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// AI_Test_area_par
			// 
			this->AI_Test_area_par->Enabled = false;
			this->AI_Test_area_par->Location = System::Drawing::Point(675, 336);
			this->AI_Test_area_par->Name = L"AI_Test_area_par";
			this->AI_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->AI_Test_area_par->TabIndex = 347;
			this->AI_Test_area_par->Text = L"0";
			this->AI_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_start_par
			// 
			this->MOT_Test_start_par->Enabled = false;
			this->MOT_Test_start_par->Location = System::Drawing::Point(716, 310);
			this->MOT_Test_start_par->Name = L"MOT_Test_start_par";
			this->MOT_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->MOT_Test_start_par->TabIndex = 346;
			this->MOT_Test_start_par->Text = L"0";
			this->MOT_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MOT_Test_area_par
			// 
			this->MOT_Test_area_par->Enabled = false;
			this->MOT_Test_area_par->Location = System::Drawing::Point(675, 310);
			this->MOT_Test_area_par->Name = L"MOT_Test_area_par";
			this->MOT_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->MOT_Test_area_par->TabIndex = 345;
			this->MOT_Test_area_par->Text = L"0";
			this->MOT_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_start_par
			// 
			this->HC_Test_start_par->Enabled = false;
			this->HC_Test_start_par->Location = System::Drawing::Point(716, 284);
			this->HC_Test_start_par->Name = L"HC_Test_start_par";
			this->HC_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->HC_Test_start_par->TabIndex = 344;
			this->HC_Test_start_par->Text = L"0";
			this->HC_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// HC_Test_area_par
			// 
			this->HC_Test_area_par->Enabled = false;
			this->HC_Test_area_par->Location = System::Drawing::Point(675, 284);
			this->HC_Test_area_par->Name = L"HC_Test_area_par";
			this->HC_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->HC_Test_area_par->TabIndex = 343;
			this->HC_Test_area_par->Text = L"0";
			this->HC_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// VLV_Test_start_par
			// 
			this->VLV_Test_start_par->Enabled = false;
			this->VLV_Test_start_par->Location = System::Drawing::Point(716, 258);
			this->VLV_Test_start_par->Name = L"VLV_Test_start_par";
			this->VLV_Test_start_par->Size = System::Drawing::Size(42, 20);
			this->VLV_Test_start_par->TabIndex = 342;
			this->VLV_Test_start_par->Text = L"0";
			this->VLV_Test_start_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label44->Location = System::Drawing::Point(728, 242);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(30, 15);
			this->label44->TabIndex = 341;
			this->label44->Text = L"start";
			this->label44->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VLV_Test_area_par
			// 
			this->VLV_Test_area_par->Enabled = false;
			this->VLV_Test_area_par->Location = System::Drawing::Point(675, 258);
			this->VLV_Test_area_par->Name = L"VLV_Test_area_par";
			this->VLV_Test_area_par->Size = System::Drawing::Size(32, 20);
			this->VLV_Test_area_par->TabIndex = 340;
			this->VLV_Test_area_par->Text = L"0";
			this->VLV_Test_area_par->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(675, 241);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(32, 15);
			this->label45->TabIndex = 339;
			this->label45->Text = L"Area";
			this->label45->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Check_button
			// 
			this->Check_button->Location = System::Drawing::Point(304, 428);
			this->Check_button->Name = L"Check_button";
			this->Check_button->Size = System::Drawing::Size(75, 23);
			this->Check_button->TabIndex = 360;
			this->Check_button->Text = L"Check";
			this->Check_button->UseVisualStyleBackColor = true;
			this->Check_button->Click += gcnew System::EventHandler(this, &Address_Form::Check_button_Click);
			// 
			// Done_button
			// 
			this->Done_button->Location = System::Drawing::Point(420, 428);
			this->Done_button->Name = L"Done_button";
			this->Done_button->Size = System::Drawing::Size(75, 23);
			this->Done_button->TabIndex = 361;
			this->Done_button->Text = L"Done";
			this->Done_button->UseVisualStyleBackColor = true;
			this->Done_button->Click += gcnew System::EventHandler(this, &Address_Form::Done_button_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->Location = System::Drawing::Point(530, 428);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(75, 23);
			this->Cancel_button->TabIndex = 362;
			this->Cancel_button->Text = L"Cancel";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &Address_Form::Cancel_button_Click);
			// 
			// Address_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 463);
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->Done_button);
			this->Controls->Add(this->Check_button);
			this->Controls->Add(this->PID_Test_stop_par);
			this->Controls->Add(this->FC_Test_stop_par);
			this->Controls->Add(this->AI_Test_stop_par);
			this->Controls->Add(this->MOT_Test_stop_par);
			this->Controls->Add(this->HC_Test_stop_par);
			this->Controls->Add(this->VLV_Test_stop_par);
			this->Controls->Add(this->label43);
			this->Controls->Add(this->PID_Test_start_par);
			this->Controls->Add(this->PID_Test_area_par);
			this->Controls->Add(this->FC_Test_start_par);
			this->Controls->Add(this->FC_Test_area_par);
			this->Controls->Add(this->AI_Test_start_par);
			this->Controls->Add(this->AI_Test_area_par);
			this->Controls->Add(this->MOT_Test_start_par);
			this->Controls->Add(this->MOT_Test_area_par);
			this->Controls->Add(this->HC_Test_start_par);
			this->Controls->Add(this->HC_Test_area_par);
			this->Controls->Add(this->VLV_Test_start_par);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->VLV_Test_area_par);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->PID_Test_stop_val);
			this->Controls->Add(this->FC_Test_stop_val);
			this->Controls->Add(this->AI_Test_stop_val);
			this->Controls->Add(this->MOT_Test_stop_val);
			this->Controls->Add(this->HC_Test_stop_val);
			this->Controls->Add(this->VLV_Test_stop_val);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->PID_Test_start_val);
			this->Controls->Add(this->PID_Test_area_val);
			this->Controls->Add(this->FC_Test_start_val);
			this->Controls->Add(this->FC_Test_area_val);
			this->Controls->Add(this->AI_Test_start_val);
			this->Controls->Add(this->AI_Test_area_val);
			this->Controls->Add(this->MOT_Test_start_val);
			this->Controls->Add(this->MOT_Test_area_val);
			this->Controls->Add(this->HC_Test_start_val);
			this->Controls->Add(this->HC_Test_area_val);
			this->Controls->Add(this->VLV_Test_start_val);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->VLV_Test_area_val);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->PID_Test_stop_cmd);
			this->Controls->Add(this->FC_Test_stop_cmd);
			this->Controls->Add(this->AI_Test_stop_cmd);
			this->Controls->Add(this->MOT_Test_stop_cmd);
			this->Controls->Add(this->HC_Test_stop_cmd);
			this->Controls->Add(this->VLV_Test_stop_cmd);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->PID_Test_start_cmd);
			this->Controls->Add(this->PID_Test_area_cmd);
			this->Controls->Add(this->FC_Test_start_cmd);
			this->Controls->Add(this->FC_Test_area_cmd);
			this->Controls->Add(this->AI_Test_start_cmd);
			this->Controls->Add(this->AI_Test_area_cmd);
			this->Controls->Add(this->MOT_Test_start_cmd);
			this->Controls->Add(this->MOT_Test_area_cmd);
			this->Controls->Add(this->HC_Test_start_cmd);
			this->Controls->Add(this->HC_Test_area_cmd);
			this->Controls->Add(this->VLV_Test_start_cmd);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->VLV_Test_area_cmd);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->PID_Test_stop_w2);
			this->Controls->Add(this->FC_Test_stop_w2);
			this->Controls->Add(this->AI_Test_stop_w2);
			this->Controls->Add(this->MOT_Test_stop_w2);
			this->Controls->Add(this->HC_Test_stop_w2);
			this->Controls->Add(this->VLV_Test_stop_w2);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->PID_Test_start_w2);
			this->Controls->Add(this->PID_Test_area_w2);
			this->Controls->Add(this->FC_Test_start_w2);
			this->Controls->Add(this->FC_Test_area_w2);
			this->Controls->Add(this->AI_Test_start_w2);
			this->Controls->Add(this->AI_Test_area_w2);
			this->Controls->Add(this->MOT_Test_start_w2);
			this->Controls->Add(this->MOT_Test_area_w2);
			this->Controls->Add(this->HC_Test_start_w2);
			this->Controls->Add(this->HC_Test_area_w2);
			this->Controls->Add(this->VLV_Test_start_w2);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->VLV_Test_area_w2);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->PID_Test_stop_w1);
			this->Controls->Add(this->FC_Test_stop_w1);
			this->Controls->Add(this->AI_Test_stop_w1);
			this->Controls->Add(this->MOT_Test_stop_w1);
			this->Controls->Add(this->HC_Test_stop_w1);
			this->Controls->Add(this->VLV_Test_stop_w1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PID_Test_start_w1);
			this->Controls->Add(this->PID_Test_area_w1);
			this->Controls->Add(this->FC_Test_start_w1);
			this->Controls->Add(this->FC_Test_area_w1);
			this->Controls->Add(this->AI_Test_start_w1);
			this->Controls->Add(this->AI_Test_area_w1);
			this->Controls->Add(this->MOT_Test_start_w1);
			this->Controls->Add(this->MOT_Test_area_w1);
			this->Controls->Add(this->HC_Test_start_w1);
			this->Controls->Add(this->HC_Test_area_w1);
			this->Controls->Add(this->VLV_Test_start_w1);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->VLV_Test_area_w1);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label52);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->Number_pid);
			this->Controls->Add(this->Number_fc);
			this->Controls->Add(this->Number_ai);
			this->Controls->Add(this->Number_mot);
			this->Controls->Add(this->Number_hc);
			this->Controls->Add(this->Number_vlv);
			this->Controls->Add(this->label42);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->PID_CPU_start_par);
			this->Controls->Add(this->PID_CPU_area_par);
			this->Controls->Add(this->PID_CPU_start_val);
			this->Controls->Add(this->PID_CPU_area_val);
			this->Controls->Add(this->PID_CPU_start_cmd);
			this->Controls->Add(this->PID_CPU_area_cmd);
			this->Controls->Add(this->PID_CPU_start_w2);
			this->Controls->Add(this->PID_CPU_area_w2);
			this->Controls->Add(this->PID_CPU_start_w1);
			this->Controls->Add(this->PID_CPU_area_w1);
			this->Controls->Add(this->FC_CPU_start_par);
			this->Controls->Add(this->FC_CPU_area_par);
			this->Controls->Add(this->FC_CPU_start_val);
			this->Controls->Add(this->FC_CPU_area_val);
			this->Controls->Add(this->FC_CPU_start_cmd);
			this->Controls->Add(this->FC_CPU_area_cmd);
			this->Controls->Add(this->FC_CPU_start_w2);
			this->Controls->Add(this->FC_CPU_area_w2);
			this->Controls->Add(this->FC_CPU_start_w1);
			this->Controls->Add(this->FC_CPU_area_w1);
			this->Controls->Add(this->AI_CPU_start_par);
			this->Controls->Add(this->AI_CPU_area_par);
			this->Controls->Add(this->AI_CPU_start_val);
			this->Controls->Add(this->AI_CPU_area_val);
			this->Controls->Add(this->AI_CPU_start_cmd);
			this->Controls->Add(this->AI_CPU_area_cmd);
			this->Controls->Add(this->AI_CPU_start_w2);
			this->Controls->Add(this->AI_CPU_area_w2);
			this->Controls->Add(this->AI_CPU_start_w1);
			this->Controls->Add(this->AI_CPU_area_w1);
			this->Controls->Add(this->MOT_CPU_start_par);
			this->Controls->Add(this->MOT_CPU_area_par);
			this->Controls->Add(this->MOT_CPU_start_val);
			this->Controls->Add(this->MOT_CPU_area_val);
			this->Controls->Add(this->MOT_CPU_start_cmd);
			this->Controls->Add(this->MOT_CPU_area_cmd);
			this->Controls->Add(this->MOT_CPU_start_w2);
			this->Controls->Add(this->MOT_CPU_area_w2);
			this->Controls->Add(this->MOT_CPU_start_w1);
			this->Controls->Add(this->MOT_CPU_area_w1);
			this->Controls->Add(this->HC_CPU_start_par);
			this->Controls->Add(this->HC_CPU_area_par);
			this->Controls->Add(this->HC_CPU_start_val);
			this->Controls->Add(this->HC_CPU_area_val);
			this->Controls->Add(this->HC_CPU_start_cmd);
			this->Controls->Add(this->HC_CPU_area_cmd);
			this->Controls->Add(this->HC_CPU_start_w2);
			this->Controls->Add(this->HC_CPU_area_w2);
			this->Controls->Add(this->HC_CPU_start_w1);
			this->Controls->Add(this->HC_CPU_area_w1);
			this->Controls->Add(this->VLV_CPU_start_par);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->VLV_CPU_area_par);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->VLV_CPU_start_val);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->VLV_CPU_area_val);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->VLV_CPU_start_cmd);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->VLV_CPU_area_cmd);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->VLV_CPU_start_w2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->VLV_CPU_area_w2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->VLV_CPU_start_w1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->VLV_CPU_area_w1);
			this->Controls->Add(this->label);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label27);
			this->Name = L"Address_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Address_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: int return_value = -1;
		int AI_nr_max = 0;
		int VLV_nr_max = 0;
		int HC_nr_max = 0;
		int FC_nr_max = 0;
		int PID_nr_max = 0;
		int MOT_nr_max = 0;

	private: void data_get1_test(System::Windows::Forms::TextBox^ textBox_area, System::Windows::Forms::TextBox^ textBox_start, System::Windows::Forms::TextBox^ textBox_end, adr_1test_str parameter)
	{
		if (parameter.area == -99)
		{
			textBox_start->Visible = false;
			textBox_end->Visible = false;
			textBox_area->Visible = false;
		}
		else
		{
			textBox_start->Visible = true;
			string text_value = to_string(parameter.start_adr);
			textBox_start->Text = string_to_system_string(text_value);

			textBox_end->Visible = true;
			text_value = to_string(parameter.end_adress);
			textBox_end->Text = string_to_system_string(text_value);

			textBox_area->Visible = true;
			text_value = to_string(parameter.area);
			textBox_area->Text = string_to_system_string(text_value);
		}			
	}
	
	private: void data_get1_cpu(System::Windows::Forms::TextBox^ textBox_area, System::Windows::Forms::TextBox^ textBox_start,  addres_1par_str parameter)
	{
		if (parameter.area == -99)
		{
			textBox_start->Visible = false;
			textBox_area->Visible = false;
		}
		else
		{
			textBox_start->Visible = true;
			string text_value = to_string(parameter.start_adr);
			textBox_start->Text = string_to_system_string(text_value);

			textBox_area->Visible = true;
			text_value = to_string(parameter.area);
			textBox_area->Text = string_to_system_string(text_value);
		}
	}

	private: void data_put1_cpu(System::Windows::Forms::TextBox^ textBox_area, System::Windows::Forms::TextBox^ textBox_start, addres_1par_str &parameter)
	{
		String^ texts = textBox_start->Text;
		string text_value = system_string_to_string(texts);
		parameter.start_adr = atoi(text_value.c_str());

		texts = textBox_area->Text;
		text_value = system_string_to_string(texts);
		parameter.area = atoi(text_value.c_str());
	}

	private:void Put_all_data_to_cpu()
	{
		addres_pars_CPU_str CPU_adr;

		if (Declare_adress_get_CPU_switch(CPU_adr) == 1)
		{
			return_value = -1;
			this->Close();
		}

		data_put1_cpu(HC_CPU_area_par, HC_CPU_start_par, CPU_adr.hc.pars);
		data_put1_cpu(HC_CPU_area_val, HC_CPU_start_val, CPU_adr.hc.val);
		data_put1_cpu(HC_CPU_area_w1, HC_CPU_start_w1, CPU_adr.hc.w1);
		data_put1_cpu(HC_CPU_area_w2, HC_CPU_start_w2, CPU_adr.hc.w2);
		data_put1_cpu(HC_CPU_area_cmd, HC_CPU_start_cmd, CPU_adr.hc.cmd);

		data_put1_cpu(AI_CPU_area_par, AI_CPU_start_par, CPU_adr.ai.pars);
		data_put1_cpu(AI_CPU_area_val, AI_CPU_start_val, CPU_adr.ai.val);
		data_put1_cpu(AI_CPU_area_w1, AI_CPU_start_w1, CPU_adr.ai.w1);
		data_put1_cpu(AI_CPU_area_w2, AI_CPU_start_w2, CPU_adr.ai.w2);
		data_put1_cpu(AI_CPU_area_cmd, AI_CPU_start_cmd, CPU_adr.ai.cmd);

		data_put1_cpu(MOT_CPU_area_par, MOT_CPU_start_par, CPU_adr.mot.pars);
		data_put1_cpu(MOT_CPU_area_val, MOT_CPU_start_val, CPU_adr.mot.val);
		data_put1_cpu(MOT_CPU_area_w1, MOT_CPU_start_w1, CPU_adr.mot.w1);
		data_put1_cpu(MOT_CPU_area_w2, MOT_CPU_start_w2, CPU_adr.mot.w2);
		data_put1_cpu(MOT_CPU_area_cmd, MOT_CPU_start_cmd, CPU_adr.mot.cmd);

		data_put1_cpu(VLV_CPU_area_par, VLV_CPU_start_par, CPU_adr.vlv.pars);
		data_put1_cpu(VLV_CPU_area_val, VLV_CPU_start_val, CPU_adr.vlv.val);
		data_put1_cpu(VLV_CPU_area_w1, VLV_CPU_start_w1, CPU_adr.vlv.w1);
		data_put1_cpu(VLV_CPU_area_w2, VLV_CPU_start_w2, CPU_adr.vlv.w2);
		data_put1_cpu(VLV_CPU_area_cmd, VLV_CPU_start_cmd, CPU_adr.vlv.cmd);

		data_put1_cpu(PID_CPU_area_par, PID_CPU_start_par, CPU_adr.pid.pars);
		data_put1_cpu(PID_CPU_area_val, PID_CPU_start_val, CPU_adr.pid.val);
		data_put1_cpu(PID_CPU_area_w1, PID_CPU_start_w1, CPU_adr.pid.w1);
		data_put1_cpu(PID_CPU_area_w2, PID_CPU_start_w2, CPU_adr.pid.w2);
		data_put1_cpu(PID_CPU_area_cmd, PID_CPU_start_cmd, CPU_adr.pid.cmd);

		data_put1_cpu(FC_CPU_area_par, FC_CPU_start_par, CPU_adr.fc.pars);
		data_put1_cpu(FC_CPU_area_val, FC_CPU_start_val, CPU_adr.fc.val);
		data_put1_cpu(FC_CPU_area_w1, FC_CPU_start_w1, CPU_adr.fc.w1);
		data_put1_cpu(FC_CPU_area_w2, FC_CPU_start_w2, CPU_adr.fc.w2);
		data_put1_cpu(FC_CPU_area_cmd, FC_CPU_start_cmd, CPU_adr.fc.cmd);

		Declare_adress_put_CPU_switch(CPU_adr);

	}

	private:void Put_all_data_to_Form(addres_pars_CPU_str CPU_adr, adr_cpu_test_str test)
	{
		data_get1_cpu(HC_CPU_area_par, HC_CPU_start_par, CPU_adr.hc.pars);
		data_get1_cpu(HC_CPU_area_val, HC_CPU_start_val, CPU_adr.hc.val);
		data_get1_cpu(HC_CPU_area_w1, HC_CPU_start_w1, CPU_adr.hc.w1);
		data_get1_cpu(HC_CPU_area_w2, HC_CPU_start_w2, CPU_adr.hc.w2);
		data_get1_cpu(HC_CPU_area_cmd, HC_CPU_start_cmd, CPU_adr.hc.cmd);

		data_get1_cpu(AI_CPU_area_par, AI_CPU_start_par, CPU_adr.ai.pars);
		data_get1_cpu(AI_CPU_area_val, AI_CPU_start_val, CPU_adr.ai.val);
		data_get1_cpu(AI_CPU_area_w1, AI_CPU_start_w1, CPU_adr.ai.w1);
		data_get1_cpu(AI_CPU_area_w2, AI_CPU_start_w2, CPU_adr.ai.w2);
		data_get1_cpu(AI_CPU_area_cmd, AI_CPU_start_cmd, CPU_adr.ai.cmd);

		data_get1_cpu(MOT_CPU_area_par, MOT_CPU_start_par, CPU_adr.mot.pars);
		data_get1_cpu(MOT_CPU_area_val, MOT_CPU_start_val, CPU_adr.mot.val);
		data_get1_cpu(MOT_CPU_area_w1, MOT_CPU_start_w1, CPU_adr.mot.w1);
		data_get1_cpu(MOT_CPU_area_w2, MOT_CPU_start_w2, CPU_adr.mot.w2);
		data_get1_cpu(MOT_CPU_area_cmd, MOT_CPU_start_cmd, CPU_adr.mot.cmd);

		data_get1_cpu(VLV_CPU_area_par, VLV_CPU_start_par, CPU_adr.vlv.pars);
		data_get1_cpu(VLV_CPU_area_val, VLV_CPU_start_val, CPU_adr.vlv.val);
		data_get1_cpu(VLV_CPU_area_w1, VLV_CPU_start_w1, CPU_adr.vlv.w1);
		data_get1_cpu(VLV_CPU_area_w2, VLV_CPU_start_w2, CPU_adr.vlv.w2);
		data_get1_cpu(VLV_CPU_area_cmd, VLV_CPU_start_cmd, CPU_adr.vlv.cmd);

		data_get1_cpu(PID_CPU_area_par, PID_CPU_start_par, CPU_adr.pid.pars);
		data_get1_cpu(PID_CPU_area_val, PID_CPU_start_val, CPU_adr.pid.val);
		data_get1_cpu(PID_CPU_area_w1, PID_CPU_start_w1, CPU_adr.pid.w1);
		data_get1_cpu(PID_CPU_area_w2, PID_CPU_start_w2, CPU_adr.pid.w2);
		data_get1_cpu(PID_CPU_area_cmd, PID_CPU_start_cmd, CPU_adr.pid.cmd);

		data_get1_cpu(FC_CPU_area_par, FC_CPU_start_par, CPU_adr.fc.pars);
		data_get1_cpu(FC_CPU_area_val, FC_CPU_start_val, CPU_adr.fc.val);
		data_get1_cpu(FC_CPU_area_w1, FC_CPU_start_w1, CPU_adr.fc.w1);
		data_get1_cpu(FC_CPU_area_w2, FC_CPU_start_w2, CPU_adr.fc.w2);
		data_get1_cpu(FC_CPU_area_cmd, FC_CPU_start_cmd, CPU_adr.fc.cmd);

		//test data
		data_get1_test(HC_Test_area_par, HC_Test_start_par, HC_Test_stop_par, test.hc.pars);
		data_get1_test(HC_Test_area_val, HC_Test_start_val, HC_Test_stop_val, test.hc.val);
		data_get1_test(HC_Test_area_w1, HC_Test_start_w1, HC_Test_stop_w1, test.hc.w1);
		data_get1_test(HC_Test_area_w2, HC_Test_start_w2, HC_Test_stop_w2, test.hc.w2);
		data_get1_test(HC_Test_area_cmd, HC_Test_start_cmd, HC_Test_stop_cmd, test.hc.cmd);

		data_get1_test(AI_Test_area_par, AI_Test_start_par, AI_Test_stop_par, test.ai.pars);
		data_get1_test(AI_Test_area_val, AI_Test_start_val, AI_Test_stop_val, test.ai.val);
		data_get1_test(AI_Test_area_w1, AI_Test_start_w1, AI_Test_stop_w1, test.ai.w1);
		data_get1_test(AI_Test_area_w2, AI_Test_start_w2, AI_Test_stop_w2, test.ai.w2);
		data_get1_test(AI_Test_area_cmd, AI_Test_start_cmd, AI_Test_stop_cmd, test.ai.cmd);

		data_get1_test(MOT_Test_area_par, MOT_Test_start_par, MOT_Test_stop_par, test.mot.pars);
		data_get1_test(MOT_Test_area_val, MOT_Test_start_val, MOT_Test_stop_val, test.mot.val);
		data_get1_test(MOT_Test_area_w1, MOT_Test_start_w1, MOT_Test_stop_w1, test.mot.w1);
		data_get1_test(MOT_Test_area_w2, MOT_Test_start_w2, MOT_Test_stop_w2, test.mot.w2);
		data_get1_test(MOT_Test_area_cmd, MOT_Test_start_cmd, MOT_Test_stop_cmd, test.mot.cmd);

		data_get1_test(VLV_Test_area_par, VLV_Test_start_par, VLV_Test_stop_par, test.vlv.pars);
		data_get1_test(VLV_Test_area_val, VLV_Test_start_val, VLV_Test_stop_val, test.vlv.val);
		data_get1_test(VLV_Test_area_w1, VLV_Test_start_w1, VLV_Test_stop_w1, test.vlv.w1);
		data_get1_test(VLV_Test_area_w2, VLV_Test_start_w2, VLV_Test_stop_w2, test.vlv.w2);
		data_get1_test(VLV_Test_area_cmd, VLV_Test_start_cmd, VLV_Test_stop_cmd, test.vlv.cmd);

		data_get1_test(PID_Test_area_par, PID_Test_start_par, PID_Test_stop_par, test.pid.pars);
		data_get1_test(PID_Test_area_val, PID_Test_start_val, PID_Test_stop_val, test.pid.val);
		data_get1_test(PID_Test_area_w1, PID_Test_start_w1, PID_Test_stop_w1, test.pid.w1);
		data_get1_test(PID_Test_area_w2, PID_Test_start_w2, PID_Test_stop_w2, test.pid.w2);
		data_get1_test(PID_Test_area_cmd, PID_Test_start_cmd, PID_Test_stop_cmd, test.pid.cmd);

		data_get1_test(FC_Test_area_par, FC_Test_start_par, FC_Test_stop_par, test.fc.pars);
		data_get1_test(FC_Test_area_val, FC_Test_start_val, FC_Test_stop_val, test.fc.val);
		data_get1_test(FC_Test_area_w1, FC_Test_start_w1, FC_Test_stop_w1, test.fc.w1);
		data_get1_test(FC_Test_area_w2, FC_Test_start_w2, FC_Test_stop_w2, test.fc.w2);
		data_get1_test(FC_Test_area_cmd, FC_Test_start_cmd, FC_Test_stop_cmd, test.fc.cmd);

	}

	public: void Adress_color(int color_flag, System::Windows::Forms::TextBox^ textBox_w1, System::Windows::Forms::TextBox^ textBox_w2,
		System::Windows::Forms::TextBox^ textBox_cmd, System::Windows::Forms::TextBox^ textBox_val, System::Windows::Forms::TextBox^ textBox_par)
	{
		Color overlap_Color_BG = System::Drawing::Color::Yellow;
		Color overlap_Color_text = System::Drawing::Color::Red;

		if (color_flag & (1 << w1_index))
		{
			textBox_w1->BackColor = overlap_Color_BG;
			textBox_w1->ForeColor = overlap_Color_text;
		}
		else
		{
			textBox_w1->BackColor = System::Drawing::SystemColors::Window;
			textBox_w1->ForeColor = System::Drawing::SystemColors::WindowText;
		}

		if (color_flag & (1 << w2_index))
		{
			textBox_w2->BackColor = overlap_Color_BG;
			textBox_w2->ForeColor = overlap_Color_text;
		}
		else
		{
			textBox_w2->BackColor = System::Drawing::SystemColors::Window;
			textBox_w2->ForeColor = System::Drawing::SystemColors::WindowText;
		}

		if (color_flag & (1 << cmd_index))
		{
			textBox_cmd->BackColor = overlap_Color_BG;
			textBox_cmd->ForeColor = overlap_Color_text;
		}
		else
		{
			textBox_cmd->BackColor = System::Drawing::SystemColors::Window;
			textBox_cmd->ForeColor = System::Drawing::SystemColors::WindowText;
		}

		if (color_flag & (1 << val_index))
		{
			textBox_val->BackColor = overlap_Color_BG;
			textBox_val->ForeColor = overlap_Color_text;
		}
		else
		{
			textBox_val->BackColor = System::Drawing::SystemColors::Window;
			textBox_val->ForeColor = System::Drawing::SystemColors::WindowText;
		}

		if (color_flag & (1 << pars_index))
		{
			textBox_par->BackColor = overlap_Color_BG;
			textBox_par->ForeColor = overlap_Color_text;
		}
		else
		{
			textBox_par->BackColor = System::Drawing::SystemColors::Window;
			textBox_par->ForeColor = System::Drawing::SystemColors::WindowText;
		}		
	}
	public: void Adress_init(check_result_str result_ob, adr_cpu_test_str test, int AI_nr_max, int VLV_nr_max, int HC_nr_max, int FC_nr_max, int PID_nr_max, int MOT_nr_max)
	{
		return_value = -1;
		addres_pars_CPU_str CPU_adr;

		if (Declare_adress_get_CPU_switch(CPU_adr) == 1)
		{
			return_value = -1;
			this->Close();
		}

		string text_value = to_string(AI_nr_max);
		Number_ai->Text = string_to_system_string(text_value);

		text_value = to_string(VLV_nr_max);
		Number_vlv->Text = string_to_system_string(text_value);

		text_value = to_string(HC_nr_max);
		Number_hc->Text = string_to_system_string(text_value);

		text_value = to_string(FC_nr_max);
		Number_fc->Text = string_to_system_string(text_value);

		text_value = to_string(PID_nr_max);
		Number_pid->Text = string_to_system_string(text_value);

		text_value = to_string(MOT_nr_max);
		Number_mot->Text = string_to_system_string(text_value);

		Adress_color(result_ob.ai, AI_Test_start_w1, AI_Test_start_w2, AI_Test_start_cmd, AI_Test_start_val, AI_Test_start_par);
		Adress_color(result_ob.hc, HC_Test_start_w1, HC_Test_start_w2, HC_Test_start_cmd, HC_Test_start_val, HC_Test_start_par);
		Adress_color(result_ob.mot, MOT_Test_start_w1, MOT_Test_start_w2, MOT_Test_start_cmd, MOT_Test_start_val, MOT_Test_start_par);
		Adress_color(result_ob.pid, PID_Test_start_w1, PID_Test_start_w2, PID_Test_start_cmd, PID_Test_start_val, PID_Test_start_par);
		Adress_color(result_ob.fc, FC_Test_start_w1, FC_Test_start_w2, FC_Test_start_cmd, FC_Test_start_val, FC_Test_start_par);
		Adress_color(result_ob.vlv, VLV_Test_start_w1, VLV_Test_start_w2, VLV_Test_start_cmd, VLV_Test_start_val, VLV_Test_start_par);

		Put_all_data_to_Form(CPU_adr, test);
	}

	private: System::Void Check_button_Click(System::Object^  sender, System::EventArgs^  e) {

		check_result_str result_ob;
		adr_cpu_test_str test_CPU_adr;
		Put_all_data_to_cpu();

		int result = Declare_adress_test(AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max, result_ob, test_CPU_adr);
		Adress_init(result_ob, test_CPU_adr, AI_nr_max, VLV_nr_max, HC_nr_max, FC_nr_max, PID_nr_max, MOT_nr_max);
	}
	private: System::Void Done_button_Click(System::Object^  sender, System::EventArgs^  e) {
		return_value = 0;
		Put_all_data_to_cpu();
		this->Close();
	}
	private: System::Void Cancel_button_Click(System::Object^  sender, System::EventArgs^  e) {
		return_value = -1;
		this->Close();
	}

};
}
