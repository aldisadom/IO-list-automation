#pragma once
#include "config.h"
#include "resource.h"
#include "design.h"
#include "signals.h"
#include "AboutForm.h"

#include <msclr/marshal_cppstd.h>



namespace IOlistautomation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  projectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  designToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  iOCompareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cPUSelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  beckhoffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  xAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  siemensToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  schneiderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sCADASelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  systemPlatformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  languageSelectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  eNToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rUToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  signalsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kKSEditToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  findFunctionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  uniquesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  declareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  iOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instanceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sCADAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  findUniquesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  findObjectsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  correctCommentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  transferToSignalsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pIDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  valveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  motorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createIOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pIDToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  valveToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  hCToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aIToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  motorToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  pIDToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  valveToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  hCToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  aIToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  motorToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  winCCToolStripMenuItem;
	public: System::Windows::Forms::ProgressBar^  progressBaras;


	public: System::Windows::Forms::Label^  Progress_label;
	private: System::Windows::Forms::ToolStripMenuItem^  transferDataToSignalsToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->Design_grid = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->projectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->designToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->iOCompareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transferDataToSignalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cPUSelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->beckhoffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->siemensToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->schneiderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sCADASelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemPlatformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->winCCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageSelectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rUToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kKSEditToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findFunctionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uniquesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findUniquesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findObjectsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->correctCommentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transferToSignalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->declareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pIDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->valveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->motorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->iOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createIOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pIDToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->valveToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hCToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aIToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->motorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sCADAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pIDToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->valveToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hCToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aIToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->motorToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->progressBaras = (gcnew System::Windows::Forms::ProgressBar());
			this->Progress_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Design_grid))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
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
			this->Design_grid->Location = System::Drawing::Point(0, 3);
			this->Design_grid->Name = L"Design_grid";
			this->Design_grid->Size = System::Drawing::Size(850, 298);
			this->Design_grid->TabIndex = 0;
			this->Design_grid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dataGridView1_CellContentClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->fileToolStripMenuItem,
					this->projectToolStripMenuItem, this->signalsToolStripMenuItem, this->uniquesToolStripMenuItem, this->declareToolStripMenuItem,
					this->iOToolStripMenuItem, this->instanceToolStripMenuItem, this->sCADAToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(861, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"MenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->saveToolStripMenuItem,
					this->loadToolStripMenuItem, this->helpToolStripMenuItem, this->aboutToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::saveToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::loadToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::helpToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exitToolStripMenuItem_Click);
			// 
			// projectToolStripMenuItem
			// 
			this->projectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->designToolStripMenuItem,
					this->iOCompareToolStripMenuItem, this->transferDataToSignalsToolStripMenuItem, this->cPUSelectToolStripMenuItem, this->sCADASelectToolStripMenuItem,
					this->languageSelectToolStripMenuItem
			});
			this->projectToolStripMenuItem->Name = L"projectToolStripMenuItem";
			this->projectToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->projectToolStripMenuItem->Text = L"Project";
			// 
			// designToolStripMenuItem
			// 
			this->designToolStripMenuItem->Name = L"designToolStripMenuItem";
			this->designToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->designToolStripMenuItem->Text = L"Design";
			this->designToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::designToolStripMenuItem_Click);
			// 
			// iOCompareToolStripMenuItem
			// 
			this->iOCompareToolStripMenuItem->Name = L"iOCompareToolStripMenuItem";
			this->iOCompareToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->iOCompareToolStripMenuItem->Text = L"IO compare";
			this->iOCompareToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::iOCompareToolStripMenuItem_Click);
			// 
			// transferDataToSignalsToolStripMenuItem
			// 
			this->transferDataToSignalsToolStripMenuItem->Name = L"transferDataToSignalsToolStripMenuItem";
			this->transferDataToSignalsToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->transferDataToSignalsToolStripMenuItem->Text = L"Transfer Data To Signals";
			this->transferDataToSignalsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::transferDataToSignalsToolStripMenuItem_Click);
			// 
			// cPUSelectToolStripMenuItem
			// 
			this->cPUSelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->beckhoffToolStripMenuItem,
					this->xAToolStripMenuItem, this->siemensToolStripMenuItem, this->schneiderToolStripMenuItem
			});
			this->cPUSelectToolStripMenuItem->Name = L"cPUSelectToolStripMenuItem";
			this->cPUSelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->cPUSelectToolStripMenuItem->Text = L"CPU Select";
			// 
			// beckhoffToolStripMenuItem
			// 
			this->beckhoffToolStripMenuItem->Name = L"beckhoffToolStripMenuItem";
			this->beckhoffToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->beckhoffToolStripMenuItem->Text = L"Beckhoff";
			this->beckhoffToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::beckhoffToolStripMenuItem_Click);
			// 
			// xAToolStripMenuItem
			// 
			this->xAToolStripMenuItem->Name = L"xAToolStripMenuItem";
			this->xAToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->xAToolStripMenuItem->Text = L"800xA";
			this->xAToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::xAToolStripMenuItem_Click);
			// 
			// siemensToolStripMenuItem
			// 
			this->siemensToolStripMenuItem->Name = L"siemensToolStripMenuItem";
			this->siemensToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->siemensToolStripMenuItem->Text = L"Siemens";
			this->siemensToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::siemensToolStripMenuItem_Click);
			// 
			// schneiderToolStripMenuItem
			// 
			this->schneiderToolStripMenuItem->Name = L"schneiderToolStripMenuItem";
			this->schneiderToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->schneiderToolStripMenuItem->Text = L"Schneider";
			this->schneiderToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::schneiderToolStripMenuItem_Click);
			// 
			// sCADASelectToolStripMenuItem
			// 
			this->sCADASelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->systemPlatformToolStripMenuItem,
					this->winCCToolStripMenuItem
			});
			this->sCADASelectToolStripMenuItem->Name = L"sCADASelectToolStripMenuItem";
			this->sCADASelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->sCADASelectToolStripMenuItem->Text = L"SCADA Select";
			// 
			// systemPlatformToolStripMenuItem
			// 
			this->systemPlatformToolStripMenuItem->Name = L"systemPlatformToolStripMenuItem";
			this->systemPlatformToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->systemPlatformToolStripMenuItem->Text = L"System Platform";
			this->systemPlatformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::systemPlatformToolStripMenuItem_Click);
			// 
			// winCCToolStripMenuItem
			// 
			this->winCCToolStripMenuItem->Name = L"winCCToolStripMenuItem";
			this->winCCToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->winCCToolStripMenuItem->Text = L"WinCC";
			this->winCCToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::winCCToolStripMenuItem_Click);
			// 
			// languageSelectToolStripMenuItem
			// 
			this->languageSelectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->lTToolStripMenuItem,
					this->lVToolStripMenuItem, this->eNToolStripMenuItem, this->rUToolStripMenuItem
			});
			this->languageSelectToolStripMenuItem->Name = L"languageSelectToolStripMenuItem";
			this->languageSelectToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->languageSelectToolStripMenuItem->Text = L"Language Select";
			// 
			// lTToolStripMenuItem
			// 
			this->lTToolStripMenuItem->Name = L"lTToolStripMenuItem";
			this->lTToolStripMenuItem->Size = System::Drawing::Size(89, 22);
			this->lTToolStripMenuItem->Text = L"LT";
			this->lTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::lTToolStripMenuItem_Click);
			// 
			// lVToolStripMenuItem
			// 
			this->lVToolStripMenuItem->Name = L"lVToolStripMenuItem";
			this->lVToolStripMenuItem->Size = System::Drawing::Size(89, 22);
			this->lVToolStripMenuItem->Text = L"LV";
			this->lVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::lVToolStripMenuItem_Click);
			// 
			// eNToolStripMenuItem
			// 
			this->eNToolStripMenuItem->Name = L"eNToolStripMenuItem";
			this->eNToolStripMenuItem->Size = System::Drawing::Size(89, 22);
			this->eNToolStripMenuItem->Text = L"EN";
			this->eNToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::eNToolStripMenuItem_Click);
			// 
			// rUToolStripMenuItem
			// 
			this->rUToolStripMenuItem->Name = L"rUToolStripMenuItem";
			this->rUToolStripMenuItem->Size = System::Drawing::Size(89, 22);
			this->rUToolStripMenuItem->Text = L"RU";
			this->rUToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::rUToolStripMenuItem_Click);
			// 
			// signalsToolStripMenuItem
			// 
			this->signalsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->kKSEditToolStripMenuItem,
					this->findFunctionToolStripMenuItem
			});
			this->signalsToolStripMenuItem->Name = L"signalsToolStripMenuItem";
			this->signalsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->signalsToolStripMenuItem->Text = L"Signals";
			// 
			// kKSEditToolStripMenuItem
			// 
			this->kKSEditToolStripMenuItem->Name = L"kKSEditToolStripMenuItem";
			this->kKSEditToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->kKSEditToolStripMenuItem->Text = L"KKS edit";
			this->kKSEditToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::kKSEditToolStripMenuItem_Click);
			// 
			// findFunctionToolStripMenuItem
			// 
			this->findFunctionToolStripMenuItem->Name = L"findFunctionToolStripMenuItem";
			this->findFunctionToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->findFunctionToolStripMenuItem->Text = L"Find function";
			this->findFunctionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::findFunctionToolStripMenuItem_Click);
			// 
			// uniquesToolStripMenuItem
			// 
			this->uniquesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->findUniquesToolStripMenuItem,
					this->findObjectsToolStripMenuItem, this->correctCommentsToolStripMenuItem, this->transferToSignalsToolStripMenuItem
			});
			this->uniquesToolStripMenuItem->Name = L"uniquesToolStripMenuItem";
			this->uniquesToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->uniquesToolStripMenuItem->Text = L"Uniques";
			// 
			// findUniquesToolStripMenuItem
			// 
			this->findUniquesToolStripMenuItem->Name = L"findUniquesToolStripMenuItem";
			this->findUniquesToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->findUniquesToolStripMenuItem->Text = L"Find Uniques";
			this->findUniquesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::findUniquesToolStripMenuItem_Click);
			// 
			// findObjectsToolStripMenuItem
			// 
			this->findObjectsToolStripMenuItem->Name = L"findObjectsToolStripMenuItem";
			this->findObjectsToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->findObjectsToolStripMenuItem->Text = L"Find Objects";
			this->findObjectsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::findObjectsToolStripMenuItem_Click);
			// 
			// correctCommentsToolStripMenuItem
			// 
			this->correctCommentsToolStripMenuItem->Name = L"correctCommentsToolStripMenuItem";
			this->correctCommentsToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->correctCommentsToolStripMenuItem->Text = L"Correct Comments";
			this->correctCommentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::correctCommentsToolStripMenuItem_Click);
			// 
			// transferToSignalsToolStripMenuItem
			// 
			this->transferToSignalsToolStripMenuItem->Name = L"transferToSignalsToolStripMenuItem";
			this->transferToSignalsToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->transferToSignalsToolStripMenuItem->Text = L"Transfer to Signals";
			this->transferToSignalsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::transferToSignalsToolStripMenuItem_Click);
			// 
			// declareToolStripMenuItem
			// 
			this->declareToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->pIDToolStripMenuItem,
					this->valveToolStripMenuItem, this->hCToolStripMenuItem, this->aIToolStripMenuItem, this->motorToolStripMenuItem, this->fCToolStripMenuItem
			});
			this->declareToolStripMenuItem->Name = L"declareToolStripMenuItem";
			this->declareToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->declareToolStripMenuItem->Text = L"Declare";
			// 
			// pIDToolStripMenuItem
			// 
			this->pIDToolStripMenuItem->Name = L"pIDToolStripMenuItem";
			this->pIDToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->pIDToolStripMenuItem->Text = L"PID";
			this->pIDToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::pIDToolStripMenuItem_Click);
			// 
			// valveToolStripMenuItem
			// 
			this->valveToolStripMenuItem->Name = L"valveToolStripMenuItem";
			this->valveToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->valveToolStripMenuItem->Text = L"Valve";
			this->valveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::valveToolStripMenuItem_Click);
			// 
			// hCToolStripMenuItem
			// 
			this->hCToolStripMenuItem->Name = L"hCToolStripMenuItem";
			this->hCToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->hCToolStripMenuItem->Text = L"HC";
			this->hCToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::hCToolStripMenuItem_Click);
			// 
			// aIToolStripMenuItem
			// 
			this->aIToolStripMenuItem->Name = L"aIToolStripMenuItem";
			this->aIToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aIToolStripMenuItem->Text = L"AI";
			this->aIToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::aIToolStripMenuItem_Click);
			// 
			// motorToolStripMenuItem
			// 
			this->motorToolStripMenuItem->Name = L"motorToolStripMenuItem";
			this->motorToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->motorToolStripMenuItem->Text = L"Motor";
			this->motorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::motorToolStripMenuItem_Click);
			// 
			// fCToolStripMenuItem
			// 
			this->fCToolStripMenuItem->Name = L"fCToolStripMenuItem";
			this->fCToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->fCToolStripMenuItem->Text = L"FC";
			this->fCToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::fCToolStripMenuItem_Click);
			// 
			// iOToolStripMenuItem
			// 
			this->iOToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createIOToolStripMenuItem });
			this->iOToolStripMenuItem->Name = L"iOToolStripMenuItem";
			this->iOToolStripMenuItem->Size = System::Drawing::Size(31, 20);
			this->iOToolStripMenuItem->Text = L"IO";
			// 
			// createIOToolStripMenuItem
			// 
			this->createIOToolStripMenuItem->Name = L"createIOToolStripMenuItem";
			this->createIOToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->createIOToolStripMenuItem->Text = L"Create IO";
			this->createIOToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::createIOToolStripMenuItem_Click);
			// 
			// instanceToolStripMenuItem
			// 
			this->instanceToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->pIDToolStripMenuItem1,
					this->valveToolStripMenuItem1, this->hCToolStripMenuItem1, this->aIToolStripMenuItem1, this->motorToolStripMenuItem1
			});
			this->instanceToolStripMenuItem->Name = L"instanceToolStripMenuItem";
			this->instanceToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->instanceToolStripMenuItem->Text = L"Instance";
			// 
			// pIDToolStripMenuItem1
			// 
			this->pIDToolStripMenuItem1->Name = L"pIDToolStripMenuItem1";
			this->pIDToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->pIDToolStripMenuItem1->Text = L"PID";
			this->pIDToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::pIDToolStripMenuItem1_Click);
			// 
			// valveToolStripMenuItem1
			// 
			this->valveToolStripMenuItem1->Name = L"valveToolStripMenuItem1";
			this->valveToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->valveToolStripMenuItem1->Text = L"Valve";
			this->valveToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::valveToolStripMenuItem1_Click);
			// 
			// hCToolStripMenuItem1
			// 
			this->hCToolStripMenuItem1->Name = L"hCToolStripMenuItem1";
			this->hCToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->hCToolStripMenuItem1->Text = L"HC";
			this->hCToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::hCToolStripMenuItem1_Click);
			// 
			// aIToolStripMenuItem1
			// 
			this->aIToolStripMenuItem1->Name = L"aIToolStripMenuItem1";
			this->aIToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->aIToolStripMenuItem1->Text = L"AI";
			this->aIToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::aIToolStripMenuItem1_Click);
			// 
			// motorToolStripMenuItem1
			// 
			this->motorToolStripMenuItem1->Name = L"motorToolStripMenuItem1";
			this->motorToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->motorToolStripMenuItem1->Text = L"Motor";
			this->motorToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::motorToolStripMenuItem1_Click);
			// 
			// sCADAToolStripMenuItem
			// 
			this->sCADAToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->pIDToolStripMenuItem2,
					this->valveToolStripMenuItem2, this->hCToolStripMenuItem2, this->aIToolStripMenuItem2, this->motorToolStripMenuItem2
			});
			this->sCADAToolStripMenuItem->Name = L"sCADAToolStripMenuItem";
			this->sCADAToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->sCADAToolStripMenuItem->Text = L"SCADA";
			// 
			// pIDToolStripMenuItem2
			// 
			this->pIDToolStripMenuItem2->Name = L"pIDToolStripMenuItem2";
			this->pIDToolStripMenuItem2->Size = System::Drawing::Size(107, 22);
			this->pIDToolStripMenuItem2->Text = L"PID";
			this->pIDToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::pIDToolStripMenuItem2_Click);
			// 
			// valveToolStripMenuItem2
			// 
			this->valveToolStripMenuItem2->Name = L"valveToolStripMenuItem2";
			this->valveToolStripMenuItem2->Size = System::Drawing::Size(107, 22);
			this->valveToolStripMenuItem2->Text = L"Valve";
			this->valveToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::valveToolStripMenuItem2_Click);
			// 
			// hCToolStripMenuItem2
			// 
			this->hCToolStripMenuItem2->Name = L"hCToolStripMenuItem2";
			this->hCToolStripMenuItem2->Size = System::Drawing::Size(107, 22);
			this->hCToolStripMenuItem2->Text = L"HC";
			this->hCToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::hCToolStripMenuItem2_Click);
			// 
			// aIToolStripMenuItem2
			// 
			this->aIToolStripMenuItem2->Name = L"aIToolStripMenuItem2";
			this->aIToolStripMenuItem2->Size = System::Drawing::Size(107, 22);
			this->aIToolStripMenuItem2->Text = L"AI";
			this->aIToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::aIToolStripMenuItem2_Click);
			// 
			// motorToolStripMenuItem2
			// 
			this->motorToolStripMenuItem2->Name = L"motorToolStripMenuItem2";
			this->motorToolStripMenuItem2->Size = System::Drawing::Size(107, 22);
			this->motorToolStripMenuItem2->Text = L"Motor";
			this->motorToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::motorToolStripMenuItem2_Click);
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
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(853, 301);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"IO_list";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(853, 301);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Objects";
			this->tabPage3->UseVisualStyleBackColor = true;
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
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"IO_list_manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Design_grid))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}

			 //menu file
//empty
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;	
		int a = this->tabControl1->SelectedIndex;
		switch (a)
		{
		case 0:	Project_save_data(true);
			break;
		case 1:	Display_no_function(buttonName);
			break;
		case 2:	Display_no_function(buttonName);
			break;
		}
		
	}
//empty
	private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		int a = this->tabControl1->SelectedIndex;
		switch (a)
		{
		case 0:	Project_Load_data();;
			break;
		case 1:	Display_no_function(buttonName);
			break;
		case 2:	Display_no_function(buttonName);
			break;
		}		
	}
//empty
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		IOlistautomation::AboutForm about;
		about.ShowDialog();
	}
//function done
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		strcpy_s(info_txt, sizeof info_txt, "Iseieta is aplikacijos paspaudus Exit");
		info_write(info_txt);
		Application::Exit();
	}

			 //menu Project
//function done
	private: System::Void designToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		if (Project_read_data() == 0)
		{
			if (Project_put_data_listview() == 0)
			{
				Signals_get_data_design();
			}
		}

	}
//empty
	private: System::Void iOCompareToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//function done
	private: System::Void transferDataToSignalsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Signals_get_data_design();
	}
//empty
	private: System::Void beckhoffToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void xAToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void siemensToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void schneiderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void systemPlatformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void winCCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void lTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void lVToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void eNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void rUToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}


			 //menu Signals
//empty
	private: System::Void kKSEditToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void findFunctionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}


			 //menu uniques
//empty
	private: System::Void findUniquesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void findObjectsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void correctCommentsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void transferToSignalsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}


			 //menu Declare
//empty
	private: System::Void pIDToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void valveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void hCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void aIToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void motorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void fCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}


			 //menu IO
//empty
	private: System::Void createIOToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}


			 //menu instance
//empty
	private: System::Void pIDToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void valveToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void hCToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void aIToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void motorToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}



			 //menu SCADA
//empty
	private: System::Void pIDToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void valveToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void hCToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void aIToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}
//empty
	private: System::Void motorToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ buttonName = safe_cast<ToolStripMenuItem^>(sender)->Text;
		Display_no_function(buttonName);
	}



};
}

public ref class GlobalForm {
public:
	static IOlistautomation::MainWindow^ forma = nullptr;
};