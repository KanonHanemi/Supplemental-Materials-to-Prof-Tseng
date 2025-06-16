#pragma once
//#include <math.h>
#include <string>
#include <vector>
#include "shop.h"
#include "equipment.h"
#include "battle_prepare.h"
#include "data_format.h"
#include <iostream>
#include "main_scene.h"

using namespace std;

Character kanon;
Equipment weapon;
Equipment armor;
Accessory accessory;
Items item;
AttackPoint point;
Potion small_hp_potion;
Potion big_hp_potion;
Potion attack_potion;
enemy small_slime;
enemy medium_slime;
enemy big_slime;
vector<enemy> enemy_list;
boss galaxy;
int stage;
int system_counter;
int enemy_clock;
int kanon_changed_attack;
bool combat_point_achieve;


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
















	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ProgressBar^ progressBar1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->AllowDrop = true;
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(-4, -14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(948, 651);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Font = (gcnew System::Drawing::Font(L"Edwardian Script ITC", 96, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(167, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(599, 302);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Fairy Tale of \r\nDivine Fox";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(400, 456);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(211, 35);
			this->label2->TabIndex = 2;
			this->label2->Text = L"                            ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(57, 501);
			this->progressBar1->MarqueeAnimationSpeed = 200;
			this->progressBar1->Maximum = 96;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(810, 10);
			this->progressBar1->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(939, 626);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Yu Mincho", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		

		void CharacterInitialize() {
			kanon.atk = 10;
			kanon.def = 10;
			kanon.max_hp = 100;
		}

		void EquipmentInitialize() {
			weapon.lv = 1;
			weapon.atk = 10;
			weapon.def = 0;
			weapon.max_hp = 50;
			armor.lv = 1;
			armor.atk = 0;
			armor.def = 10;
			armor.max_hp = 100;
			

			kanon.weapon = weapon;
			kanon.armor = armor;
			kanon.accessory = accessory;

			kanon.hp = kanon.total_maxhp();
		}

		void PotionInitialize() {
			item.coin = 0;

			string name = "small_hp_potion";
			small_hp_potion.name = name;
			name = "big_hp_potion";
			big_hp_potion.name = name;
			name = "attack_potion";
			attack_potion.name = name;
			small_hp_potion.amount = 0;
			big_hp_potion.amount = 0;
			attack_potion.amount = 0;
			small_hp_potion.cost = 100;
			big_hp_potion.cost = 300;
			attack_potion.cost = 500;
		}

		void TextDisplayer(int i) {
			if (i%4 == 2){
				if (i >= 10 && i <= 41) {
					this->label2->Text = "Initializing";
				}
				else if (i >= 42 && i <= 73) {
					this->label2->Location = System::Drawing::Point(360, 456);
					this->label2->Text = "Loading Resources";
				}	
				else if (i >= 74 && i <= 105) {
					this->label2->Location = System::Drawing::Point(355, 456);
					this->label2->Text = "Loading User INFO";
				}
					
			}
			if (i % 4 == 3) {
				if (i >= 8 && i <= 41) 
					this->label2->Text = "Initializing.";
				else if (i >= 42 && i <= 73) 
					this->label2->Text = "Loading Resources.";
				else if (i >= 74 && i <= 105)
					this->label2->Text = "Loading User INFO.";
				
			}
			if (i % 4 == 0) {
				if (i >= 8 && i <= 41) 
					this->label2->Text = "Initializing..";
				else if (i >= 42 && i <= 73) 
					this->label2->Text = "Loading Resources..";
				else if (i >= 74 && i <= 105)
					this->label2->Text = "Loading User INFO..";
				
			}
			if (i % 4 == 1) {
				if (i >= 8 && i <= 41) 
					this->label2->Text = "Initializing...";
				else if (i >= 42 && i <= 73) 
					this->label2->Text = "Loading Resources...";
				else if (i >= 74 && i <= 105)
					this->label2->Text = "Loading User INFO...";
				
			}

		}
		
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		combat_point_achieve = false;
		this->label2->Hide();
		CharacterInitialize();
		EquipmentInitialize();
		PotionInitialize();	
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (system_counter >= 4 && system_counter <= 105) {
			this->label2->Show();
			TextDisplayer(system_counter);
		}
		if (system_counter >= 4 && system_counter <= 100) {
			this->progressBar1->Value = system_counter - 4;
		}
		if (system_counter >= 105) {
			this->button1->Enabled = true;
			this->label1->Enabled = true;
			if (system_counter % 10 >= 5) {
				this->label2->Location = System::Drawing::Point(300, 456);
				this->label2->Text = "Click anywhere to Continue.";
			}
			else {
				this->label2->Text = "";
			}
		}
		system_counter++;
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Stop();
		system_counter = 0;
		FinalProject::main_scene^ mainscene = gcnew FinalProject::main_scene;
		mainscene->Show();
		this->Hide();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Stop();
		system_counter = 0;
		FinalProject::main_scene^ mainscene = gcnew FinalProject::main_scene;
		mainscene->Show();
		this->Hide();

	}
};
}
