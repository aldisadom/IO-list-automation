#pragma once
#include "config.h"
#include "resource.h"
#include "design.h"
#include "signals.h"
#include "AboutForm.h"
#include "HelpForm.h"
#include "KKS_editForm.h"
#include "objects.h"
#include "Global_Functions.h"
#include "Declare.h"
#include "Instance.h"
#include "IO_declare.h"
#include "tests.h"
#include "Trend_data.h"
#include "Instance_scada.h"

#include <msclr/marshal_cppstd.h>


namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  Design_grid;


	protected:

	protected:

	protected:

	protected:



	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public: System::Windows::Forms::TabControl^  tabControl1;
	private:

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  File_Save;
	private: System::Windows::Forms::ToolStripMenuItem^  File_Load;
	private: System::Windows::Forms::ToolStripMenuItem^  File_Help;
	private: System::Windows::Forms::ToolStripMenuItem^  File_About;
	private: System::Windows::Forms::ToolStripMenuItem^  File_Exit;
	private: System::Windows::Forms::ToolStripMenuItem^  projectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_Design;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_IOcompare;
	private: System::Windows::Forms::ToolStripMenuItem^  cPUSelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_CPU_Beckhoff;


	private: System::Windows::Forms::ToolStripMenuItem^  Project_CPU_800xA;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_CPU_Siemens;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_CPU_Schneider;
	private: System::Windows::Forms::ToolStripMenuItem^  sCADASelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_SCADA_SystemPlatform;
	private: System::Windows::Forms::ToolStripMenuItem^  languageSelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_Language_LT;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_Language_LV;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_Language_EN;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_Language_RU;
	private: System::Windows::Forms::ToolStripMenuItem^  signalsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Signals_KKSedit;
	private: System::Windows::Forms::ToolStripMenuItem^  Signals_FindFunction;
	private: System::Windows::Forms::ToolStripMenuItem^  uniquesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  declareToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  instanceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sCADAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  Uniques_FindUniques;
	private: System::Windows::Forms::ToolStripMenuItem^  Uniques_FindObjects;
	private: System::Windows::Forms::ToolStripMenuItem^  Uniques_CorrectComments;
	private: System::Windows::Forms::ToolStripMenuItem^  Uniques_TransferSignals;
	private: System::Windows::Forms::ToolStripMenuItem^  Declare_Adressing;








	private: System::Windows::Forms::ToolStripMenuItem^  Instance_Generate;
	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_Instances;










	private: System::Windows::Forms::ToolStripMenuItem^  Project_SCADA_WinCC;
	public: System::Windows::Forms::ProgressBar^  progressBaras;


	public: System::Windows::Forms::Label^  Progress_label;
	private: System::Windows::Forms::ToolStripMenuItem^  Project_TransferIO;
	private: System::Windows::Forms::ToolStripMenuItem^  File_SaveALL;
	public: System::Windows::Forms::DataGridView^  Signals_grid;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	public:
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
public: System::Windows::Forms::DataGridView^  Object_grid;
private: System::Windows::Forms::ToolStripMenuItem^  Uniques_FindOperatyv;
private: System::Windows::Forms::ToolStripMenuItem^  File_LoadALL;
private: System::Windows::Forms::ToolStripMenuItem^  Declare_GenerateAdress;

private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
private: System::Windows::Forms::ToolStripMenuItem^  Instance_ShowIO;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
private: System::Windows::Forms::ToolStripMenuItem^  Instance_GenerateIO;
private: System::Windows::Forms::ToolStripMenuItem^  Signals_MultiCPU;
private: System::Windows::Forms::ToolStripMenuItem^  Test_app;
private: System::Windows::Forms::ComboBox^  Filter_1;
private: System::Windows::Forms::ComboBox^  Filter_0;





private: System::Windows::Forms::ComboBox^  Filter_16;


private: System::Windows::Forms::ComboBox^  Filter_15;


private: System::Windows::Forms::ComboBox^  Filter_14;


private: System::Windows::Forms::ComboBox^  Filter_13;


private: System::Windows::Forms::ComboBox^  Filter_12;


private: System::Windows::Forms::ComboBox^  Filter_11;


private: System::Windows::Forms::ComboBox^  Filter_10;


private: System::Windows::Forms::ComboBox^  Filter_9;


private: System::Windows::Forms::ComboBox^  Filter_8;


private: System::Windows::Forms::ComboBox^  Filter_7;



private: System::Windows::Forms::ComboBox^  Filter_6;


private: System::Windows::Forms::ComboBox^  Filter_5;


private: System::Windows::Forms::ComboBox^  Filter_4;


private: System::Windows::Forms::ComboBox^  Filter_3;


private: System::Windows::Forms::ComboBox^  Filter_2;
private: System::Windows::Forms::ComboBox^  Filter_17;
private: System::Windows::Forms::ComboBox^  Filter_18;
private: System::Windows::Forms::ComboBox^  Filter_19;
private: System::Windows::Forms::Button^  Find_button;
private: System::Windows::Forms::TextBox^  Find_text;
private: System::Windows::Forms::TabPage^  tabPage4;
public: System::Windows::Forms::DataGridView^  Trend_data_grid;
private:

private:
private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::Button^  Clear_button;
private: System::Windows::Forms::Button^  Poly_calc_button;
private: System::Windows::Forms::ToolStripMenuItem^  File_ReadCFG;
private: System::Windows::Forms::ToolStripMenuItem^  Gen_tests;
private: System::Windows::Forms::Button^  Plot_button;




public:






private:
public:

public:
private:
	private:
	public:




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->Design_grid = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_Save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_SaveALL = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_Load = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_LoadALL = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_ReadCFG = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->File_Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_About = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Test_app = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Gen_tests = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->File_Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->projectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_Design = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_IOcompare = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_TransferIO = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cPUSelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_CPU_Beckhoff = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_CPU_800xA = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_CPU_Siemens = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_CPU_Schneider = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sCADASelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_SCADA_SystemPlatform = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_SCADA_WinCC = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageSelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_Language_LT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_Language_EN = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_Language_LV = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Project_Language_RU = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Signals_KKSedit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Signals_FindFunction = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Signals_MultiCPU = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uniquesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Uniques_FindUniques = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Uniques_FindObjects = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Uniques_FindOperatyv = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Uniques_CorrectComments = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Uniques_TransferSignals = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->declareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Declare_GenerateAdress = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->Declare_Adressing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Instance_GenerateIO = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Instance_ShowIO = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->Instance_Generate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sCADAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SCADA_Instances = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Signals_grid = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->Object_grid = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->Poly_calc_button = (gcnew System::Windows::Forms::Button());
			this->Clear_button = (gcnew System::Windows::Forms::Button());
			this->Trend_data_grid = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->Filter_0 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_7 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_16 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_6 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_8 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_15 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_5 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_9 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_14 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_4 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_10 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_13 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_3 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_1 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_11 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_12 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_2 = (gcnew System::Windows::Forms::ComboBox());
			this->progressBaras = (gcnew System::Windows::Forms::ProgressBar());
			this->Progress_label = (gcnew System::Windows::Forms::Label());
			this->Filter_17 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_18 = (gcnew System::Windows::Forms::ComboBox());
			this->Filter_19 = (gcnew System::Windows::Forms::ComboBox());
			this->Find_button = (gcnew System::Windows::Forms::Button());
			this->Find_text = (gcnew System::Windows::Forms::TextBox());
			this->Plot_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Design_grid))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Signals_grid))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Object_grid))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Trend_data_grid))->BeginInit();
			this->SuspendLayout();
			// 
			// Design_grid
			// 
			this->Design_grid->AllowUserToResizeRows = false;
			this->Design_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Design_grid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->Design_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Design_grid->Location = System::Drawing::Point(1, 3);
			this->Design_grid->Name = L"Design_grid";
			this->Design_grid->RowHeadersWidth = 10;
			this->Design_grid->Size = System::Drawing::Size(850, 266);
			this->Design_grid->TabIndex = 0;
			this->Design_grid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dataGridView1_CellContentClick);
			this->Design_grid->ColumnWidthChanged += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MainWindow::D_column_width_changed);
			this->Design_grid->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MainWindow::D_scroll);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->fileToolStripMenuItem,
					this->projectToolStripMenuItem, this->signalsToolStripMenuItem, this->uniquesToolStripMenuItem, this->declareToolStripMenuItem,
					this->instanceToolStripMenuItem, this->sCADAToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(861, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"MenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->File_Save,
					this->File_SaveALL, this->File_Load, this->File_LoadALL, this->File_ReadCFG, this->toolStripSeparator1, this->File_Help, this->File_About,
					this->Test_app, this->Gen_tests, this->toolStripSeparator2, this->File_Exit
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// File_Save
			// 
			this->File_Save->Name = L"File_Save";
			this->File_Save->Size = System::Drawing::Size(153, 22);
			this->File_Save->Text = L"Save";
			this->File_Save->Click += gcnew System::EventHandler(this, &MainWindow::File_Save_Click);
			// 
			// File_SaveALL
			// 
			this->File_SaveALL->Name = L"File_SaveALL";
			this->File_SaveALL->Size = System::Drawing::Size(153, 22);
			this->File_SaveALL->Text = L"Save all";
			this->File_SaveALL->Click += gcnew System::EventHandler(this, &MainWindow::File_SaveALL_Click);
			// 
			// File_Load
			// 
			this->File_Load->Name = L"File_Load";
			this->File_Load->Size = System::Drawing::Size(153, 22);
			this->File_Load->Text = L"Load";
			this->File_Load->Click += gcnew System::EventHandler(this, &MainWindow::File_Load_Click);
			// 
			// File_LoadALL
			// 
			this->File_LoadALL->Name = L"File_LoadALL";
			this->File_LoadALL->Size = System::Drawing::Size(153, 22);
			this->File_LoadALL->Text = L"Load all";
			this->File_LoadALL->Click += gcnew System::EventHandler(this, &MainWindow::File_LoadALL_Click);
			// 
			// File_ReadCFG
			// 
			this->File_ReadCFG->Name = L"File_ReadCFG";
			this->File_ReadCFG->Size = System::Drawing::Size(153, 22);
			this->File_ReadCFG->Text = L"Read CFG";
			this->File_ReadCFG->Click += gcnew System::EventHandler(this, &MainWindow::File_ReadCFG_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(150, 6);
			// 
			// File_Help
			// 
			this->File_Help->Name = L"File_Help";
			this->File_Help->Size = System::Drawing::Size(153, 22);
			this->File_Help->Text = L"Help";
			this->File_Help->Click += gcnew System::EventHandler(this, &MainWindow::File_Help_Click);
			// 
			// File_About
			// 
			this->File_About->Name = L"File_About";
			this->File_About->Size = System::Drawing::Size(153, 22);
			this->File_About->Text = L"About";
			this->File_About->Click += gcnew System::EventHandler(this, &MainWindow::File_About_Click);
			// 
			// Test_app
			// 
			this->Test_app->Name = L"Test_app";
			this->Test_app->Size = System::Drawing::Size(153, 22);
			this->Test_app->Text = L"Test_aplication";
			this->Test_app->Click += gcnew System::EventHandler(this, &MainWindow::Test_app_Click);
			// 
			// Gen_tests
			// 
			this->Gen_tests->Name = L"Gen_tests";
			this->Gen_tests->Size = System::Drawing::Size(153, 22);
			this->Gen_tests->Text = L"Generate tests";
			this->Gen_tests->Click += gcnew System::EventHandler(this, &MainWindow::Gen_tests_click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(150, 6);
			// 
			// File_Exit
			// 
			this->File_Exit->Name = L"File_Exit";
			this->File_Exit->Size = System::Drawing::Size(153, 22);
			this->File_Exit->Text = L"Exit";
			this->File_Exit->Click += gcnew System::EventHandler(this, &MainWindow::File_Exit_Click);
			// 
			// projectToolStripMenuItem
			// 
			this->projectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->Project_Design,
					this->Project_IOcompare, this->Project_TransferIO, this->toolStripSeparator3, this->cPUSelectToolStripMenuItem, this->sCADASelectToolStripMenuItem,
					this->languageSelectToolStripMenuItem
			});
			this->projectToolStripMenuItem->Name = L"projectToolStripMenuItem";
			this->projectToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->projectToolStripMenuItem->Text = L"Project";
			// 
			// Project_Design
			// 
			this->Project_Design->Name = L"Project_Design";
			this->Project_Design->Size = System::Drawing::Size(201, 22);
			this->Project_Design->Text = L"Design";
			this->Project_Design->Click += gcnew System::EventHandler(this, &MainWindow::Project_Design_Click);
			// 
			// Project_IOcompare
			// 
			this->Project_IOcompare->BackColor = System::Drawing::SystemColors::Control;
			this->Project_IOcompare->Name = L"Project_IOcompare";
			this->Project_IOcompare->Size = System::Drawing::Size(201, 22);
			this->Project_IOcompare->Text = L"IO compare";
			this->Project_IOcompare->Click += gcnew System::EventHandler(this, &MainWindow::Project_IOcompare_Click);
			// 
			// Project_TransferIO
			// 
			this->Project_TransferIO->Name = L"Project_TransferIO";
			this->Project_TransferIO->Size = System::Drawing::Size(201, 22);
			this->Project_TransferIO->Text = L"Transfer Data To Signals";
			this->Project_TransferIO->Click += gcnew System::EventHandler(this, &MainWindow::Project_TransferIO_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(198, 6);
			// 
			// cPUSelectToolStripMenuItem
			// 
			this->cPUSelectToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->cPUSelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Project_CPU_Beckhoff,
					this->Project_CPU_800xA, this->Project_CPU_Siemens, this->Project_CPU_Schneider
			});
			this->cPUSelectToolStripMenuItem->Name = L"cPUSelectToolStripMenuItem";
			this->cPUSelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->cPUSelectToolStripMenuItem->Text = L"CPU Select";
			// 
			// Project_CPU_Beckhoff
			// 
			this->Project_CPU_Beckhoff->Name = L"Project_CPU_Beckhoff";
			this->Project_CPU_Beckhoff->Size = System::Drawing::Size(126, 22);
			this->Project_CPU_Beckhoff->Text = L"Beckhoff";
			this->Project_CPU_Beckhoff->Click += gcnew System::EventHandler(this, &MainWindow::Project_CPU_Beckhoff_Click);
			// 
			// Project_CPU_800xA
			// 
			this->Project_CPU_800xA->Name = L"Project_CPU_800xA";
			this->Project_CPU_800xA->Size = System::Drawing::Size(126, 22);
			this->Project_CPU_800xA->Text = L"800xA";
			this->Project_CPU_800xA->Click += gcnew System::EventHandler(this, &MainWindow::Project_CPU_800xA_Click);
			// 
			// Project_CPU_Siemens
			// 
			this->Project_CPU_Siemens->Name = L"Project_CPU_Siemens";
			this->Project_CPU_Siemens->Size = System::Drawing::Size(126, 22);
			this->Project_CPU_Siemens->Text = L"Siemens";
			this->Project_CPU_Siemens->Click += gcnew System::EventHandler(this, &MainWindow::Project_CPU_Siemens_Click);
			// 
			// Project_CPU_Schneider
			// 
			this->Project_CPU_Schneider->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Project_CPU_Schneider->Name = L"Project_CPU_Schneider";
			this->Project_CPU_Schneider->Size = System::Drawing::Size(126, 22);
			this->Project_CPU_Schneider->Text = L"Schneider";
			this->Project_CPU_Schneider->Click += gcnew System::EventHandler(this, &MainWindow::Project_CPU_Schneider_Click);
			// 
			// sCADASelectToolStripMenuItem
			// 
			this->sCADASelectToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->sCADASelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Project_SCADA_SystemPlatform,
					this->Project_SCADA_WinCC
			});
			this->sCADASelectToolStripMenuItem->Name = L"sCADASelectToolStripMenuItem";
			this->sCADASelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->sCADASelectToolStripMenuItem->Text = L"SCADA Select";
			// 
			// Project_SCADA_SystemPlatform
			// 
			this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Project_SCADA_SystemPlatform->Name = L"Project_SCADA_SystemPlatform";
			this->Project_SCADA_SystemPlatform->Size = System::Drawing::Size(161, 22);
			this->Project_SCADA_SystemPlatform->Text = L"System Platform";
			this->Project_SCADA_SystemPlatform->Click += gcnew System::EventHandler(this, &MainWindow::Project_SCADA_SystemPlatform_Click);
			// 
			// Project_SCADA_WinCC
			// 
			this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Project_SCADA_WinCC->Name = L"Project_SCADA_WinCC";
			this->Project_SCADA_WinCC->Size = System::Drawing::Size(161, 22);
			this->Project_SCADA_WinCC->Text = L"WinCC";
			this->Project_SCADA_WinCC->Click += gcnew System::EventHandler(this, &MainWindow::Project_SCADA_WinCC_Click);
			// 
			// languageSelectToolStripMenuItem
			// 
			this->languageSelectToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->languageSelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Project_Language_LT,
					this->Project_Language_EN, this->Project_Language_LV, this->Project_Language_RU
			});
			this->languageSelectToolStripMenuItem->Name = L"languageSelectToolStripMenuItem";
			this->languageSelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->languageSelectToolStripMenuItem->Text = L"Language Select";
			// 
			// Project_Language_LT
			// 
			this->Project_Language_LT->Name = L"Project_Language_LT";
			this->Project_Language_LT->Size = System::Drawing::Size(89, 22);
			this->Project_Language_LT->Text = L"LT";
			this->Project_Language_LT->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_LT_Click);
			// 
			// Project_Language_EN
			// 
			this->Project_Language_EN->Name = L"Project_Language_EN";
			this->Project_Language_EN->Size = System::Drawing::Size(89, 22);
			this->Project_Language_EN->Text = L"EN";
			this->Project_Language_EN->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_EN_Click);
			// 
			// Project_Language_LV
			// 
			this->Project_Language_LV->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Project_Language_LV->Name = L"Project_Language_LV";
			this->Project_Language_LV->Size = System::Drawing::Size(89, 22);
			this->Project_Language_LV->Text = L"LV";
			this->Project_Language_LV->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_LV_Click);
			// 
			// Project_Language_RU
			// 
			this->Project_Language_RU->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Project_Language_RU->Name = L"Project_Language_RU";
			this->Project_Language_RU->Size = System::Drawing::Size(89, 22);
			this->Project_Language_RU->Text = L"RU";
			this->Project_Language_RU->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_RU_Click);
			// 
			// signalsToolStripMenuItem
			// 
			this->signalsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Signals_KKSedit,
					this->Signals_FindFunction, this->Signals_MultiCPU
			});
			this->signalsToolStripMenuItem->Name = L"signalsToolStripMenuItem";
			this->signalsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->signalsToolStripMenuItem->Text = L"Signals";
			// 
			// Signals_KKSedit
			// 
			this->Signals_KKSedit->BackColor = System::Drawing::SystemColors::Control;
			this->Signals_KKSedit->Name = L"Signals_KKSedit";
			this->Signals_KKSedit->Size = System::Drawing::Size(145, 22);
			this->Signals_KKSedit->Text = L"KKS edit";
			this->Signals_KKSedit->Click += gcnew System::EventHandler(this, &MainWindow::Signals_KKSedit_Click);
			// 
			// Signals_FindFunction
			// 
			this->Signals_FindFunction->BackColor = System::Drawing::SystemColors::Control;
			this->Signals_FindFunction->Name = L"Signals_FindFunction";
			this->Signals_FindFunction->Size = System::Drawing::Size(145, 22);
			this->Signals_FindFunction->Text = L"Find function";
			this->Signals_FindFunction->Click += gcnew System::EventHandler(this, &MainWindow::Signals_FindFunction_Click);
			// 
			// Signals_MultiCPU
			// 
			this->Signals_MultiCPU->Name = L"Signals_MultiCPU";
			this->Signals_MultiCPU->Size = System::Drawing::Size(145, 22);
			this->Signals_MultiCPU->Text = L"Multi CPU";
			this->Signals_MultiCPU->Click += gcnew System::EventHandler(this, &MainWindow::Signals_MultiCPU_Click);
			// 
			// uniquesToolStripMenuItem
			// 
			this->uniquesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->Uniques_FindUniques,
					this->Uniques_FindObjects, this->Uniques_FindOperatyv, this->Uniques_CorrectComments, this->Uniques_TransferSignals
			});
			this->uniquesToolStripMenuItem->Name = L"uniquesToolStripMenuItem";
			this->uniquesToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->uniquesToolStripMenuItem->Text = L"Uniques";
			// 
			// Uniques_FindUniques
			// 
			this->Uniques_FindUniques->BackColor = System::Drawing::SystemColors::Control;
			this->Uniques_FindUniques->Name = L"Uniques_FindUniques";
			this->Uniques_FindUniques->Size = System::Drawing::Size(198, 22);
			this->Uniques_FindUniques->Text = L"Find Uniques";
			this->Uniques_FindUniques->Click += gcnew System::EventHandler(this, &MainWindow::Uniques_FindUniques_Click);
			// 
			// Uniques_FindObjects
			// 
			this->Uniques_FindObjects->BackColor = System::Drawing::SystemColors::Control;
			this->Uniques_FindObjects->Name = L"Uniques_FindObjects";
			this->Uniques_FindObjects->Size = System::Drawing::Size(198, 22);
			this->Uniques_FindObjects->Text = L"Find Objects";
			this->Uniques_FindObjects->Click += gcnew System::EventHandler(this, &MainWindow::Uniques_FindObjects_Click);
			// 
			// Uniques_FindOperatyv
			// 
			this->Uniques_FindOperatyv->Name = L"Uniques_FindOperatyv";
			this->Uniques_FindOperatyv->Size = System::Drawing::Size(198, 22);
			this->Uniques_FindOperatyv->Text = L"Find Operatyv";
			this->Uniques_FindOperatyv->Click += gcnew System::EventHandler(this, &MainWindow::Uniques_FindOperatyv_Click);
			// 
			// Uniques_CorrectComments
			// 
			this->Uniques_CorrectComments->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Uniques_CorrectComments->Name = L"Uniques_CorrectComments";
			this->Uniques_CorrectComments->Size = System::Drawing::Size(198, 22);
			this->Uniques_CorrectComments->Text = L"Correct Comments";
			this->Uniques_CorrectComments->Click += gcnew System::EventHandler(this, &MainWindow::Uniques_CorrectComments_Click);
			// 
			// Uniques_TransferSignals
			// 
			this->Uniques_TransferSignals->BackColor = System::Drawing::SystemColors::Control;
			this->Uniques_TransferSignals->Name = L"Uniques_TransferSignals";
			this->Uniques_TransferSignals->Size = System::Drawing::Size(198, 22);
			this->Uniques_TransferSignals->Text = L"Transfer Data to Signals";
			this->Uniques_TransferSignals->Click += gcnew System::EventHandler(this, &MainWindow::Uniques_TransferSignals_Click);
			// 
			// declareToolStripMenuItem
			// 
			this->declareToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Declare_GenerateAdress,
					this->toolStripSeparator4, this->Declare_Adressing
			});
			this->declareToolStripMenuItem->Name = L"declareToolStripMenuItem";
			this->declareToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->declareToolStripMenuItem->Text = L"Declare";
			// 
			// Declare_GenerateAdress
			// 
			this->Declare_GenerateAdress->Name = L"Declare_GenerateAdress";
			this->Declare_GenerateAdress->Size = System::Drawing::Size(166, 22);
			this->Declare_GenerateAdress->Text = L"Generate adress";
			this->Declare_GenerateAdress->Click += gcnew System::EventHandler(this, &MainWindow::Declare_GenerateAdress_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(163, 6);
			// 
			// Declare_Adressing
			// 
			this->Declare_Adressing->BackColor = System::Drawing::SystemColors::Control;
			this->Declare_Adressing->Name = L"Declare_Adressing";
			this->Declare_Adressing->Size = System::Drawing::Size(166, 22);
			this->Declare_Adressing->Text = L"Declare adressing";
			this->Declare_Adressing->Click += gcnew System::EventHandler(this, &MainWindow::Declare_Adressing_Click);
			// 
			// instanceToolStripMenuItem
			// 
			this->instanceToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Instance_GenerateIO,
					this->Instance_ShowIO, this->toolStripSeparator5, this->Instance_Generate
			});
			this->instanceToolStripMenuItem->Name = L"instanceToolStripMenuItem";
			this->instanceToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->instanceToolStripMenuItem->Text = L"Instance";
			// 
			// Instance_GenerateIO
			// 
			this->Instance_GenerateIO->Name = L"Instance_GenerateIO";
			this->Instance_GenerateIO->Size = System::Drawing::Size(173, 22);
			this->Instance_GenerateIO->Text = L"Generate IO";
			this->Instance_GenerateIO->Click += gcnew System::EventHandler(this, &MainWindow::Instance_GenerateIO_Click);
			// 
			// Instance_ShowIO
			// 
			this->Instance_ShowIO->Name = L"Instance_ShowIO";
			this->Instance_ShowIO->Size = System::Drawing::Size(173, 22);
			this->Instance_ShowIO->Text = L"Show IO";
			this->Instance_ShowIO->Click += gcnew System::EventHandler(this, &MainWindow::Instance_ShowIO_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(170, 6);
			// 
			// Instance_Generate
			// 
			this->Instance_Generate->BackColor = System::Drawing::SystemColors::Control;
			this->Instance_Generate->Name = L"Instance_Generate";
			this->Instance_Generate->Size = System::Drawing::Size(173, 22);
			this->Instance_Generate->Text = L"Generate instances";
			this->Instance_Generate->Click += gcnew System::EventHandler(this, &MainWindow::Instance_Generate_Click);
			// 
			// sCADAToolStripMenuItem
			// 
			this->sCADAToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->SCADA_Instances });
			this->sCADAToolStripMenuItem->Name = L"sCADAToolStripMenuItem";
			this->sCADAToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->sCADAToolStripMenuItem->Text = L"SCADA";
			// 
			// SCADA_Instances
			// 
			this->SCADA_Instances->BackColor = System::Drawing::Color::White;
			this->SCADA_Instances->Name = L"SCADA_Instances";
			this->SCADA_Instances->Size = System::Drawing::Size(123, 22);
			this->SCADA_Instances->Text = L"Instances";
			this->SCADA_Instances->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_Instances_Click);
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
			this->tabControl1->Location = System::Drawing::Point(0, 57);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(861, 297);
			this->tabControl1->TabIndex = 2;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::Grid_changed_index);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Design_grid);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(853, 271);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Design";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->Signals_grid);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(853, 271);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"IO_list";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Signals_grid
			// 
			this->Signals_grid->AllowUserToResizeRows = false;
			this->Signals_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Signals_grid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->Signals_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Signals_grid->Location = System::Drawing::Point(1, 3);
			this->Signals_grid->Name = L"Signals_grid";
			this->Signals_grid->RowHeadersWidth = 10;
			this->Signals_grid->Size = System::Drawing::Size(850, 269);
			this->Signals_grid->TabIndex = 1;
			this->Signals_grid->ColumnWidthChanged += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MainWindow::S_column_width_changed);
			this->Signals_grid->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MainWindow::S_scroll);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->Object_grid);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(853, 271);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Objects";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// Object_grid
			// 
			this->Object_grid->AllowUserToResizeRows = false;
			this->Object_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Object_grid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->Object_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Object_grid->Location = System::Drawing::Point(1, 3);
			this->Object_grid->Name = L"Object_grid";
			this->Object_grid->RowHeadersWidth = 10;
			this->Object_grid->Size = System::Drawing::Size(850, 268);
			this->Object_grid->TabIndex = 1;
			this->Object_grid->ColumnWidthChanged += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MainWindow::O_column_width_changed);
			this->Object_grid->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MainWindow::O_scroll);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->Plot_button);
			this->tabPage4->Controls->Add(this->Poly_calc_button);
			this->tabPage4->Controls->Add(this->Clear_button);
			this->tabPage4->Controls->Add(this->Trend_data_grid);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(853, 271);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Trend data";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// Poly_calc_button
			// 
			this->Poly_calc_button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Poly_calc_button->Location = System::Drawing::Point(3, 60);
			this->Poly_calc_button->Name = L"Poly_calc_button";
			this->Poly_calc_button->Size = System::Drawing::Size(45, 23);
			this->Poly_calc_button->TabIndex = 22;
			this->Poly_calc_button->Text = L"Poly";
			this->Poly_calc_button->UseVisualStyleBackColor = true;
			this->Poly_calc_button->Click += gcnew System::EventHandler(this, &MainWindow::Poly_calc_button_Click);
			// 
			// Clear_button
			// 
			this->Clear_button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Clear_button->Location = System::Drawing::Point(3, 21);
			this->Clear_button->Name = L"Clear_button";
			this->Clear_button->Size = System::Drawing::Size(45, 23);
			this->Clear_button->TabIndex = 21;
			this->Clear_button->Text = L"Clear";
			this->Clear_button->UseVisualStyleBackColor = true;
			this->Clear_button->Click += gcnew System::EventHandler(this, &MainWindow::Clear_button_Click);
			// 
			// Trend_data_grid
			// 
			this->Trend_data_grid->AllowUserToResizeRows = false;
			this->Trend_data_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Trend_data_grid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->Trend_data_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Trend_data_grid->Location = System::Drawing::Point(54, 1);
			this->Trend_data_grid->Name = L"Trend_data_grid";
			this->Trend_data_grid->RowHeadersWidth = 10;
			this->Trend_data_grid->Size = System::Drawing::Size(797, 268);
			this->Trend_data_grid->TabIndex = 2;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(853, 271);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"PID calculation";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// Filter_0
			// 
			this->Filter_0->FormattingEnabled = true;
			this->Filter_0->Location = System::Drawing::Point(5, 27);
			this->Filter_0->Name = L"Filter_0";
			this->Filter_0->Size = System::Drawing::Size(36, 21);
			this->Filter_0->TabIndex = 17;
			this->Filter_0->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_0);
			this->Filter_0->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_0);
			this->Filter_0->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_0);
			// 
			// Filter_7
			// 
			this->Filter_7->FormattingEnabled = true;
			this->Filter_7->Location = System::Drawing::Point(298, 27);
			this->Filter_7->Name = L"Filter_7";
			this->Filter_7->Size = System::Drawing::Size(36, 21);
			this->Filter_7->TabIndex = 7;
			this->Filter_7->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_7);
			this->Filter_7->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_7);
			this->Filter_7->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_7);
			// 
			// Filter_16
			// 
			this->Filter_16->FormattingEnabled = true;
			this->Filter_16->Location = System::Drawing::Point(676, 27);
			this->Filter_16->Name = L"Filter_16";
			this->Filter_16->Size = System::Drawing::Size(36, 21);
			this->Filter_16->TabIndex = 16;
			this->Filter_16->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_16);
			this->Filter_16->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_16);
			this->Filter_16->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_16);
			// 
			// Filter_6
			// 
			this->Filter_6->FormattingEnabled = true;
			this->Filter_6->Location = System::Drawing::Point(256, 27);
			this->Filter_6->Name = L"Filter_6";
			this->Filter_6->Size = System::Drawing::Size(36, 21);
			this->Filter_6->TabIndex = 6;
			this->Filter_6->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_6);
			this->Filter_6->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_6);
			this->Filter_6->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_6);
			// 
			// Filter_8
			// 
			this->Filter_8->FormattingEnabled = true;
			this->Filter_8->Location = System::Drawing::Point(340, 27);
			this->Filter_8->Name = L"Filter_8";
			this->Filter_8->Size = System::Drawing::Size(36, 21);
			this->Filter_8->TabIndex = 8;
			this->Filter_8->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_8);
			this->Filter_8->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_8);
			this->Filter_8->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_8);
			// 
			// Filter_15
			// 
			this->Filter_15->FormattingEnabled = true;
			this->Filter_15->Location = System::Drawing::Point(634, 27);
			this->Filter_15->Name = L"Filter_15";
			this->Filter_15->Size = System::Drawing::Size(36, 21);
			this->Filter_15->TabIndex = 15;
			this->Filter_15->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_15);
			this->Filter_15->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_15);
			this->Filter_15->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_15);
			// 
			// Filter_5
			// 
			this->Filter_5->FormattingEnabled = true;
			this->Filter_5->Location = System::Drawing::Point(214, 27);
			this->Filter_5->Name = L"Filter_5";
			this->Filter_5->Size = System::Drawing::Size(36, 21);
			this->Filter_5->TabIndex = 5;
			this->Filter_5->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_5);
			this->Filter_5->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_5);
			this->Filter_5->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_5);
			// 
			// Filter_9
			// 
			this->Filter_9->FormattingEnabled = true;
			this->Filter_9->Location = System::Drawing::Point(382, 27);
			this->Filter_9->Name = L"Filter_9";
			this->Filter_9->Size = System::Drawing::Size(36, 21);
			this->Filter_9->TabIndex = 9;
			this->Filter_9->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_9);
			this->Filter_9->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_9);
			this->Filter_9->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_9);
			// 
			// Filter_14
			// 
			this->Filter_14->FormattingEnabled = true;
			this->Filter_14->Location = System::Drawing::Point(592, 27);
			this->Filter_14->Name = L"Filter_14";
			this->Filter_14->Size = System::Drawing::Size(36, 21);
			this->Filter_14->TabIndex = 14;
			this->Filter_14->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_14);
			this->Filter_14->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_14);
			this->Filter_14->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_14);
			// 
			// Filter_4
			// 
			this->Filter_4->FormattingEnabled = true;
			this->Filter_4->Location = System::Drawing::Point(172, 27);
			this->Filter_4->Name = L"Filter_4";
			this->Filter_4->Size = System::Drawing::Size(36, 21);
			this->Filter_4->TabIndex = 4;
			this->Filter_4->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_4);
			this->Filter_4->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_4);
			this->Filter_4->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_4);
			// 
			// Filter_10
			// 
			this->Filter_10->FormattingEnabled = true;
			this->Filter_10->Location = System::Drawing::Point(424, 27);
			this->Filter_10->Name = L"Filter_10";
			this->Filter_10->Size = System::Drawing::Size(36, 21);
			this->Filter_10->TabIndex = 10;
			this->Filter_10->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_10);
			this->Filter_10->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_10);
			this->Filter_10->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_10);
			// 
			// Filter_13
			// 
			this->Filter_13->FormattingEnabled = true;
			this->Filter_13->Location = System::Drawing::Point(550, 27);
			this->Filter_13->Name = L"Filter_13";
			this->Filter_13->Size = System::Drawing::Size(36, 21);
			this->Filter_13->TabIndex = 13;
			this->Filter_13->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_13);
			this->Filter_13->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_13);
			this->Filter_13->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_13);
			// 
			// Filter_3
			// 
			this->Filter_3->FormattingEnabled = true;
			this->Filter_3->Location = System::Drawing::Point(130, 27);
			this->Filter_3->Name = L"Filter_3";
			this->Filter_3->Size = System::Drawing::Size(36, 21);
			this->Filter_3->TabIndex = 3;
			this->Filter_3->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_3);
			this->Filter_3->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_3);
			this->Filter_3->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_3);
			// 
			// Filter_1
			// 
			this->Filter_1->FormattingEnabled = true;
			this->Filter_1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"asd", L"sdf" });
			this->Filter_1->Location = System::Drawing::Point(46, 27);
			this->Filter_1->Name = L"Filter_1";
			this->Filter_1->Size = System::Drawing::Size(36, 21);
			this->Filter_1->TabIndex = 1;
			this->Filter_1->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_1);
			this->Filter_1->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_1);
			this->Filter_1->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_1);
			// 
			// Filter_11
			// 
			this->Filter_11->FormattingEnabled = true;
			this->Filter_11->Location = System::Drawing::Point(466, 27);
			this->Filter_11->Name = L"Filter_11";
			this->Filter_11->Size = System::Drawing::Size(36, 21);
			this->Filter_11->TabIndex = 11;
			this->Filter_11->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_11);
			this->Filter_11->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_11);
			this->Filter_11->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_11);
			// 
			// Filter_12
			// 
			this->Filter_12->FormattingEnabled = true;
			this->Filter_12->Location = System::Drawing::Point(508, 27);
			this->Filter_12->Name = L"Filter_12";
			this->Filter_12->Size = System::Drawing::Size(36, 21);
			this->Filter_12->TabIndex = 12;
			this->Filter_12->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_12);
			this->Filter_12->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_12);
			this->Filter_12->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_12);
			// 
			// Filter_2
			// 
			this->Filter_2->FormattingEnabled = true;
			this->Filter_2->Location = System::Drawing::Point(88, 27);
			this->Filter_2->Name = L"Filter_2";
			this->Filter_2->Size = System::Drawing::Size(36, 21);
			this->Filter_2->TabIndex = 2;
			this->Filter_2->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_2);
			this->Filter_2->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_2);
			this->Filter_2->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_2);
			// 
			// progressBaras
			// 
			this->progressBaras->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBaras->Location = System::Drawing::Point(0, 353);
			this->progressBaras->Name = L"progressBaras";
			this->progressBaras->Size = System::Drawing::Size(861, 18);
			this->progressBaras->TabIndex = 3;
			this->progressBaras->Visible = false;
			// 
			// Progress_label
			// 
			this->Progress_label->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Progress_label->AutoSize = true;
			this->Progress_label->BackColor = System::Drawing::Color::Transparent;
			this->Progress_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Progress_label->Location = System::Drawing::Point(419, 356);
			this->Progress_label->Name = L"Progress_label";
			this->Progress_label->Size = System::Drawing::Size(35, 13);
			this->Progress_label->TabIndex = 4;
			this->Progress_label->Text = L"label1";
			this->Progress_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Progress_label->UseMnemonic = false;
			this->Progress_label->Visible = false;
			// 
			// Filter_17
			// 
			this->Filter_17->FormattingEnabled = true;
			this->Filter_17->Location = System::Drawing::Point(718, 27);
			this->Filter_17->Name = L"Filter_17";
			this->Filter_17->Size = System::Drawing::Size(36, 21);
			this->Filter_17->TabIndex = 18;
			this->Filter_17->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_17);
			this->Filter_17->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_17);
			this->Filter_17->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_17);
			// 
			// Filter_18
			// 
			this->Filter_18->FormattingEnabled = true;
			this->Filter_18->Location = System::Drawing::Point(760, 27);
			this->Filter_18->Name = L"Filter_18";
			this->Filter_18->Size = System::Drawing::Size(36, 21);
			this->Filter_18->TabIndex = 19;
			this->Filter_18->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_18);
			this->Filter_18->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_18);
			this->Filter_18->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_18);
			// 
			// Filter_19
			// 
			this->Filter_19->FormattingEnabled = true;
			this->Filter_19->Location = System::Drawing::Point(802, 27);
			this->Filter_19->Name = L"Filter_19";
			this->Filter_19->Size = System::Drawing::Size(36, 21);
			this->Filter_19->TabIndex = 20;
			this->Filter_19->DropDown += gcnew System::EventHandler(this, &MainWindow::Filter_Drop_down_19);
			this->Filter_19->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_Changed_Text_19);
			this->Filter_19->Click += gcnew System::EventHandler(this, &MainWindow::Filter_click_19);
			// 
			// Find_button
			// 
			this->Find_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Find_button->Location = System::Drawing::Point(779, 54);
			this->Find_button->Name = L"Find_button";
			this->Find_button->Size = System::Drawing::Size(75, 23);
			this->Find_button->TabIndex = 1;
			this->Find_button->Text = L"Find";
			this->Find_button->UseVisualStyleBackColor = true;
			this->Find_button->Click += gcnew System::EventHandler(this, &MainWindow::Find_button_Click);
			// 
			// Find_text
			// 
			this->Find_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Find_text->Location = System::Drawing::Point(618, 54);
			this->Find_text->Name = L"Find_text";
			this->Find_text->Size = System::Drawing::Size(154, 20);
			this->Find_text->TabIndex = 1;
			this->Find_text->Click += gcnew System::EventHandler(this, &MainWindow::Find_text_Click);
			this->Find_text->TextChanged += gcnew System::EventHandler(this, &MainWindow::Filter_click_13);
			// 
			// Plot_button
			// 
			this->Plot_button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Plot_button->Location = System::Drawing::Point(3, 112);
			this->Plot_button->Name = L"Plot_button";
			this->Plot_button->Size = System::Drawing::Size(45, 23);
			this->Plot_button->TabIndex = 23;
			this->Plot_button->Text = L"Plot";
			this->Plot_button->UseVisualStyleBackColor = true;
			this->Plot_button->Click += gcnew System::EventHandler(this, &MainWindow::Plot_button_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(861, 371);
			this->Controls->Add(this->Find_text);
			this->Controls->Add(this->Find_button);
			this->Controls->Add(this->Filter_19);
			this->Controls->Add(this->Filter_18);
			this->Controls->Add(this->Filter_17);
			this->Controls->Add(this->Filter_0);
			this->Controls->Add(this->Progress_label);
			this->Controls->Add(this->progressBaras);
			this->Controls->Add(this->Filter_7);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->Filter_16);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->Filter_6);
			this->Controls->Add(this->Filter_1);
			this->Controls->Add(this->Filter_8);
			this->Controls->Add(this->Filter_2);
			this->Controls->Add(this->Filter_15);
			this->Controls->Add(this->Filter_12);
			this->Controls->Add(this->Filter_5);
			this->Controls->Add(this->Filter_11);
			this->Controls->Add(this->Filter_9);
			this->Controls->Add(this->Filter_3);
			this->Controls->Add(this->Filter_14);
			this->Controls->Add(this->Filter_13);
			this->Controls->Add(this->Filter_4);
			this->Controls->Add(this->Filter_10);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"IO_list_manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Design_grid))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Signals_grid))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Object_grid))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Trend_data_grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void KeyDown_event(Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		// Delete function
		if ((e->KeyCode == Keys::Delete) || (e->KeyCode == Keys::Back))
		{
			int index_function = this->tabControl1->SelectedIndex;
			System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
			if (grid->SelectedCells->Count > 1)
			{
				for (int i = 0; i < (grid->SelectedCells->Count); i++)
				{
					grid->SelectedCells[i]->Value = L"";
				}
			}
		}// Paste function
		else if ((e->Modifiers == Keys::Control) && (e->KeyCode == Keys::V))
		{
			int index_function = this->tabControl1->SelectedIndex;
			System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);
			if (grid->SelectedCells->Count > 0)
			{
				Global_paste(Global_function_txt(index_function,lang), grid);
			}
			this->Update();
		}
	}

	public: void Main_init(void)
	{
		switch (parameters.Language)
		{
		case LT_index:	this->Project_Language_LT->BackColor = System::Drawing::Color::Aqua;;
			break;
		case LV_index:	this->Project_Language_LV->BackColor = System::Drawing::Color::Aqua;;
			break;
		case EN_index:	this->Project_Language_EN->BackColor = System::Drawing::Color::Aqua;;
			break;
		case RU_index:	this->Project_Language_RU->BackColor = System::Drawing::Color::Aqua;;
			break;
		}

		switch (parameters.CPU)
		{
		case Beckhoff_index:	this->Project_CPU_Beckhoff->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Siemens_index:	this->Project_CPU_Siemens->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Schneider_index:	this->Project_CPU_Schneider->BackColor = System::Drawing::Color::Aqua;;
			break;
		case ABB_800xA_index:	this->Project_CPU_800xA->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
		

		switch (parameters.SCADA)
		{
		case System_platform_index:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC_index:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}

		this->KeyDown += gcnew KeyEventHandler(this, &MainWindow::KeyDown_event);
/*
		signals.valid_entries = 1;
		project.valid_entries = 1;
		objects.valid_entries = 1;
		Trend_data.valid_entries = 1999;

		signals.data.resize(2);
		project.data.resize(2);
		objects.data.resize(2);
		Trend_data.data.resize(2001);
*/

		Global_get_width_list(Design_grid_index, project.number_collums, project.collumn_with);
		Global_get_width_list(Signals_grid_index, signals.number_collums, signals.collumn_with);
		Global_get_width_list(Objects_grid_index, objects.number_collums, objects.collumn_with);
		Global_get_width_list(Trend_data_grid_index, Trend_data.number_collums, Trend_data.collumn_with);

		

		Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
		Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);
		Global_put_data_listview(Trend_data_grid_index, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.column_name_EN, Trend_data.column_name_LT, Trend_data.collumn_with);

		int result = Global_trend_data_check(Max_Trend_data);


		this->tabControl1->SelectedIndex = Design_grid_index;
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int a = 0;
	}

			 //menu file
//function done
	private: System::Void File_Save_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);


		int index_function = this->tabControl1->SelectedIndex;
		
		Global_choose_save(index_function, false, L" ");
	}
//function done
	private: System::Void File_SaveALL_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		
		sfd->Filter = "Save document |*.psave;*.osave;*.ssave";

		sfd->FileName = "";
		std::wstring file_name;
		
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			file_name = system_string_to_wstring(sfd->FileName);
			std::wstring extension;
			
			int a = -1;
			bool continue_save = true;
			a = file_name.find_last_of(L".");

			if (a > 0)
			{
				continue_save = false;
				extension = file_name.substr(a + 2);
				if (extension.compare(L"save") >= 0)
				{
					file_name = file_name.substr(0, a);
					continue_save = true;
				}
			}

			Global_choose_save(Design_grid_index, false, file_name);
			Global_choose_save(Signals_grid_index, false, file_name);
			Global_choose_save(Objects_grid_index, false, file_name);
		}
		else
		{
			wstring texts = button_text;
			texts.append(error_separator);
			texts.append(str.Error.canceled_selection.s[lang]);
			err_write_show(texts);
		}
				
	}
//function done
	private: System::Void File_Load_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		int index_function = this->tabControl1->SelectedIndex;
			
		Global_choose_Load(index_function,L" ");			
	}

	private: System::Void File_LoadALL_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		OpenFileDialog^ importfile = gcnew OpenFileDialog();
		importfile->Filter = "Load document |*.psave;*.osave;*.ssave";
		importfile->FileName = "";

		if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			std::wstring file_name;
			std::wstring extension;

			file_name = system_string_to_wstring(importfile->FileName);
			int a = -1;
			int b = 0;
			bool continue_load = true;
			a = file_name.find_last_of(L".");			

			if (a > 0)
			{
				continue_load = false;
				extension = file_name.substr(a + 2);
				if (extension.compare(L"save") >=0)
				{
					file_name = file_name.substr(0, a);
					continue_load = true;				
				}
			}

			if (continue_load)
			{
				Global_choose_Load(Design_grid_index, file_name);
				Global_choose_Load(Signals_grid_index, file_name);
				Global_choose_Load(Objects_grid_index, file_name);
			}			
		}
		else
		{
			wstring texts = button_text;
			texts.append(error_separator);
			texts.append(str.Error.canceled_selection.s[lang]);
			err_write_show(texts);
		}
	}
//function done
	private: System::Void File_Help_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		IOlistautomation::HelpForm helpas;
		helpas.ShowDialog();
	}
//function done
	private: System::Void File_About_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		IOlistautomation::AboutForm about;
		about.ShowDialog();
	}
//function done
	private: System::Void Test_app_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		Test_All(false);
	}
//function done
	private: System::Void File_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		wstring texts = str.Info.exit_aplication.s[lang];
		info_write(texts);
		Application::Exit();
	}

			 //menu Project
//function done
	private: System::Void Project_Design_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		if (Project_read_data(FALSE,L" ", project) == 0)
		{
			Signals_get_data_design();
		}

	}
//function done
	private: System::Void Project_IOcompare_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		Project_compare_data(L" ");
	}
//function done
	private: System::Void Project_TransferIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Signals_get_data_design();
	}
//function done
	private: System::Void Project_CPU_Beckhoff_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		this->Project_CPU_Beckhoff->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Siemens->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Schneider->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_800xA->BackColor = System::Drawing::SystemColors::Control;

		parameters.CPU = Beckhoff_index;
		switch (parameters.CPU)
		{
		case Beckhoff_index:	this->Project_CPU_Beckhoff->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Siemens_index:	this->Project_CPU_Siemens->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Schneider_index:	this->Project_CPU_Schneider->BackColor = System::Drawing::Color::Aqua;;
			break;
		case ABB_800xA_index:	this->Project_CPU_800xA->BackColor = System::Drawing::Color::Aqua;;
			break;
		}

	}
//function done
	private: System::Void Project_CPU_800xA_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		this->Project_CPU_Beckhoff->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Siemens->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Schneider->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_800xA->BackColor = System::Drawing::SystemColors::Control;

		parameters.CPU = ABB_800xA_index;
		switch (parameters.CPU)
		{
		case Beckhoff_index:	this->Project_CPU_Beckhoff->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Siemens_index:	this->Project_CPU_Siemens->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Schneider_index:	this->Project_CPU_Schneider->BackColor = System::Drawing::Color::Aqua;;
			break;
		case ABB_800xA_index:	this->Project_CPU_800xA->BackColor = System::Drawing::Color::Aqua;;
			break;
		}		
	}
//function done
	private: System::Void Project_CPU_Siemens_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		this->Project_CPU_Beckhoff->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Siemens->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Schneider->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_800xA->BackColor = System::Drawing::SystemColors::Control;

		parameters.CPU = Siemens_index;
		switch (parameters.CPU)
		{
		case Beckhoff_index:	this->Project_CPU_Beckhoff->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Siemens_index:	this->Project_CPU_Siemens->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Schneider_index:	this->Project_CPU_Schneider->BackColor = System::Drawing::Color::Aqua;;
			break;
		case ABB_800xA_index:	this->Project_CPU_800xA->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_CPU_Schneider_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		
		this->Project_CPU_Beckhoff->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Siemens->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_Schneider->BackColor = System::Drawing::SystemColors::Control;
		this->Project_CPU_800xA->BackColor = System::Drawing::SystemColors::Control;

		parameters.CPU = Schneider_index;
		switch (parameters.CPU)
		{
		case Beckhoff_index:	this->Project_CPU_Beckhoff->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Siemens_index:	this->Project_CPU_Siemens->BackColor = System::Drawing::Color::Aqua;;
			break;
		case Schneider_index:	this->Project_CPU_Schneider->BackColor = System::Drawing::Color::Aqua;;
			break;
		case ABB_800xA_index:	this->Project_CPU_800xA->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_SCADA_SystemPlatform_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::SystemColors::Control;
		this->Project_SCADA_WinCC->BackColor = System::Drawing::SystemColors::Control;

		parameters.SCADA = System_platform_index;
		switch (parameters.SCADA)
		{
		case System_platform_index:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC_index:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_SCADA_WinCC_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::SystemColors::Control;
		this->Project_SCADA_WinCC->BackColor = System::Drawing::SystemColors::Control;

		parameters.SCADA = WinCC_index;
		switch (parameters.SCADA)
		{
		case System_platform_index:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC_index:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_Language_LT_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		
		learn = {};
		this->Project_Language_LT->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_LV->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_EN->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_RU->BackColor = System::Drawing::SystemColors::Control;

		parameters.Language = LT_index;
		switch (parameters.Language)
		{
		case LT_index:	this->Project_Language_LT->BackColor = System::Drawing::Color::Aqua;;
			break;
		case LV_index:	this->Project_Language_LV->BackColor = System::Drawing::Color::Aqua;;
			break;
		case EN_index:	this->Project_Language_EN->BackColor = System::Drawing::Color::Aqua;;
			break;
		case RU_index:	this->Project_Language_RU->BackColor = System::Drawing::Color::Aqua;;
			break;
		}		
	}
//function done
	private: System::Void Project_Language_LV_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		learn = {};
		this->Project_Language_LT->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_LV->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_EN->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_RU->BackColor = System::Drawing::SystemColors::Control;

		parameters.Language = LV_index;
		switch (parameters.Language)
		{
		case LT_index:	this->Project_Language_LT->BackColor = System::Drawing::Color::Aqua;;
			break;
		case LV_index:	this->Project_Language_LV->BackColor = System::Drawing::Color::Aqua;;
			break;
		case EN_index:	this->Project_Language_EN->BackColor = System::Drawing::Color::Aqua;;
			break;
		case RU_index:	this->Project_Language_RU->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_Language_EN_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		learn = {};
		this->Project_Language_LT->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_LV->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_EN->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_RU->BackColor = System::Drawing::SystemColors::Control;

		parameters.Language = EN_index;
		switch (parameters.Language)
		{
		case LT_index:	this->Project_Language_LT->BackColor = System::Drawing::Color::Aqua;;
			break;
		case LV_index:	this->Project_Language_LV->BackColor = System::Drawing::Color::Aqua;;
			break;
		case EN_index:	this->Project_Language_EN->BackColor = System::Drawing::Color::Aqua;;
			break;
		case RU_index:	this->Project_Language_RU->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_Language_RU_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);

		learn = {};
		this->Project_Language_LT->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_LV->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_EN->BackColor = System::Drawing::SystemColors::Control;
		this->Project_Language_RU->BackColor = System::Drawing::SystemColors::Control;

		parameters.Language = RU_index;
		switch (parameters.Language)
		{
		case LT_index:	this->Project_Language_LT->BackColor = System::Drawing::Color::Aqua;;
			break;
		case LV_index:	this->Project_Language_LV->BackColor = System::Drawing::Color::Aqua;;
			break;
		case EN_index:	this->Project_Language_EN->BackColor = System::Drawing::Color::Aqua;;
			break;
		case RU_index:	this->Project_Language_RU->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}


			 //menu Signals
//function done
	private: System::Void Signals_KKSedit_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Signals_all_KKS_trim(false);		
	}
//function done
	private: System::Void Signals_FindFunction_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Signals_find_function();
	}
//function done
private: System::Void Signals_MultiCPU_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
	wstring button_text = button_press_name_write(buttonName);
	Signals_multi_cpu(false);
}


			 //menu uniques
//function done
	private: System::Void Uniques_FindUniques_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		
		int a = this->Object_grid->RowCount;
		if (Objects_find_uniques() == 0)
		{
			if (a <= 1)
			{
				if (Objects_find_objects() == 0)
				{
					if (Objects_find_operatyv() == 0)
					{

					}
				}
			}
		}
	}
//function done
	private: System::Void Uniques_FindObjects_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		if (Objects_find_objects() == 0)
		{

		}
	}

//function done
	private: System::Void Uniques_FindOperatyv_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		if (Objects_find_operatyv() == 0)
		{

		}
	}

//empty
	private: System::Void Uniques_CorrectComments_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Objects_get_description_lenght();
		Display_no_function(buttonName);
	}
//function done
	private: System::Void Uniques_TransferSignals_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		if (Objects_transfer_to_signals(false))
		{

		}
	}


			 //menu Declare
//function done
	private: System::Void Declare_GenerateAdress_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Declare_addreses(false);
	}
//function done
	private: System::Void Declare_Adressing_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Declare_put_adres_grid(false,L" ");
	}
			 //menu instance

	//function done
	private: System::Void Instance_GenerateIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		if (IO_generate() == 0)
		{
			if (IO_show(false,L" ") == 0)
			{

			}
		}
	}

	//function done
	private: System::Void Instance_ShowIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		if (IO_show(false,L" ") == 0)
		{

		}
	}

//function done
	private: System::Void Instance_Generate_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Instance_gen(false,L" ");
	}



			 //menu SCADA
//function done
	private: System::Void SCADA_Instances_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		wstring button_text = button_press_name_write(buttonName);
		Instance_scada_gen(false,L" ");
	}



	private: void Change_filter_position(vector <int> &collumn_with, int collumn_count, int index_function)
	{
		int pixel=0;
		int pixel_offset = 15;

		switch (index_function)
		{
		case Design_grid_index:
			pixel = -this->Design_grid->HorizontalScrollingOffset + pixel_offset;
			break;
		case Signals_grid_index:
			pixel = -this->Signals_grid->HorizontalScrollingOffset + pixel_offset;
			break;
		case Objects_grid_index:
			pixel = -this->Object_grid->HorizontalScrollingOffset + pixel_offset;
			break;
		}
		
		int width = 0;
		for (int i = 0; i <= collumn_count;i++)
		{
			width = collumn_with[i];
			switch (i)
			{
				case 0:	this->Filter_0->Left = pixel;
						this->Filter_0->Width = width;
						this->Filter_0->Visible = true;
						break;
				case 1:	this->Filter_1->Left = pixel;
						this->Filter_1->Width = width;
						this->Filter_1->Visible = true;
						break;
				case 2:	this->Filter_2->Left = pixel;
						this->Filter_2->Width = width;
						this->Filter_2->Visible = true;
						break;
				case 3:	this->Filter_3->Left = pixel;
						this->Filter_3->Width = width;
						this->Filter_3->Visible = true;
						break;
				case 4:	this->Filter_4->Left = pixel;
						this->Filter_4->Width = width;
						this->Filter_4->Visible = true;
						break;
				case 5:	this->Filter_5->Left = pixel;
						this->Filter_5->Width = width;
						this->Filter_5->Visible = true;
						break;
				case 6:	this->Filter_6->Left = pixel;
						this->Filter_6->Width = width;
						this->Filter_6->Visible = true;
						break;
				case 7:	this->Filter_7->Left = pixel;
						this->Filter_7->Width = width;
						this->Filter_7->Visible = true;
						break;
				case 8:	this->Filter_8->Left = pixel;
						this->Filter_8->Width = width;
						this->Filter_8->Visible = true;
						break;
				case 9:	this->Filter_9->Left = pixel;
						this->Filter_9->Width = width;
						this->Filter_9->Visible = true;
						break;
				case 10:	this->Filter_10->Left = pixel;
						this->Filter_10->Width = width;
						this->Filter_10->Visible = true;
						break;
				case 11:	this->Filter_11->Left = pixel;
						this->Filter_11->Width = width;
						this->Filter_11->Visible = true;
						break;
				case 12:	this->Filter_12->Left = pixel;
						this->Filter_12->Width = width;
						this->Filter_12->Visible = true;
						break;
				case 13:	this->Filter_13->Left = pixel;
						this->Filter_13->Width = width;
						this->Filter_13->Visible = true;
						break;
				case 14:	this->Filter_14->Left = pixel;
						this->Filter_14->Width = width;
						this->Filter_14->Visible = true;
						break;
				case 15:	this->Filter_15->Left = pixel;
						this->Filter_15->Width = width;
						this->Filter_15->Visible = true;
						break;
				case 16:	this->Filter_16->Left = pixel;
						this->Filter_16->Width = width;
						this->Filter_16->Visible = true;
						break;
				case 17:	this->Filter_17->Left = pixel;
						this->Filter_17->Width = width;
						this->Filter_17->Visible = true;
						break;
				case 18:	this->Filter_18->Left = pixel;
						this->Filter_18->Width = width;
						this->Filter_18->Visible = true;
						break;
				case 19:	this->Filter_19->Left = pixel;
						this->Filter_19->Width = width;
						this->Filter_19->Visible = true;
						break;
			}
			pixel = pixel + width;
		}
		for (int i = collumn_count+1; i <= Filter_Count-1; i++)
		{
			width = 0;
			switch (i)
			{
			case 0:	this->Filter_0->Visible = false;
				break;
			case 1:	this->Filter_1->Visible = false;
				break;
			case 2:	this->Filter_2->Visible = false;
				break;
			case 3:	this->Filter_3->Visible = false;
				break;
			case 4:	this->Filter_4->Visible = false;
				break;
			case 5:	this->Filter_5->Visible = false;
				break;
			case 6:	this->Filter_6->Visible = false;
				break;
			case 7:	this->Filter_7->Visible = false;
				break;
			case 8:	this->Filter_8->Visible = false;
				break;
			case 9:	this->Filter_9->Visible = false;
				break;
			case 10:	this->Filter_10->Visible = false;
				break;
			case 11:	this->Filter_11->Visible = false;
				break;
			case 12:	this->Filter_12->Visible = false;
				break;
			case 13:	this->Filter_13->Visible = false;
				break;
			case 14:	this->Filter_14->Visible = false;
				break;
			case 15:	this->Filter_15->Visible = false;
				break;
			case 16:	this->Filter_16->Visible = false;
				break;
			case 17:	this->Filter_17->Visible = false;
				break;
			case 18:	this->Filter_18->Visible = false;
				break;
			case 19:	this->Filter_19->Visible = false;
				break;
			}
		}


	}

	public: void Global_Change_filter_position(int index_function)
	{

		switch (index_function)
		{
		case Design_grid_index:
								Global_get_width_list(index_function, project.number_collums, project.collumn_with);
								Change_filter_position(project.collumn_with,project.number_collums, index_function);
								break;
		case Signals_grid_index: 
								Global_get_width_list(index_function, signals.number_collums, signals.collumn_with);
								Change_filter_position(signals.collumn_with, signals.number_collums, index_function);
								break;
		case Objects_grid_index: 
								Global_get_width_list(index_function, objects.number_collums, objects.collumn_with);
								Change_filter_position(objects.collumn_with, objects.number_collums, index_function);
								break;
		}

	}

		private: void Find_put_to_view(filter_str filtras)
		{
			this->Filter_0->Text = wstring_to_system_string(filtras.Filter_text[0]);
			this->Filter_1->Text = wstring_to_system_string(filtras.Filter_text[1]);
			this->Filter_2->Text = wstring_to_system_string(filtras.Filter_text[2]);
			this->Filter_3->Text = wstring_to_system_string(filtras.Filter_text[3]);
			this->Filter_4->Text = wstring_to_system_string(filtras.Filter_text[4]);
			this->Filter_5->Text = wstring_to_system_string(filtras.Filter_text[5]);
			this->Filter_6->Text = wstring_to_system_string(filtras.Filter_text[6]);
			this->Filter_7->Text = wstring_to_system_string(filtras.Filter_text[7]);
			this->Filter_8->Text = wstring_to_system_string(filtras.Filter_text[8]);
			this->Filter_9->Text = wstring_to_system_string(filtras.Filter_text[9]);
			this->Filter_10->Text = wstring_to_system_string(filtras.Filter_text[10]);
			this->Filter_11->Text = wstring_to_system_string(filtras.Filter_text[11]);
			this->Filter_12->Text = wstring_to_system_string(filtras.Filter_text[12]);
			this->Filter_13->Text = wstring_to_system_string(filtras.Filter_text[13]);
			this->Filter_14->Text = wstring_to_system_string(filtras.Filter_text[14]);
			this->Filter_15->Text = wstring_to_system_string(filtras.Filter_text[15]);
			this->Filter_16->Text = wstring_to_system_string(filtras.Filter_text[16]);
			this->Filter_17->Text = wstring_to_system_string(filtras.Filter_text[17]);
			this->Filter_18->Text = wstring_to_system_string(filtras.Filter_text[18]);
			this->Filter_19->Text = wstring_to_system_string(filtras.Filter_text[19]);

		}

		private: void Find_put_to_view(int index_function)
		{
			switch (index_function)
			{
			case Design_grid_index:
				Find_put_to_view(design_filter);
				break;
			case Signals_grid_index:
				Find_put_to_view(signal_filter);
				break;
			case Objects_grid_index:
				Find_put_to_view(object_filter);
				break;
			}

		}

		private: System::Void Grid_changed_index(System::Object^  sender, System::EventArgs^  e) {
			int index_function = this->tabControl1->SelectedIndex;
			Global_Change_filter_position(index_function);
			Find_put_to_view(index_function);
		}

	private: System::Void D_column_width_changed(System::Object^  sender, System::Windows::Forms::DataGridViewColumnEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}
	private: System::Void D_scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}
	private: System::Void S_column_width_changed(System::Object^  sender, System::Windows::Forms::DataGridViewColumnEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}
	private: System::Void S_scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}
	private: System::Void O_column_width_changed(System::Object^  sender, System::Windows::Forms::DataGridViewColumnEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}
	private: System::Void O_scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		Global_Change_filter_position(index_function);
	}


	private: System::Void Filter_Changed_Text_0(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 0, index_function);
	}
	private: System::Void Filter_Changed_Text_1(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 1, index_function);
	}
	private: System::Void Filter_Changed_Text_2(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 2, index_function);
	}
	private: System::Void Filter_Changed_Text_3(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 3, index_function);
	}
	private: System::Void Filter_Changed_Text_4(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 4, index_function);
	}
	private: System::Void Filter_Changed_Text_5(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 5, index_function);
	}
	private: System::Void Filter_Changed_Text_6(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 6, index_function);
	}
	private: System::Void Filter_Changed_Text_7(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 7, index_function);
	}
	private: System::Void Filter_Changed_Text_8(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 8, index_function);
	}
	private: System::Void Filter_Changed_Text_9(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 9, index_function);
	}
	private: System::Void Filter_Changed_Text_10(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 10, index_function);
	}
	private: System::Void Filter_Changed_Text_11(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 11, index_function);
	}
	private: System::Void Filter_Changed_Text_12(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 12, index_function);
	}
	private: System::Void Filter_Changed_Text_13(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 13, index_function);
	}
	private: System::Void Filter_Changed_Text_14(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 14, index_function);
	}
	private: System::Void Filter_Changed_Text_15(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 15, index_function);
	}
	private: System::Void Filter_Changed_Text_16(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 16, index_function);
	}
	private: System::Void Filter_Changed_Text_17(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 17, index_function);
	}
	private: System::Void Filter_Changed_Text_18(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 18, index_function);
	}
	private: System::Void Filter_Changed_Text_19(System::Object^  sender, System::EventArgs^  e) {
		int index_function = this->tabControl1->SelectedIndex;
		String^ text_from_box = safe_cast<ComboBox^>(sender)->Text;
		wstring text = system_string_to_wstring(text_from_box);
		Global_Filter_text_changed(text, 19, index_function);
	}

	private: void Drop_down_text_write(ComboBox ^filter_box, vector <wstring> unique_texts, int valid_entries)
	{
		filter_box->Items->Clear();
		for (int i = 0; i < valid_entries; i++)
		{
			filter_box->Items->Add(wstring_to_system_string(unique_texts[i]));
		}
		int a = 0;
	}

private: System::Void Filter_Drop_down_0(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 0, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_1(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 1, unique_texts);
	int valid_entries = sizeof(unique_texts);
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_2(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 2, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_3(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 3, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_4(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 4, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_5(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 5, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_6(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 6, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_7(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 7, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_8(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 8, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_9(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 9, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_10(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 10, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_11(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 11, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_12(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 12, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_13(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 13, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_14(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 14, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_15(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 15, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_16(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 16, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_17(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 17, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_18(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 18, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_Drop_down_19(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;
	Global_Filter_drop_down(index_function, 19, unique_texts);
	int valid_entries = sizeof(unique_texts);
	valid_entries = unique_texts.size();
	Drop_down_text_write(safe_cast<ComboBox^>(sender), unique_texts, valid_entries);
}
private: System::Void Filter_clicked()
{
	int index_function = this->tabControl1->SelectedIndex;
	switch (index_function)
	{
	case Design_grid_index:
			this->Design_grid->ClearSelection();
		break;
	case Signals_grid_index:
			this->Signals_grid->ClearSelection();
		break;
	case Objects_grid_index:
		this->Object_grid->ClearSelection();
		break;
	}

}
private: System::Void Filter_click_0(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_1(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_2(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_3(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_4(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_5(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_6(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_7(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_8(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_9(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_10(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_11(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_12(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_13(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_14(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_15(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_16(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_17(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_18(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Filter_click_19(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Find_button_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ texts = this->Find_text->Text;
	wstring text_value = system_string_to_wstring(texts);
	int index_function = this->tabControl1->SelectedIndex;

	int valid_entries = 0;
	int number_collums = 0;
	int start_index = 0;
	int start_iCol = 0;
	int result = 0;

	System::Windows::Forms::DataGridView^ grid = Global_function_grid(index_function);

	if (grid->SelectedCells->Count >= 1)
	{
		start_index = grid->SelectedCells[0]->RowIndex;
		start_iCol = grid->SelectedCells[0]->ColumnIndex+1;
	}

	if (grid->RowCount > 0)
	{
		valid_entries = grid->RowCount - 1;
		number_collums = grid->ColumnCount-1;

		wstring cell_text = L"";

		for (int index = start_index; index <= valid_entries; index++)
		{
			// fill all cells with data
			for (int iCol = start_iCol; iCol <= number_collums; iCol++)
			{
				cell_text = Global_get_cell_value(index, iCol, grid);
				result = cell_text.find(text_value);
				if (result  >= 0)
				{
					grid->ClearSelection();
//					grid->CurrentCell = grid->Rows[index]->Cells[iCol];
					grid->Rows[index]->Cells[iCol]->Selected = true;
					index = valid_entries;
					break;
				}				
			}
			start_iCol = 0;
		}
	}
}

private: System::Void Find_text_Click(System::Object^  sender, System::EventArgs^  e) {
	Filter_clicked();
}
private: System::Void Clear_button_Click(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;

	Global_delete_all_data(index_function);
	int result = Global_trend_data_check(Max_Trend_data);
//	Global_put_data_listview(Trend_data_grid_index, Trend_data.valid_entries, Trend_data.number_collums, Trend_data.column_name, Trend_data.collumn_with);

}
private: System::Void Poly_calc_button_Click(System::Object^  sender, System::EventArgs^  e) {
	Global_Polynom_calc();
}
private: System::Void File_ReadCFG_Click(System::Object^  sender, System::EventArgs^  e) {
	cfg_reads(&parameters, L" ");

}

private: System::Void Gen_tests_click(System::Object^  sender, System::EventArgs^  e) {
	Generate_Test_All();
}
private: System::Void Plot_button_Click(System::Object^  sender, System::EventArgs^  e) {
	int index_function = this->tabControl1->SelectedIndex;
	vector <wstring> unique_texts;

	Plot_data_to_file(index_function,0,1);
	Global_show_trend_data();
}
};
}

public ref class GlobalForm {
public:
	static IOlistautomation::MainWindow^ forma = nullptr;
};