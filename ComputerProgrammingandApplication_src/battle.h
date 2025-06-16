#pragma once
#include <stdio.h>
#include <chrono>
#include <thread>
#include "data_format.h"
using namespace std;

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// battle 的摘要
	/// </summary>
	public ref class battle : public System::Windows::Forms::Form
	{
	public:
		battle(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~battle()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ button5;




	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Honeydew;
			this->panel1->Controls->Add(this->label21);
			this->panel1->Controls->Add(this->label20);
			this->panel1->Controls->Add(this->label19);
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(9, 450);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(606, 340);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &battle::panel1_Paint);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(429, 201);
			this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(71, 25);
			this->label21->TabIndex = 12;
			this->label21->Text = L"label21";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(334, 201);
			this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(71, 25);
			this->label20->TabIndex = 11;
			this->label20->Text = L"label20";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(236, 201);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(71, 25);
			this->label19->TabIndex = 10;
			this->label19->Text = L"label19";
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(434, 99);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(90, 100);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 9;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &battle::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(339, 99);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(90, 100);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 8;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &battle::pictureBox4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(241, 99);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(94, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &battle::pictureBox1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(339, 255);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"label4";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(241, 255);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(94, 56);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Change\r\nAttitude";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &battle::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(499, 255);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(94, 56);
			this->button3->TabIndex = 4;
			this->button3->Text = L"End Turn";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &battle::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(339, 48);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 48);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Heal";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &battle::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(241, 48);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Attack";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &battle::button1_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(2, 48);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(225, 240);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(11, 12);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 27);
			this->label3->TabIndex = 0;
			this->label3->Text = L"label3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(653, 354);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 31);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::ForestGreen;
			this->progressBar1->Location = System::Drawing::Point(9, 414);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(466, 22);
			this->progressBar1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Honeydew;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(478, 410);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 27);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &battle::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(512, 265);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"system clock";
			// 
			// progressBar2
			// 
			this->progressBar2->BackColor = System::Drawing::Color::Gray;
			this->progressBar2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->progressBar2->Location = System::Drawing::Point(118, 326);
			this->progressBar2->Margin = System::Windows::Forms::Padding(2);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(390, 12);
			this->progressBar2->TabIndex = 8;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(118, 10);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(390, 312);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(652, 64);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(142, 35);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Boss Data:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(652, 120);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(67, 27);
			this->label8->TabIndex = 11;
			this->label8->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(652, 160);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 27);
			this->label9->TabIndex = 12;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(652, 200);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(78, 27);
			this->label10->TabIndex = 13;
			this->label10->Text = L"label10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(652, 240);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(78, 27);
			this->label11->TabIndex = 14;
			this->label11->Text = L"label11";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(772, 10);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(129, 35);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Dialogue:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(652, 414);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(89, 31);
			this->label13->TabIndex = 16;
			this->label13->Text = L"label13";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(652, 280);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(78, 27);
			this->label14->TabIndex = 17;
			this->label14->Text = L"label14";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &battle::timer2_Tick_1);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(512, 10);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 25);
			this->label6->TabIndex = 18;
			this->label6->Text = L"label6";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(654, 535);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(78, 27);
			this->label15->TabIndex = 19;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(654, 585);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(78, 27);
			this->label16->TabIndex = 20;
			this->label16->Text = L"label16";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(512, 319);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(78, 27);
			this->label17->TabIndex = 21;
			this->label17->Text = L"label17";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Yu Mincho Demibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(46, 348);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(89, 30);
			this->label18->TabIndex = 22;
			this->label18->Text = L"label18";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(658, 639);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(364, 151);
			this->button5->TabIndex = 23;
			this->button5->Text = L"You win!\r\nClick here to \r\nclose this window.";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &battle::button5_Click);
			// 
			// battle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1034, 801);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->panel1);
			this->Name = L"battle";
			this->Text = L"battle";
			this->Load += gcnew System::EventHandler(this, &battle::battle_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		void BattleSceneInitialize() {
			this->button5->Hide();
			this->label18->Hide();
			this->timer2->Stop();
			this->label5->Hide();
			this->label13->Hide();
			LoadImage("boss_shadow.png", pictureBox2);
			kanon.atk_point = point;
			enemy_clock = 100;
			kanon.attitude = 1;
			kanon.cd = 0;
			kanon_changed_attack = kanon.total_atk();
			kanon.hp = kanon.total_maxhp();
			progressBar1->Maximum = kanon.total_maxhp();
			//progressBar1->Value = kanon.hp;
			this->label1->Text = (Convert::ToString(kanon.hp)+" / "+ Convert::ToString(kanon.total_maxhp()));
			LoadImage("character.png", pictureBox3);
			this->label3->Text = "Remaining Actions: " + Convert::ToString(kanon.atk_point.point);
			LoadImage("small_hp_potion.png", pictureBox1);
			LoadImage("big_hp_potion.png", pictureBox4);
			LoadImage("attack_potion.png", pictureBox5);
			ControlPanalHide();
			PotionPanalHide();
		}

		void Stage1() {

			enemy_list.clear();
			small_slime.atk = 10;
			small_slime.def = 0;
			small_slime.max_hp = 50;
			small_slime.hp = small_slime.max_hp;
			small_slime.cd = 2;
			small_slime.cd_plus = 1;
			enemy_list.push_back(small_slime);
			this->progressBar2->Location = System::Drawing::Point(245, 330);
			this->progressBar2->Size = System::Drawing::Size(130, 15);

			LoadImage("small_slime.png", pictureBox2);
			progressBar2->Maximum = small_slime.max_hp;
			progressBar2->Value = small_slime.hp;
			
			this->label17->Hide();
		}

		void Stage2() {

		}

		void BossStage() {
			string name = "Galaxy";
			galaxy.name = name;
			galaxy.atk = 4000;
			galaxy.def = 800;
			galaxy.max_hp = 20000;
			galaxy.cd = 1;
			galaxy.cd_plus = 1;
			galaxy.hp = galaxy.max_hp;
			galaxy.effect_80 = 1;
			galaxy.effect_60 = 1;
			galaxy.effect_50 = 1;
			galaxy.effect_40 = 1;
			galaxy.effect_20 = 1;
			galaxy.effect_10 = 1;
			galaxy.is_alive = true;
			//LoadImage("boss.png", pictureBox2);
			progressBar2->Maximum = galaxy.max_hp;
			progressBar2->Value = galaxy.hp;
		}

		void Displayer() {
			this->label1->Text = (Convert::ToString(kanon.hp) + " / " + Convert::ToString(kanon.total_maxhp()));
			this->label3->Text = "Remaining Actions: " + Convert::ToString(kanon.atk_point.point);
			progressBar1->Value = kanon.hp;
			this->label16->Text = "Your atk: " + Convert::ToString(kanon_changed_attack);
			this->label19->Text = "Hold: " + Convert::ToString(small_hp_potion.amount);
			this->label20->Text = "Hold: " + Convert::ToString(big_hp_potion.amount);
			this->label21->Text = "Hold: " + Convert::ToString(attack_potion.amount);
			if (stage == 1 && system_counter >= 5) {
				progressBar2->Value = small_slime.hp;
			}
			if (stage == 3 && system_counter >= 5) {
				progressBar2->Value = galaxy.hp;
			}
			if (kanon.attitude == 1) {
				this->label4->Text = "Now Attitude:\n      Attack";
			}
			if (kanon.attitude == 0) {
				this->label4->Text = "Now Attitude:\n      Defense";
			}
		}

		void PlayerAttack() {
			int damage = 0;
			if (stage == 1) {
				damage = DamageCounter(kanon_changed_attack, small_slime.def);
				if (damage >= small_slime.hp) {
					small_slime.hp = 0;
					small_slime.is_alive = false;
				}
				else {
					small_slime.hp = small_slime.hp - damage;
				}
				
			}
			if (stage == 3) {
				damage = DamageCounter(kanon_changed_attack, galaxy.def, kanon.accessory.crit_rate, kanon.accessory.crit_dmg, kanon.attitude);
				if (galaxy.effect_80 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.601) {
					damage = 0;
				}
				if (galaxy.effect_60 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.501) {
					damage = 0;
				}
				if (galaxy.effect_50 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.401) {
					damage = 0;
				}
				if (galaxy.effect_40 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.201) {
					damage = 0;
				}
				if (galaxy.effect_20 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.101) {
					damage = 0;
				}
				if (galaxy.effect_10 == 1 && galaxy.hp - damage <= galaxy.max_hp * 0.001) {
					damage = 0;
				}
				if (damage >= galaxy.hp) {
					galaxy.hp = 0;
					galaxy.is_alive = false;
				}
				else {
					galaxy.hp = galaxy.hp - damage;
				}
			}
			this->label5->Show();
			this->label5->Text = "Damage Caused:  " + Convert::ToString(damage);
		}

		int EnemyAttack(int enemy_atk) {
			int kanon_def;
			if (kanon.attitude == 0) {
				kanon_def = kanon.total_def() * 1.1;
			}
			else {
				kanon_def = kanon.total_def() * 0.9;
			}
			int damage = DamageCounter(enemy_atk, kanon_def);

			if (damage >= kanon.hp) {
				kanon.hp = 0;
			}
			else {
				kanon.hp = kanon.hp - damage;
			}
			return damage;
		}

		int EnemyAttack(int enemy_atk, float crit) {
			int kanon_def;
			if (kanon.attitude == 0) {
				kanon_def = kanon.total_def() * 1.1;
			}
			else {
				kanon_def = kanon.total_def() * 0.9;
			}
			int damage = DamageCounter(enemy_atk, kanon_def, crit);

			if (damage >= kanon.hp) {
				kanon.hp = 0;
			}
			else {
				kanon.hp = kanon.hp - damage;
			}
			return damage;
		}

		void DialogueDisplayer() {
			if (stage == 3) {
				String^ boss_name = gcnew String(galaxy.name.c_str());
				this->label8->Text = "Name:  " + boss_name;
				this->label9->Text = "ATK:  " + Convert::ToString(galaxy.atk);
				this->label10->Text = "DEF:  " + Convert::ToString(galaxy.def);
				this->label11->Text = "HP:  " + Convert::ToString(galaxy.hp);
				this->label17->Text = "CD:  " + Convert::ToString(galaxy.cd);
				
			}
			else if (stage == 1) {
				this->label9->Text = "ATK:  " + Convert::ToString(small_slime.atk);
				this->label10->Text = "DEF:  " + Convert::ToString(small_slime.def);
				this->label11->Text = "HP:  " + Convert::ToString(small_slime.hp);
				//this->label17->Text = "CD:  " + Convert::ToString(small_slime.cd);
			}
			else {
				this->label7->Hide();
				this->label8->Hide();
				this->label9->Hide();
				this->label10->Hide();
				this->label11->Hide();
			}
			if (kanon.cd == 0) {
				this->label15->Text = "Your Turn!";
			}
			else {
				this->label15->Text = "CD Remaining:  " + Convert::ToString(kanon.cd);
			}
			
			
		}

		void ControlPanalHide() {
			this->button1->Hide();
			this->button2->Hide();
			this->button3->Hide();
			this->button4->Hide();
			//this->label4->Hide();
		}

		void ControlPanalShow() {
			this->button1->Show();
			this->button2->Show();
			this->button3->Show();
			this->button4->Show();
			//this->label4->Show();
		}

		void PotionPanalShow() {
			this->pictureBox1->Show();
			this->pictureBox4->Show();
			this->pictureBox5->Show();
			this->label19->Show();
			this->label20->Show();
			this->label21->Show();
		}

		void PotionPanalHide() {
			this->pictureBox1->Hide();
			this->pictureBox4->Hide();
			this->pictureBox5->Hide();
			this->label19->Hide();
			this->label20->Hide();
			this->label21->Hide();
		}

		void EnemyTurn(vector<enemy>& enemy_list, Character& character, int& counter) {
			int amount = enemy_list.size();
			int i = counter/16;
			
			if (i < amount) {
				if (enemy_list[i].is_alive == true) {
					this->label17->Show();
					this->label17->Text = "CD:  " + Convert::ToString(enemy_list[i].cd);
					if (counter == 8 + 16*i) {
						enemy_list[i].cd = enemy_list[i].cd - 1;
					}
					
					if (counter == 15 + 16 * i) {
						if (enemy_list[i].cd == 0) {
							int enemy_damage = EnemyAttack(enemy_list[i].atk);
							this->label13->Show();
							this->label13->Text = "Hitted with Damage:  " + Convert::ToString(enemy_damage);
							enemy_list[i].cd = enemy_list[i].cd + enemy_list[i].cd_plus;
						}
					}
					
				}
				else {
					counter = counter + 16;
				}
			}
			if (counter == 16 * amount + 3) {
				character.cd--;
			}
			if (character.cd == 0 && counter == 16 * amount + 7) {
				int point = character.atk_point.point + character.atk_point.recover;
				if (point >= character.atk_point.limit) {
					character.atk_point.point = character.atk_point.limit;
				}
				else {
					character.atk_point.point = point;
				}
				ControlPanalShow();
				this->timer2->Stop();
			}
			if (character.cd != 0 && counter >= 16 * amount + 8) {
				counter = 0;
			}
			
		}

		void SingleEnemyTurn(enemy& e, Character& character, int& counter) {
			if (e.is_alive == true) {
				
				if (counter == 8) {
					e.cd = e.cd--;
				}
				if (counter == 16) {
					if (e.cd == 0) {
						int enemy_damage = EnemyAttack(e.atk);
						this->label13->Show();
						this->label13->Text = "Hitted with Damage:  " + Convert::ToString(enemy_damage);
						e.cd = e.cd + e.cd_plus;
					}
				}
			}
			
			if (counter == 19) {
				character.cd--;
			}
			if (character.cd == 0 && counter == 23) {
				int point = character.atk_point.point + character.atk_point.recover;
				if (point >= character.atk_point.limit) {
					character.atk_point.point = character.atk_point.limit;
				}
				else {
					character.atk_point.point = point;
				}
				ControlPanalShow();
				this->timer2->Stop();
			}
			if (character.cd != 0 && counter >= 24) {
				counter = 0;
			}



		}

		void BossMessage(int i) {
			this->label18->Show();
			if (i == 1) {
				this->label18->Text = "Time to show you my power!";
			}
			else if(i == 2){
				this->label18->Text = "Force of Divine Nine-tailed Fox!";
			}
			else if (i == 3) {
				this->label18->Text = "Don't run and catch it!";
			}
			else if (i == 4) {
				this->label18->Text = "For my last spell...";
			}
			else if (i == 5) {
				this->label18->Text = "Bath in resentment, disappear pathetically!";
			}
			else if (i == 6) {
				this->label18->Text = "Claw attack!";
			}
			else if (i == 7) {
				this->label18->Text = "Spirit Sphere attack!";
			}
			else if (i == 8) {
				this->label18->Text = "Nine tail thrust!";
			}
			
		}
		
		void BossMessageAnime(int i) {
			this->label18->Show();
			if (i == 10)
				this->label18->Text = "He";
			else if (i == 11)
				this->label18->Text = "Hey t";
			else if (i == 12)
				this->label18->Text = "Hey the";
			else if (i == 13)
				this->label18->Text = "Hey there, ";
			else if (i == 14)
				this->label18->Text = "Hey there, yo";
			else if (i == 15)
				this->label18->Text = "Hey there, you f";
			else if (i == 16)
				this->label18->Text = "Hey there, you fin";
			else if (i == 17)
				this->label18->Text = "Hey there, you final";
			else if (i == 18)
				this->label18->Text = "Hey there, you finally ";
			else if (i == 19)
				this->label18->Text = "Hey there, you finally co";
			else if (i >= 20 && i<=27)
				this->label18->Text = "Hey there, you finally come.";
			else if (i == 35)
				this->label18->Text = "Pl";
			else if (i == 36)
				this->label18->Text = "Play ";
			else if (i == 37)
				this->label18->Text = "Play wi";
			else if (i == 38)
				this->label18->Text = "Play with";
			else if (i == 39)
				this->label18->Text = "Play with me";
			else if (i == 40)
				this->label18->Text = "Play with me, ";
			else if (i == 41)
				this->label18->Text = "Play with me, un";
			else if (i == 42)
				this->label18->Text = "Play with me, unti";
			else if (i == 43)
				this->label18->Text = "Play with me, until o";
			else if (i == 44)
				this->label18->Text = "Play with me, until one";
			else if (i == 45)
				this->label18->Text = "Play with me, until one of";
			else if (i == 46)
				this->label18->Text = "Play with me, until one of us";
			else if (i >= 47 && i<= 55)
				this->label18->Text = "Play with me, until one of us die!";
			else
				this->label18->Text = " ";
			
		}
		

		void BossTurn() {
			String^ boss_name = gcnew String(galaxy.name.c_str());
			float crit_dmg = GenerateRandomFloat(1.8, 2.0);
			if (galaxy.is_alive == true) {
				
				if (enemy_clock == 10) {
					galaxy.cd--;
				}
				if (enemy_clock == 20) {
					if (galaxy.cd == 0) {
						if (galaxy.hp <= galaxy.max_hp * 0.8 && galaxy.effect_80 >= 1) {
							BossMessage(1);
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.6 && galaxy.effect_60 >= 1) {
							BossMessage(2);
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.5 && galaxy.effect_50 >= 1) {
							BossMessage(3);
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.4 && galaxy.effect_40 >= 1) {
							BossMessage(2);
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.2 && galaxy.effect_20 >= 1) {
							//String^ musicFilePath = "trans.wav";
							//System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(musicFilePath);
							//player->Play();
							LoadImage("boss_trans.png", pictureBox2);
							BossMessage(4);
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.1 && galaxy.effect_10 >= 1) {
							BossMessage(5);
						}
						else {
							float effect = GenerateRandomFloat(0.0, 100.0);
							float normal = GenerateRandomFloat(0.95, 1.05);
							if (effect <= 10.0) {
								BossMessage(8);
								int boss_damage = EnemyAttack(galaxy.atk* normal, crit_dmg);
								this->label13->Show();
								this->label13->Text = "Hitted By " + boss_name + ", Damage:  " + Convert::ToString(boss_damage);
							}
							else {
								if (normal <= 1.0) {
									BossMessage(6);
									int boss_damage = EnemyAttack(galaxy.atk * normal);
									this->label13->Show();
									this->label13->Text = "Hitted By " + boss_name + ", Damage:  " + Convert::ToString(boss_damage);
								}
								else {
									BossMessage(7);
									int boss_damage = EnemyAttack(galaxy.atk * normal);
									this->label13->Show();
									this->label13->Text = "Hitted By " + boss_name + ", Damage:  " + Convert::ToString(boss_damage);
								}
							}
							
						}
					}
				}
				if (enemy_clock == 30) {
					if (galaxy.cd == 0) {
						
						if (galaxy.hp <= galaxy.max_hp * 0.8 && galaxy.effect_80 >= 1) {
							galaxy.AttackChange(1.068);
							galaxy.DefenseChange(1.058);
							this->label13->Show();
							this->label13->Text = "Galaxy's ability is increased!";
							galaxy.effect_80--;
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.6 && galaxy.effect_60 >= 1) {
							galaxy.AttackChange(1.068);
							galaxy.DefenseChange(1.058);
							galaxy.DirectAttack(0.50, kanon);
							this->label13->Show();
							this->label13->Text = "Direct Attack!\nLose 50% HP!";
							galaxy.effect_60--;
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.5 && galaxy.effect_50 >= 1) {
							galaxy.AdditionalTurn(2, kanon);
							this->label13->Show();
							this->label13->Text = "You can't move for 2 rounds";
							galaxy.effect_50--;
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.4 && galaxy.effect_40 >= 1) {
							galaxy.AttackChange(1.068);
							galaxy.DefenseChange(1.058);
							galaxy.DirectAttack(0.65, kanon);
							this->label13->Show();
							this->label13->Text = "Direct Attack!\nLose 65% HP!";
							galaxy.effect_40--;
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.2 && galaxy.effect_20 >= 1) {
							galaxy.AttackChange(1.068);
							galaxy.DefenseChange(1.058);
							galaxy.AdditionalTurn(1, kanon);
							kanon.hp = kanon.hp * 0.15 + 1;
							this->label13->Show();
							this->label13->Text = "Her appearance changed!\nYou can't move for 1 round";
							galaxy.effect_20--;
						}
						else if (galaxy.hp <= galaxy.max_hp * 0.1 && galaxy.effect_10 >= 1) {
							galaxy.AttackChange(1.154);
							galaxy.DefenseChange(1.2);
							galaxy.AdditionalTurn(1, kanon);
							kanon.hp = kanon.hp * 0.20 + 1;
							galaxy.hp = galaxy.hp + galaxy.max_hp * 0.30 + 1;
							this->label13->Show();
							this->label13->Text = "Lose 80% remaining HP and\nYou can't move for 1 round";
							galaxy.effect_10--;
						}
						

						galaxy.cd = galaxy.cd + galaxy.cd_plus;
					}
				}
			}
			

			if (enemy_clock == 45) {
				//this->label13->Hide();
				kanon.cd--;
			}
			if (kanon.cd == 0 && kanon.hp >= 1 && enemy_clock == 46) {
				int point = kanon.atk_point.point + kanon.atk_point.recover;
				if (point >= kanon.atk_point.limit) {
					kanon.atk_point.point = kanon.atk_point.limit;
				}
				else {
					kanon.atk_point.point = point;
				}
				kanon_changed_attack = kanon.total_atk();
				ControlPanalShow();
				PotionPanalShow();
				this->timer2->Stop();
			}
			if (kanon.cd != 0 && enemy_clock >= 47){
				enemy_clock = 0;
			}

		}

		bool StageIsClear() {
			if (stage != 3) {
				for (int i = 0; i < enemy_list.size(); i++) {
					if (enemy_list[i].is_alive == false) {
						pictureBox2->Hide();
						return true;
					}
					else {
						return false;
						break;
					}
				}
			}
			else if (stage == 3){
				if (galaxy.is_alive == false) {
					pictureBox2->Hide();
					return true;
				}
			}
			else {
				return false;
			}
		}

#pragma endregion
	private: System::Void battle_Load(System::Object^ sender, System::EventArgs^ e) {
		if (stage == 3) {
			String^ musicFilePath = "gransaga.wav";
			System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(musicFilePath);
			player->Play();
		}
		
		
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (system_counter == 0) {
			this->label14->Hide();
			BattleSceneInitialize();
			if (stage == 1) {
				Stage1();
			}
			if (stage == 3) {
				BossStage();
			}
		}
		label2->Text = Convert::ToString(system_counter);
		this->label2->Hide();
		
		Displayer();
		DialogueDisplayer();
		if (system_counter >= 10 && system_counter <= 50 && stage == 3) {
			BossMessageAnime(system_counter);
		}
		if (stage == 3 && system_counter == 55) {
			LoadImage("boss.png", pictureBox2);
			ControlPanalShow();
			PotionPanalShow();
		}
		else if (stage != 3){
			ControlPanalShow();
			PotionPanalShow();
		}
		

		if (StageIsClear() == true) {
			if (stage == 3) {
				this->label18->Hide();
			}
			this->button5->Show();
			ControlPanalHide();
			PotionPanalHide();
		}
		else {
			
		}

		if (kanon.hp == 0) {
			this->button5->Text = "You Lose!\nClick here to\nclose this window.";
			this->button5->Show();
			ControlPanalHide();
			PotionPanalHide();
		}
		
		if (stage == 3 && system_counter == 0) {
			String^ musicFilePath = "gransaga.wav";
			System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(musicFilePath);
			player->Play();
		}
		else if (stage == 3 && system_counter == 1460 && galaxy.effect_20 == 1) {
			String^ musicFilePath = "gransaga.wav";
			System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(musicFilePath);
			player->Play();
		}
		//label14->Text = Convert::ToString(system_counter);
		system_counter++;
		
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (kanon.atk_point.point >= 1) {
		kanon.atk_point.point--;
		PlayerAttack();
	}
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (kanon.attitude == 1) {
		kanon.attitude = 0;
	}
	else {
		kanon.attitude = 1;
	}
	
	kanon.cd++;
	ControlPanalHide();
	PotionPanalHide();
	enemy_clock = 0;
	timer2->Start();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	kanon.cd++;
	ControlPanalHide();
	PotionPanalHide();
	enemy_clock = 0;
	timer2->Start();
}
private: System::Void timer2_Tick_1(System::Object^ sender, System::EventArgs^ e) {
	if (stage == 1) {
		EnemyTurn(enemy_list, kanon, enemy_clock);
	}
	if (stage == 3){
		BossTurn();
	}
	this->label6->Text = Convert::ToString(enemy_clock);
	this->label6->Hide();
	enemy_clock++;
	
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (kanon.atk_point.point >= 1 && kanon.hp < kanon.total_maxhp()) {
		kanon.atk_point.point--;
		int heal = kanon.total_maxhp() * 0.01;
		if (kanon.hp + heal >= kanon.total_maxhp()) {
			kanon.hp = kanon.total_maxhp();
		}
		else {
			kanon.hp = kanon.hp + heal;
		}
	}
	
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (small_hp_potion.amount >= 1 && kanon.atk_point.point >= 2) {
		int heal = kanon.total_maxhp() * 0.15;
		if (kanon.hp + heal >= kanon.total_maxhp()) {
			kanon.hp = kanon.total_maxhp();
		}
		else {
			kanon.hp = kanon.hp + heal;
		}
		small_hp_potion.amount--;
		kanon.atk_point.point = kanon.atk_point.point - 2;
		PotionPanalHide();
	}
}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (big_hp_potion.amount >= 1 && kanon.atk_point.point >= 3) {
		int heal = kanon.total_maxhp() * 0.3;
		if (kanon.hp + heal >= kanon.total_maxhp()) {
			kanon.hp = kanon.total_maxhp();
		}
		else {
			kanon.hp = kanon.hp + heal;
		}
		big_hp_potion.amount--;
		kanon.atk_point.point = kanon.atk_point.point - 3;
		PotionPanalHide();
	}

}
private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (attack_potion.amount >= 1 && kanon.atk_point.point >= 1) {
		kanon_changed_attack = kanon_changed_attack * 1.6 + 1;
		attack_potion.amount--;
		kanon.atk_point.point--;
		PotionPanalHide();
	}
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
