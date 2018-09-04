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





	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_PID;
	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_Valve;
	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_HC;
	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_AI;
	private: System::Windows::Forms::ToolStripMenuItem^  SCADA_Motor;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->Design_grid = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_Save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_SaveALL = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_Load = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_LoadALL = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->File_Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->File_About = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->SCADA_PID = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SCADA_Valve = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SCADA_HC = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SCADA_AI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SCADA_Motor = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Signals_grid = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->Object_grid = (gcnew System::Windows::Forms::DataGridView());
			this->progressBaras = (gcnew System::Windows::Forms::ProgressBar());
			this->Progress_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Design_grid))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Signals_grid))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Object_grid))->BeginInit();
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
			this->Design_grid->Location = System::Drawing::Point(1, 1);
			this->Design_grid->Name = L"Design_grid";
			this->Design_grid->RowHeadersWidth = 10;
			this->Design_grid->Size = System::Drawing::Size(850, 298);
			this->Design_grid->TabIndex = 0;
			this->Design_grid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dataGridView1_CellContentClick);
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
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->File_Save,
					this->File_SaveALL, this->File_Load, this->File_LoadALL, this->toolStripSeparator1, this->File_Help, this->File_About, this->toolStripSeparator2,
					this->File_Exit
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// File_Save
			// 
			this->File_Save->Name = L"File_Save";
			this->File_Save->Size = System::Drawing::Size(115, 22);
			this->File_Save->Text = L"Save";
			this->File_Save->Click += gcnew System::EventHandler(this, &MainWindow::File_Save_Click);
			// 
			// File_SaveALL
			// 
			this->File_SaveALL->Name = L"File_SaveALL";
			this->File_SaveALL->Size = System::Drawing::Size(115, 22);
			this->File_SaveALL->Text = L"Save all";
			this->File_SaveALL->Click += gcnew System::EventHandler(this, &MainWindow::File_SaveALL_Click);
			// 
			// File_Load
			// 
			this->File_Load->Name = L"File_Load";
			this->File_Load->Size = System::Drawing::Size(115, 22);
			this->File_Load->Text = L"Load";
			this->File_Load->Click += gcnew System::EventHandler(this, &MainWindow::File_Load_Click);
			// 
			// File_LoadALL
			// 
			this->File_LoadALL->Name = L"File_LoadALL";
			this->File_LoadALL->Size = System::Drawing::Size(115, 22);
			this->File_LoadALL->Text = L"Load all";
			this->File_LoadALL->Click += gcnew System::EventHandler(this, &MainWindow::File_LoadALL_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(112, 6);
			// 
			// File_Help
			// 
			this->File_Help->Name = L"File_Help";
			this->File_Help->Size = System::Drawing::Size(115, 22);
			this->File_Help->Text = L"Help";
			this->File_Help->Click += gcnew System::EventHandler(this, &MainWindow::File_Help_Click);
			// 
			// File_About
			// 
			this->File_About->Name = L"File_About";
			this->File_About->Size = System::Drawing::Size(115, 22);
			this->File_About->Text = L"About";
			this->File_About->Click += gcnew System::EventHandler(this, &MainWindow::File_About_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(112, 6);
			// 
			// File_Exit
			// 
			this->File_Exit->Name = L"File_Exit";
			this->File_Exit->Size = System::Drawing::Size(115, 22);
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
			this->Project_IOcompare->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
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
			this->Project_SCADA_SystemPlatform->Name = L"Project_SCADA_SystemPlatform";
			this->Project_SCADA_SystemPlatform->Size = System::Drawing::Size(161, 22);
			this->Project_SCADA_SystemPlatform->Text = L"System Platform";
			this->Project_SCADA_SystemPlatform->Click += gcnew System::EventHandler(this, &MainWindow::Project_SCADA_SystemPlatform_Click);
			// 
			// Project_SCADA_WinCC
			// 
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
			this->Project_Language_LV->Name = L"Project_Language_LV";
			this->Project_Language_LV->Size = System::Drawing::Size(89, 22);
			this->Project_Language_LV->Text = L"LV";
			this->Project_Language_LV->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_LV_Click);
			// 
			// Project_Language_RU
			// 
			this->Project_Language_RU->Name = L"Project_Language_RU";
			this->Project_Language_RU->Size = System::Drawing::Size(89, 22);
			this->Project_Language_RU->Text = L"RU";
			this->Project_Language_RU->Click += gcnew System::EventHandler(this, &MainWindow::Project_Language_RU_Click);
			// 
			// signalsToolStripMenuItem
			// 
			this->signalsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Signals_KKSedit,
					this->Signals_FindFunction
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
			this->sCADAToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->SCADA_PID,
					this->SCADA_Valve, this->SCADA_HC, this->SCADA_AI, this->SCADA_Motor
			});
			this->sCADAToolStripMenuItem->Name = L"sCADAToolStripMenuItem";
			this->sCADAToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->sCADAToolStripMenuItem->Text = L"SCADA";
			// 
			// SCADA_PID
			// 
			this->SCADA_PID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SCADA_PID->Name = L"SCADA_PID";
			this->SCADA_PID->Size = System::Drawing::Size(107, 22);
			this->SCADA_PID->Text = L"PID";
			this->SCADA_PID->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_PID_Click);
			// 
			// SCADA_Valve
			// 
			this->SCADA_Valve->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SCADA_Valve->Name = L"SCADA_Valve";
			this->SCADA_Valve->Size = System::Drawing::Size(107, 22);
			this->SCADA_Valve->Text = L"Valve";
			this->SCADA_Valve->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_Valve_Click);
			// 
			// SCADA_HC
			// 
			this->SCADA_HC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SCADA_HC->Name = L"SCADA_HC";
			this->SCADA_HC->Size = System::Drawing::Size(107, 22);
			this->SCADA_HC->Text = L"HC";
			this->SCADA_HC->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_HC_Click);
			// 
			// SCADA_AI
			// 
			this->SCADA_AI->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SCADA_AI->Name = L"SCADA_AI";
			this->SCADA_AI->Size = System::Drawing::Size(107, 22);
			this->SCADA_AI->Text = L"AI";
			this->SCADA_AI->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_AI_Click);
			// 
			// SCADA_Motor
			// 
			this->SCADA_Motor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SCADA_Motor->Name = L"SCADA_Motor";
			this->SCADA_Motor->Size = System::Drawing::Size(107, 22);
			this->SCADA_Motor->Text = L"Motor";
			this->SCADA_Motor->Click += gcnew System::EventHandler(this, &MainWindow::SCADA_Motor_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(861, 327);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Design_grid);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(853, 301);
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
			this->tabPage2->Size = System::Drawing::Size(853, 301);
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
			this->Signals_grid->Location = System::Drawing::Point(1, 1);
			this->Signals_grid->Name = L"Signals_grid";
			this->Signals_grid->RowHeadersWidth = 10;
			this->Signals_grid->Size = System::Drawing::Size(850, 298);
			this->Signals_grid->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->Object_grid);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(853, 301);
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
			this->Object_grid->Location = System::Drawing::Point(1, 1);
			this->Object_grid->Name = L"Object_grid";
			this->Object_grid->RowHeadersWidth = 10;
			this->Object_grid->Size = System::Drawing::Size(850, 298);
			this->Object_grid->TabIndex = 1;
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
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(861, 371);
			this->Controls->Add(this->Progress_label);
			this->Controls->Add(this->progressBaras);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void KeyDown_event(Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		
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
		}
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
		

		switch (parameters.Language)
		{
		case System_platform:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}

		this->KeyDown += gcnew KeyEventHandler(this, &MainWindow::KeyDown_event);

		signals.valid_entries = 1;
		project.valid_entries = 1;
		objects.valid_entries = 1;

		Global_resize_data(Design_grid_index, 2);
		Global_resize_data(Signals_grid_index, 2);
		Global_resize_data(Objects_grid_index, 2);

		Global_get_width_list(Design_grid_index, project.number_collums, project.collumn_with);
		Global_get_width_list(Signals_grid_index, signals.number_collums, signals.collumn_with);
		Global_get_width_list(Objects_grid_index, objects.number_collums, objects.collumn_with);

		Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
		Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);

		this->tabControl1->SelectedIndex = Design_grid_index;
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int a = 0;
	}

			 //menu file
//function done
	private: System::Void File_Save_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		int index_function = this->tabControl1->SelectedIndex;
		
		Global_get_data_listview(index_function, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		Global_choose_save(index_function, false, " ");
	}
//function done
	private: System::Void File_SaveALL_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		
		sfd->Filter = "Save document |*.psave;*.osave;*.ssave";

		sfd->FileName = "";
		std::string file_name;
		
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			file_name = system_string_to_string(sfd->FileName);
			std::string extension;
			
			int a = -1;
			bool continue_save = true;
			a = file_name.find_last_of(".");

			if (a > 0)
			{
				continue_save = false;
				extension = file_name.substr(a + 2);
				if (extension.compare("save") >= 0)
				{
					file_name = file_name.substr(0, a);
					continue_save = true;
				}
			}

			Global_get_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
			Global_get_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
			Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);

			Global_choose_save(Design_grid_index, false, file_name);
			Global_choose_save(Signals_grid_index, false, file_name);
			Global_choose_save(Objects_grid_index, false, file_name);
		}
		else
		{
			strcpy_s(err_txt, sizeof err_txt, button_text);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
		}
				
	}
//function done
	private: System::Void File_Load_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		int index_function = this->tabControl1->SelectedIndex;
			
		Global_choose_Load(index_function," ");			
	}

	private: System::Void File_LoadALL_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		OpenFileDialog^ importfile = gcnew OpenFileDialog();
		importfile->Filter = "Load document |*.psave;*.osave;*.ssave";
		importfile->FileName = "";

		if (importfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			std::string file_name;
			std::string extension;

			file_name = system_string_to_string(importfile->FileName);
			int a = -1;
			int b = 0;
			bool continue_load = true;
			a = file_name.find_last_of(".");			

			if (a > 0)
			{
				continue_load = false;
				extension = file_name.substr(a + 2);
				if (extension.compare("save") >=0)
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
			strcpy_s(err_txt, sizeof err_txt, button_text);
			strcat_s(err_txt, sizeof err_txt, error_separator);
			strcat_s(err_txt, sizeof err_txt, err_canceled_selection[lang]);
			err_write(err_txt);
		}
	}
//function done
	private: System::Void File_Help_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		IOlistautomation::HelpForm helpas;
		helpas.ShowDialog();
	}
//function done
	private: System::Void File_About_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		IOlistautomation::AboutForm about;
		about.ShowDialog();
	}
//function done
	private: System::Void File_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		strcpy_s(info_txt, sizeof info_txt, info_exit_aplication[lang]);
		info_write(info_txt);
		Application::Exit();
	}

			 //menu Project
//function done
	private: System::Void Project_Design_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (Project_read_data() == 0)
		{
			Signals_get_data_design();
		}

	}
//empty
	private: System::Void Project_IOcompare_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//function done
	private: System::Void Project_TransferIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Signals_get_data_design();
	}
//function done
	private: System::Void Project_CPU_Beckhoff_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::SystemColors::Control;
		this->Project_SCADA_WinCC->BackColor = System::Drawing::SystemColors::Control;

		parameters.SCADA = System_platform;
		switch (parameters.SCADA)
		{
		case System_platform:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_SCADA_WinCC_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::SystemColors::Control;
		this->Project_SCADA_WinCC->BackColor = System::Drawing::SystemColors::Control;

		parameters.SCADA = WinCC;
		switch (parameters.SCADA)
		{
		case System_platform:	this->Project_SCADA_SystemPlatform->BackColor = System::Drawing::Color::Aqua;;
			break;
		case WinCC:	this->Project_SCADA_WinCC->BackColor = System::Drawing::Color::Aqua;;
			break;
		}
	}
//function done
	private: System::Void Project_Language_LT_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		
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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		Signals_all_KKS_trim();		
	}
//function done
	private: System::Void Signals_FindFunction_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		Signals_find_function();
	}


			 //menu uniques
//function done
	private: System::Void Uniques_FindUniques_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		
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
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (Objects_find_objects() == 0)
		{

		}
	}

//function done
	private: System::Void Uniques_FindOperatyv_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (Objects_find_operatyv() == 0)
		{

		}
	}

//empty
	private: System::Void Uniques_CorrectComments_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//function done
	private: System::Void Uniques_TransferSignals_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (Objects_transfer_to_signals())
		{

		}
	}


			 //menu Declare
//function done
	private: System::Void Declare_GenerateAdress_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Declare_addreses();
	}
//function done
	private: System::Void Declare_Adressing_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();
		
		Declare_put_adres_grid();

	}

			 //menu instance

	//function done
	private: System::Void Instance_GenerateIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (IO_generate() == 0)
		{
			if (IO_show() == 0)
			{

			}
		}
	}

	//function done
	private: System::Void Instance_ShowIO_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		if (IO_show() == 0)
		{

		}
	}

//function done
	private: System::Void Instance_Generate_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Instance_gen();
	}



			 //menu SCADA
//empty
	private: System::Void SCADA_PID_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//empty
	private: System::Void SCADA_Valve_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//empty
	private: System::Void SCADA_HC_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//empty
	private: System::Void SCADA_AI_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);
	}
//empty
	private: System::Void SCADA_Motor_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Name;
		string converted_text = button_press_name_write(buttonName);
		const char *button_text = converted_text.c_str();

		Display_no_function(buttonName);		
	}






};
}

public ref class GlobalForm {
public:
	static IOlistautomation::MainWindow^ forma = nullptr;
};