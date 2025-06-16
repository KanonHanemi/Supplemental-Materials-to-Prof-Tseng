#pragma once
#include "battle.h"
#include "data_format.h"




namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// battle_prepare 的摘要
	/// </summary>
	public ref class battle_prepare : public System::Windows::Forms::Form
	{
	public:
		battle_prepare(void)
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
		~battle_prepare()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ Boss;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(battle_prepare::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Boss = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 300);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Stage 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &battle_prepare::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(130, 69);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 300);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Stage 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &battle_prepare::button2_Click);
			// 
			// Boss
			// 
			this->Boss->BackColor = System::Drawing::Color::DarkRed;
			this->Boss->Font = (gcnew System::Drawing::Font(L"Yu Mincho Demibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boss->ForeColor = System::Drawing::Color::White;
			this->Boss->Location = System::Drawing::Point(246, 69);
			this->Boss->Name = L"Boss";
			this->Boss->Size = System::Drawing::Size(110, 300);
			this->Boss->TabIndex = 2;
			this->Boss->Text = L"BOSS";
			this->Boss->UseVisualStyleBackColor = false;
			this->Boss->Click += gcnew System::EventHandler(this, &battle_prepare::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(360, 360);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(378, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 275);
			this->label1->TabIndex = 4;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->Click += gcnew System::EventHandler(this, &battle_prepare::label1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(552, 322);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 50);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Enter";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &battle_prepare::button3_Click_1);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(383, 322);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 50);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Back";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &battle_prepare::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(13, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 40);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Back";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &battle_prepare::button5_Click);
			// 
			// battle_prepare
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 381);
			this->ControlBox = false;
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Boss);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"battle_prepare";
			this->Text = L"battle_prepare";
			this->Load += gcnew System::EventHandler(this, &battle_prepare::battle_prepare_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void battle_prepare_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Hide();
		
		this->button3->Hide();
		this->button4->Hide();
		this->pictureBox1->Hide();
		if (combat_point_achieve == false) {
			this->Boss->Hide();
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::battle^ battle_1 = gcnew FinalProject::battle;
		stage = 1;
		system_counter = 0;
		this->Close();
		battle_1->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::battle^ battle_2 = gcnew FinalProject::battle;
		stage = 2;
		system_counter = 0;
		this->Close();
		battle_2->Show();
		
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadImage("boss_shadow2.png", pictureBox1);
		this->pictureBox1->Show();
		this->label1->Show();
		this->button3->Show();
		this->button4->Show();
		this->button1->Hide();
		this->button2->Hide();
		this->button5->Hide();
		this->Boss->Hide();
		
	}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	FinalProject::battle^ battle_boss = gcnew FinalProject::battle;
	stage = 3;
	system_counter = 0;
	this->Close();
	battle_boss->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button1->Show();
	this->button2->Show();
	this->button5->Show();
	this->Boss->Show();
	this->label1->Hide();
	this->button3->Hide();
	this->button4->Hide();
	this->pictureBox1->Hide();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
