#include "../gantoApi.cpp" //@@@ added things @@@
#include <iostream>
#include <string>
#include <filesystem>

#pragma once

namespace GantoGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			initializeData("");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBoxSort;
	private: System::Windows::Forms::Button^ sort_button;


	private: System::Windows::Forms::Label^ temp_label;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::ListBox^ listBox7;
	private: System::Windows::Forms::ListBox^ listBox8;
	private: System::Windows::Forms::ListBox^ listBox9;
	private: System::Diagnostics::EventLog^ eventLog1;
	private: System::Windows::Forms::VScrollBar^ vScrollBar1;
	private: System::Windows::Forms::VScrollBar^ vScrollBar2;
	private: System::Windows::Forms::Button^ testingbutton;


	private: System::Windows::Forms::ListView^ listView1;



	private: System::Windows::Forms::Button^ testingbutton2;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::ListView^ listView2;



	private: System::Windows::Forms::Button^ runQuery;
	private: System::Windows::Forms::ListView^ listView3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSort = (gcnew System::Windows::Forms::ComboBox());
			this->sort_button = (gcnew System::Windows::Forms::Button());
			this->temp_label = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->vScrollBar2 = (gcnew System::Windows::Forms::VScrollBar());
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			this->testingbutton = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->testingbutton2 = (gcnew System::Windows::Forms::Button());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->runQuery = (gcnew System::Windows::Forms::Button());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(658, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(54, 24);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(71, 372);
			this->listBox1->TabIndex = 5;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(766, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"TableList";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1096, 253);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Query Results";
			// 
			// comboBoxSort
			// 
			this->comboBoxSort->FormattingEnabled = true;
			this->comboBoxSort->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"> 90", L"< 30" });
			this->comboBoxSort->Location = System::Drawing::Point(1287, 188);
			this->comboBoxSort->Name = L"comboBoxSort";
			this->comboBoxSort->Size = System::Drawing::Size(121, 24);
			this->comboBoxSort->TabIndex = 8;
			// 
			// sort_button
			// 
			this->sort_button->Location = System::Drawing::Point(153, 330);
			this->sort_button->Name = L"sort_button";
			this->sort_button->Size = System::Drawing::Size(102, 34);
			this->sort_button->TabIndex = 9;
			this->sort_button->Text = L"Run Query Operation";
			this->sort_button->UseVisualStyleBackColor = true;
			this->sort_button->Click += gcnew System::EventHandler(this, &MyForm::sort_button_Click);
			// 
			// temp_label
			// 
			this->temp_label->AutoSize = true;
			this->temp_label->Location = System::Drawing::Point(94, 458);
			this->temp_label->Name = L"temp_label";
			this->temp_label->Size = System::Drawing::Size(100, 16);
			this->temp_label->TabIndex = 10;
			this->temp_label->Text = L"Current Number";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(3, 3);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(71, 372);
			this->listBox2->TabIndex = 11;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(23, 358);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(42, 20);
			this->radioButton1->TabIndex = 12;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"==";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(23, 384);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(35, 20);
			this->radioButton2->TabIndex = 13;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L">";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(23, 410);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(42, 20);
			this->radioButton3->TabIndex = 14;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L">=";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(87, 358);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(35, 20);
			this->radioButton4->TabIndex = 15;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"<";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(87, 384);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(42, 20);
			this->radioButton5->TabIndex = 16;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"<=";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(37, 477);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(209, 56);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Value = 50;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 330);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 16);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Operations";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->listBox1);
			this->flowLayoutPanel1->Controls->Add(this->listBox3);
			this->flowLayoutPanel1->Controls->Add(this->listBox4);
			this->flowLayoutPanel1->Controls->Add(this->listBox5);
			this->flowLayoutPanel1->Controls->Add(this->vScrollBar1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(769, 272);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(324, 400);
			this->flowLayoutPanel1->TabIndex = 18;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Location = System::Drawing::Point(80, 3);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(70, 372);
			this->listBox3->TabIndex = 0;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox3_SelectedIndexChanged);
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 16;
			this->listBox4->Location = System::Drawing::Point(156, 3);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(67, 372);
			this->listBox4->TabIndex = 1;
			this->listBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox4_SelectedIndexChanged);
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 16;
			this->listBox5->Location = System::Drawing::Point(229, 3);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(64, 372);
			this->listBox5->TabIndex = 2;
			this->listBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox5_SelectedIndexChanged);
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(296, 0);
			this->vScrollBar1->Maximum = 1000;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(28, 391);
			this->vScrollBar1->TabIndex = 6;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar1_Scroll);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->listBox2);
			this->flowLayoutPanel2->Controls->Add(this->listBox7);
			this->flowLayoutPanel2->Controls->Add(this->listBox8);
			this->flowLayoutPanel2->Controls->Add(this->listBox9);
			this->flowLayoutPanel2->Controls->Add(this->vScrollBar2);
			this->flowLayoutPanel2->Location = System::Drawing::Point(1099, 272);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(335, 400);
			this->flowLayoutPanel2->TabIndex = 19;
			// 
			// listBox7
			// 
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 16;
			this->listBox7->Location = System::Drawing::Point(80, 3);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(70, 372);
			this->listBox7->TabIndex = 0;
			// 
			// listBox8
			// 
			this->listBox8->FormattingEnabled = true;
			this->listBox8->ItemHeight = 16;
			this->listBox8->Location = System::Drawing::Point(156, 3);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(67, 372);
			this->listBox8->TabIndex = 1;
			// 
			// listBox9
			// 
			this->listBox9->FormattingEnabled = true;
			this->listBox9->ItemHeight = 16;
			this->listBox9->Location = System::Drawing::Point(229, 3);
			this->listBox9->Name = L"listBox9";
			this->listBox9->Size = System::Drawing::Size(64, 372);
			this->listBox9->TabIndex = 2;
			// 
			// vScrollBar2
			// 
			this->vScrollBar2->Location = System::Drawing::Point(296, 0);
			this->vScrollBar2->Maximum = 1000;
			this->vScrollBar2->Name = L"vScrollBar2";
			this->vScrollBar2->Size = System::Drawing::Size(25, 391);
			this->vScrollBar2->TabIndex = 12;
			this->vScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar2_Scroll);
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			this->eventLog1->EntryWritten += gcnew System::Diagnostics::EntryWrittenEventHandler(this, &MyForm::eventLog1_EntryWritten);
			// 
			// testingbutton
			// 
			this->testingbutton->Location = System::Drawing::Point(813, 81);
			this->testingbutton->Name = L"testingbutton";
			this->testingbutton->Size = System::Drawing::Size(97, 34);
			this->testingbutton->TabIndex = 20;
			this->testingbutton->Text = L"testingbutton";
			this->testingbutton->UseVisualStyleBackColor = true;
			this->testingbutton->Click += gcnew System::EventHandler(this, &MyForm::testingbutton_Click);
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(24, 63);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(149, 149);
			this->listView1->TabIndex = 23;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// testingbutton2
			// 
			this->testingbutton2->Location = System::Drawing::Point(1318, 113);
			this->testingbutton2->Name = L"testingbutton2";
			this->testingbutton2->Size = System::Drawing::Size(97, 34);
			this->testingbutton2->TabIndex = 24;
			this->testingbutton2->Text = L"testingbutton2";
			this->testingbutton2->UseVisualStyleBackColor = true;
			this->testingbutton2->Click += gcnew System::EventHandler(this, &MyForm::testingbutton2_Click);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(87, 407);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(38, 20);
			this->radioButton6->TabIndex = 25;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"!=";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton6_CheckedChanged);
			// 
			// listView2
			// 
			this->listView2->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->listView2->CheckBoxes = true;
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(282, 63);
			this->listView2->Name = L"listView2";
			this->listView2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listView2->Size = System::Drawing::Size(346, 220);
			this->listView2->TabIndex = 26;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// runQuery
			// 
			this->runQuery->Location = System::Drawing::Point(179, 63);
			this->runQuery->Name = L"runQuery";
			this->runQuery->Size = System::Drawing::Size(97, 34);
			this->runQuery->TabIndex = 27;
			this->runQuery->Text = L"Run Query";
			this->runQuery->UseVisualStyleBackColor = true;
			this->runQuery->Click += gcnew System::EventHandler(this, &MyForm::runQuery_Click);
			// 
			// listView3
			// 
			this->listView3->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->listView3->CheckBoxes = true;
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(282, 313);
			this->listView3->Name = L"listView3";
			this->listView3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listView3->Size = System::Drawing::Size(346, 220);
			this->listView3->TabIndex = 28;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->View = System::Windows::Forms::View::Details;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 16);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Tables";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(283, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 16);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Data";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(282, 290);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 16);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Query Data";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(658, 559);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listView3);
			this->Controls->Add(this->runQuery);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->testingbutton2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->testingbutton);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->temp_label);
			this->Controls->Add(this->sort_button);
			this->Controls->Add(this->comboBoxSort);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		api* t = new api();
		//vector<string>* tablenames;
		//vector<vector<string>>* columnnames;

		// need this function to initialize everything
	private: System::Void initializeData(string filename) {
		try {
			if (!filename.empty()) {
				listView1->Columns->Clear();
				listView1->Items->Clear();
				listView1->Clear();
				t->apiLoadFile(filename);
				vector<string> tabnames = t->getTableNames();
				vector<vector<string>> columnnames;
				for (int i = 0; i < tabnames.size(); i++) {
					string tname = tabnames[i];
					String^ tempconv = gcnew String(tname.c_str());
					listView1->Items->Add(tempconv);
					columnnames.push_back(t->getColumnNames(tname));
				}
			}
		}
		catch (Exception^ e) {
			return;
		}
		//tablenames = &tabnames;
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		string path = filesystem::current_path().generic_string();
		//openFileDialog1->InitialDirectory = path;
		openFileDialog1->Filter = "json files (*.json)|*.json";
		//openFileDialog1->ShowDialog();

		/*Stream^ mystream;*/
		listView1->Clear();

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//read file stuff here
			string convstr = "";
			String^ str = openFileDialog1->FileName;
			MarshalString(str, convstr);
			listView1->Items->Clear();
			listView1->Columns->Clear();
			listView1->Clear();
			initializeData(convstr);
		}
		//mystream->Close();
	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->ShowDialog();
		//t->apiSaveToFile();
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox3->TopIndex = listBox1->TopIndex;
		listBox4->TopIndex = listBox1->TopIndex;
		listBox5->TopIndex = listBox1->TopIndex;
	}
	private: System::Void sort_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//listBox2->Items->Clear();
		//listBox7->Items->Clear();
		//listBox8->Items->Clear();
		//listBox9->Items->Clear();
		//vector<vector<variant<string, double>>> returned;
		//if (comboBoxSort->SelectedIndex == 0) {
		//	returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 1, 90.0} });
		//}
		//else if (comboBoxSort->SelectedIndex == 1) {
		//	returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 3, 30.0} });
		//}
		//for (int i = 0; i < returned.size(); i++) {
		//	string temp = to_string(get<double>(returned[i][0]));
		//	String^ tempconv = gcnew String(temp.c_str());
		//	listBox2->Items->Add(tempconv);
		//}

		string convstr;
		ListViewItem^ selitem1;
		if (listView1->SelectedItems->Count == 0)
			return;
		selitem1 = listView1->SelectedItems[0];
		String^ str = selitem1->Text;
		MarshalString(str, convstr);
		vector<string> columnnames = t->getColumnNames(convstr);

		try {
			if (listView2->CheckedIndices[0] == 32766)
				bool placeholder;
		}
		catch (Exception^ e) {
			return;
		}
		int index = listView2->CheckedIndices[0];

		//ListView::SelectedIndexCollection^ indexes = listView2->SelectedIndices;

		vector<vector<variant<string, double>>> returned;
		double num = trackBar1->Value;

		bool firstrun = true;
		if (radioButton1->Checked) {
			listView3->Clear();
			listView3->Columns->Add(gcnew String("Columns"));
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j]}, {{{columnnames[index]}, 0, num}});
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
		else if (radioButton2->Checked) {
			listView3->Clear();
			listView3->Columns->Add(gcnew String("Columns"));
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j] }, { {{columnnames[index]}, 1, num} });
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
		else if (radioButton3->Checked) {
			listView3->Clear();
			listView3->Columns->Add(gcnew String("Columns"));
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j] }, { {{columnnames[index]}, 2, num} });
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
		else if (radioButton4->Checked) {
			listView3->Clear();
			listView3->Columns->Add(gcnew String("Columns"));
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j]}, {{{columnnames[index]}, 3, num}});
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
		else if (radioButton5->Checked) {
			listView3->Clear();
			listView3->Columns->Add(gcnew String("Columns"));
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j]}, {{{columnnames[index]}, 4, num}});
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
		else if (radioButton6->Checked) {
			listView3->Clear();
			for (int j = 0; j < columnnames.size(); j++) {
				ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[j].c_str()));
				returned = t->apiReadEntry(convstr, { columnnames[j] }, { {{columnnames[index]}, 3, num} });
				for (int i = 0; i < returned.size(); i++) {
					if (firstrun)
						listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
					try {
						string temp = get<string>(returned[i][0]);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
					catch (Exception^ e) {
						string temp = to_string(get<double>(returned[i][0]));
						temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
						String^ tempconv = gcnew String(temp.c_str());
						lvitem->SubItems->Add(tempconv);
					}
				}
				firstrun = false;
				listView3->Items->Add(lvitem);
			}
		}
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		vector<vector<variant<string, double>>> returned, returned1, returned2, returned3;
		double num = trackBar1->Value;
		returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 0, num} });
		returned1 = t->apiReadEntry("LargeTable", { "String" }, { {"Number", 0, num} });
		returned2 = t->apiReadEntry("LargeTable", { "KeyValue" }, { {"Number", 0, num} });
		returned3 = t->apiReadEntry("LargeTable", { "Other Number" }, { {"Number", 0, num} });
		for (int i = 0; i < returned.size(); i++) {
			string temp = to_string(get<double>(returned[i][0]));
			String^ tempconv = gcnew String(temp.c_str());
			listBox2->Items->Add(tempconv);

			temp = get<string>(returned1[i][0]);
			tempconv = gcnew String(temp.c_str());
			listBox7->Items->Add(tempconv);

			temp = to_string(get<double>(returned2[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox8->Items->Add(tempconv);

			temp = to_string(get<double>(returned3[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox9->Items->Add(tempconv);
		}
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		vector<vector<variant<string, double>>> returned, returned1, returned2, returned3;
		double num = trackBar1->Value;
		returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 1, num} });
		returned1 = t->apiReadEntry("LargeTable", { "String" }, { {"Number", 1, num} });
		returned2 = t->apiReadEntry("LargeTable", { "KeyValue" }, { {"Number", 1, num} });
		returned3 = t->apiReadEntry("LargeTable", { "Other Number" }, { {"Number", 1, num} });
		for (int i = 0; i < returned.size(); i++) {
			string temp = to_string(get<double>(returned[i][0]));
			String^ tempconv = gcnew String(temp.c_str());
			listBox2->Items->Add(tempconv);

			temp = get<string>(returned1[i][0]);
			tempconv = gcnew String(temp.c_str());
			listBox7->Items->Add(tempconv);

			temp = to_string(get<double>(returned2[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox8->Items->Add(tempconv);

			temp = to_string(get<double>(returned3[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox9->Items->Add(tempconv);
		}
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		vector<vector<variant<string, double>>> returned, returned1, returned2, returned3;
		double num = trackBar1->Value;
		returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 2, num} });
		returned1 = t->apiReadEntry("LargeTable", { "String" }, { {"Number", 2, num} });
		returned2 = t->apiReadEntry("LargeTable", { "KeyValue" }, { {"Number", 2, num} });
		returned3 = t->apiReadEntry("LargeTable", { "Other Number" }, { {"Number", 2, num} });
		for (int i = 0; i < returned.size(); i++) {
			string temp = to_string(get<double>(returned[i][0]));
			String^ tempconv = gcnew String(temp.c_str());
			listBox2->Items->Add(tempconv);

			temp = get<string>(returned1[i][0]);
			tempconv = gcnew String(temp.c_str());
			listBox7->Items->Add(tempconv);

			temp = to_string(get<double>(returned2[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox8->Items->Add(tempconv);

			temp = to_string(get<double>(returned3[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox9->Items->Add(tempconv);
		}
	}
	private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		vector<vector<variant<string, double>>> returned, returned1, returned2, returned3;
		double num = trackBar1->Value;
		returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 3, num} });
		returned1 = t->apiReadEntry("LargeTable", { "String" }, { {"Number", 3, num} });
		returned2 = t->apiReadEntry("LargeTable", { "KeyValue" }, { {"Number", 3, num} });
		returned3 = t->apiReadEntry("LargeTable", { "Other Number" }, { {"Number", 3, num} });
		for (int i = 0; i < returned.size(); i++) {
			string temp = to_string(get<double>(returned[i][0]));
			String^ tempconv = gcnew String(temp.c_str());
			listBox2->Items->Add(tempconv);

			temp = get<string>(returned1[i][0]);
			tempconv = gcnew String(temp.c_str());
			listBox7->Items->Add(tempconv);

			temp = to_string(get<double>(returned2[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox8->Items->Add(tempconv);

			temp = to_string(get<double>(returned3[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox9->Items->Add(tempconv);
		}
	}
	private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		vector<vector<variant<string, double>>> returned, returned1, returned2, returned3;
		double num = trackBar1->Value;
		returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 4, num} });
		returned1 = t->apiReadEntry("LargeTable", { "String" }, { {"Number", 4, num} });
		returned2 = t->apiReadEntry("LargeTable", { "KeyValue" }, { {"Number", 4, num} });
		returned3 = t->apiReadEntry("LargeTable", { "Other Number" }, { {"Number", 4, num} });
		for (int i = 0; i < returned.size(); i++) {
			string temp = to_string(get<double>(returned[i][0]));
			String^ tempconv = gcnew String(temp.c_str());
			listBox2->Items->Add(tempconv);

			temp = get<string>(returned1[i][0]);
			tempconv = gcnew String(temp.c_str());
			listBox7->Items->Add(tempconv);

			temp = to_string(get<double>(returned2[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox8->Items->Add(tempconv);

			temp = to_string(get<double>(returned3[i][0]));
			temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
			tempconv = gcnew String(temp.c_str());
			listBox9->Items->Add(tempconv);
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		temp_label->Text = System::Convert::ToString(trackBar1->Value);
	}
	private: System::Void listBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox3->TopIndex = listBox5->TopIndex;
		listBox4->TopIndex = listBox5->TopIndex;
		listBox1->TopIndex = listBox5->TopIndex;
	}

	private: System::Void eventLog1_EntryWritten(System::Object^ sender, System::Diagnostics::EntryWrittenEventArgs^ e) {
	}
	private: System::Void vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		listBox1->TopIndex = vScrollBar1->Value;
		listBox3->TopIndex = listBox1->TopIndex;
		listBox4->TopIndex = listBox1->TopIndex;
		listBox5->TopIndex = listBox1->TopIndex;
	}
	private: System::Void vScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		listBox2->TopIndex = vScrollBar2->Value;
		listBox7->TopIndex = listBox2->TopIndex;
		listBox8->TopIndex = listBox2->TopIndex;
		listBox9->TopIndex = listBox2->TopIndex;
	}
	private: System::Void listBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox1->TopIndex = listBox3->TopIndex;
		listBox4->TopIndex = listBox3->TopIndex;
		listBox5->TopIndex = listBox3->TopIndex;
	}
	private: System::Void listBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		listBox3->TopIndex = listBox4->TopIndex;
		listBox1->TopIndex = listBox4->TopIndex;
		listBox5->TopIndex = listBox4->TopIndex;
	}
	private: System::Void testingbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		string convstr;
		ListViewItem^ selitem1;
		if (listView1->SelectedItems->Count == 0)
			return;
		selitem1 = listView1->SelectedItems[0];
		String^ str = selitem1->Text;
		MarshalString(str, convstr);
		vector<string> columnnames = t->getColumnNames(convstr);

		try {
			if (listView2->CheckedIndices[0] == 32766)
				bool placeholder;
		}
		catch (Exception^ e) {
			return;
		}
		int index = listView2->CheckedIndices[0];

		vector<vector<variant<string, double>>> returned;

		//returned = t->apiReadEntry("LargeTable", { "Number" }, { {"Number", 1, num} });
		//t->apiJoinEntry(convstr, {columnnames[});

		//listView3->Clear();
		//listView3->Columns->Add(gcnew String("Columns"));
		////for (int j = 0; j < columnnames[index].size(); j++) {
		//ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[index].c_str()));
		//returned = t->apiReadEntry(convstr, { columnnames[index] }, { {{columnnames[index]}, 3, num} });
		//for (int i = 0; i < returned.size(); i++) {
		//	if (firstrun)
		//		listView3->Columns->Add(gcnew String(to_string(i + 1).c_str()));
		//	try {
		//		string temp = get<string>(returned[i][0]);
		//		String^ tempconv = gcnew String(temp.c_str());
		//		lvitem->SubItems->Add(tempconv);
		//	}
		//	catch (Exception^ e) {
		//		string temp = to_string(get<double>(returned[i][0]));
		//		temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
		//		String^ tempconv = gcnew String(temp.c_str());
		//		lvitem->SubItems->Add(tempconv);
		//	}
		//}
		//firstrun = false;
		//listView3->Items->Add(lvitem);
		
		
		//int num = 7;
		/*this->listBox7->FormattingEnabled = true;
		this->listBox7->ItemHeight = 16;
		this->listBox7->Location = System::Drawing::Point(80, 3);
		this->listBox7->Name = L"listBox7";
		this->listBox7->Size = System::Drawing::Size(70, 388);
		this->listBox7->TabIndex = 0;
		this->listBox7 = (gcnew System::Windows::Forms::ListBox());*/
		//vector<System::Windows::Forms::ListBox^> testboxes;
		//for (int i = 0; i < num; i++) {
			//testboxes.push_back(gcnew System::Windows::Forms::ListBox());
		//}
		//for (int i = 0; i < testboxes.size(); i++) {
			//testboxes[i]->Location = System::Drawing::Point(1060, 70 + i * 10);
			//listBox7->Location
		//}
		/*String^ lvitemname2 = "Zach";
		ListViewItem^ lvitem2 = gcnew ListViewItem(lvitemname2);
		lvitem2->SubItems->Add("Jeb");
		lvitem2->SubItems->Add("Farquad");
		listView1->Items->Add(lvitem2);

		String^ lvitemname = "Bob";
		ListViewItem^ lvitem = gcnew ListViewItem(lvitemname);
		lvitem->SubItems->Add("Billy");
		lvitem->SubItems->Add("Canada");
		listView1->Items->Add(lvitem);*/
		//listView1->Columns->Add("pee", -2, HorizontalAlignment::Left);
		//int index = listView1->Columns->IndexOfKey("pee");
		//listView1->Columns->Insert();
		//listView1->Columns->Insert(0, "pee");		//adds to position but add is better
		//listView1->Columns->Insert(0, "za");
		//listView1->Columns->Add("poo", -2, HorizontalAlignment::Left);
		//listView1->Columns->Add("puu", -2, HorizontalAlignment::Left);
	}

	//converts system string to std string
	void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void testingbutton2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->FocusedItem) {
			listView1->Items->Remove(listView1->SelectedItems[0]);
			//listView1->FocusedItem->ToString() != ""
		}

	}
	private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void runQuery_Click(System::Object^ sender, System::EventArgs^ e) {
		listView2->Clear();
		vector<vector<variant<string, double>>> returned;
		string convstr;
		ListViewItem^ selitem;
		if (listView1->SelectedItems->Count == 0)
			return;
		selitem = listView1->SelectedItems[0];
		String^ str = selitem->Text;
		MarshalString(str, convstr);
		//get index of selected item
		int index;
		vector<string> tabnames = t->getTableNames();
		for (int i = 0; i < tabnames.size(); i++) {
			if (tabnames[i] == convstr) {
				index = i;
			}
		}
		vector<vector<string>> columnnames;
		for (int i = 0; i < tabnames.size(); i++) {
			string tname = tabnames[i];
			String^ tempconv = gcnew String(tname.c_str());
			columnnames.push_back(t->getColumnNames(tname));
		}

		string tpe = "0";
		bool firstrun = true;

		listView2->Columns->Add(gcnew String("Columns"));
		for (int i = 0; i < columnnames[index].size(); i++) {
			ListViewItem^ lvitem = gcnew ListViewItem(gcnew String(columnnames[index][i].c_str()));
			returned = t->apiReadEntry(convstr, { columnnames[index][i] }, {});
			for (int k = 0; k < returned.size(); k++) {
				if (firstrun)
					listView2->Columns->Add(gcnew String(to_string(k + 1).c_str()));
				try {
					string temp = get<string>(returned[k][0]);
					String^ tempconv = gcnew String(temp.c_str());
					lvitem->SubItems->Add(tempconv);
				}
				catch (Exception^ e) {
					string temp = to_string(get<double>(returned[k][0]));
					temp = temp.erase(temp.find_last_not_of('0') + 2, string::npos);
					String^ tempconv = gcnew String(temp.c_str());
					lvitem->SubItems->Add(tempconv);
				}
			}
			firstrun = false;
			listView2->Items->Add(lvitem);
		}
	}
	};
}
