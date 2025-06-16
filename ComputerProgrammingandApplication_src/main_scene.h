#pragma once
#include <string>
#include <vector>
#include "shop.h"
#include "equipment.h"
#include "battle_prepare.h"
#include "data_format.h"
#include "Profile.h"
#include <iostream>



namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// main_scene 的摘要
	/// </summary>
	public ref class main_scene : public System::Windows::Forms::Form
	{
	public:
		main_scene(void)
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
		~main_scene()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button6;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(37, 98);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(350, 350);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(422, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 90);
			this->button1->TabIndex = 1;
			this->button1->Text = L"View status";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main_scene::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(588, 98);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 90);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Equipment";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &main_scene::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(422, 209);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 90);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Shop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &main_scene::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(588, 307);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 90);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Stages";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &main_scene::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(12, 9);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(109, 45);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Exit Game";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &main_scene::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(584, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 27);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &main_scene::timer1_Tick);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(127, 9);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(109, 45);
			this->button6->TabIndex = 7;
			this->button6->Text = L"BackDoor";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &main_scene::button6_Click);
			// 
			// main_scene
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->ControlBox = false;
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"main_scene";
			this->Text = L"main_scene";
			this->Load += gcnew System::EventHandler(this, &main_scene::main_scene_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void TextDisplayer() {
			this->label1->Text = ("Coin: " + Convert::ToString(item.coin));
			if (kanon.combat_point() >= 6000) {
				combat_point_achieve = true;
			}
		}

#pragma endregion
	private: System::Void main_scene_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadImage("character.png", pictureBox1);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::Profile^ profile = gcnew FinalProject::Profile;
		profile->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::equipment^ equipment_page = gcnew FinalProject::equipment;
		//this->Close();
		equipment_page->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::shop^ shop_page = gcnew FinalProject::shop;
		
		//this->Close();
		shop_page->Show();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalProject::battle_prepare^ battle_prepare = gcnew FinalProject::battle_prepare;
		//this->Close();
		battle_prepare->Show();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		TextDisplayer();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		kanon.atk = 1800;
		kanon.def = 3900;
		kanon.max_hp = 19926;
		small_hp_potion.amount = 80;
		big_hp_potion.amount = 80;
		attack_potion.amount = 80;
		item.coin = 9553;
		combat_point_achieve = true;
	}
};
}
