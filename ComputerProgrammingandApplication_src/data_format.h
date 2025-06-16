#pragma once
#include <sstream>
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

class Items {
public:
	int coin;
};

class Equipment {
public:
	int atk, def, max_hp;
	int lv = 1;
	int UpgradeCost() {
		int cost = 0;
		int tenth = lv / 10 + 1;
		for (int i = 1; i < tenth; i++) {
			cost = cost + i * 100;
		}
		cost = cost + (lv % 10) * (10 * tenth);
		return cost;
	}
	void Upgrade(Items& item) {
		item.coin = item.coin - UpgradeCost();
		lv++;
		atk = atk * 1.1;
		def = def * 1.1;
		max_hp = max_hp * 1.1;
	}

	Equipment() {

	}
};

class Accessory {
public:
	float crit_rate = 10.0;
	float crit_dmg = 50.0;
	int lv = 1;
	int UpgradeCost() {
		int cost = 0;
		int tenth = lv / 10 + 1;
		for (int i = 1; i < tenth; i++) {
			cost = cost + i * 500;
		}
		cost = cost + (lv % 10) * (50 * tenth);
		return cost;
	}
	void Upgrade(Items& item) {
		item.coin = item.coin - UpgradeCost();
		lv++;
		crit_rate = crit_rate * 1.05;
		crit_dmg = crit_dmg * 1.05;
	}
};

class AttackPoint {
public:
	int point = 5;
	int recover = 3;
	int limit = 10;
};

class Character {
public:
	int atk, def, max_hp;
	int hp;
	Equipment weapon;
	Equipment armor;
	Accessory accessory;
	int total_atk() {
		int total = atk + weapon.atk + armor.atk;
		return total;
	}
	int total_def() {
		int total = def + weapon.def + armor.def;
		return total;
	}
	int total_maxhp() {
		int total = max_hp + weapon.max_hp + armor.max_hp;
		return total;
	}
	int combat_point() {
		int total = total_atk() + total_def() + total_maxhp()/10;
		return total;
	}
	int cd = 0;
	int attitude = 1;
	bool is_alive = true;
	AttackPoint atk_point;

	Character() {

	}
};

class Potion {
public:
	string name;
	int amount;
	int cost;
};

class enemy {
public:
	int atk, def, max_hp;
	int hp;
	int cd, cd_plus;
	int drop_coin;
	bool is_alive = true;

	enemy() {

	}
};

class boss : public enemy {
public:
	string name;
	int effect_80 = 1;
	int effect_60 = 1;
	int effect_50 = 1;
	int effect_40 = 1;
	int effect_20 = 1;
	int effect_10 = 1;
	void AttackChange(float rate);
	void DefenseChange(float rate);
	void DirectAttack(float rate, Character& chatacter);
	void AdditionalTurn(int turn, Character& character);

	boss() {

	}
};

void SaveCharacterData(Character& character);
void LoadCharacterData(Character& character);
void LoadImage(const char* image_name, PictureBox^ picture_box);
float GenerateRandomFloat(double a, double b);
float CriticalDamage(float crit_rate, float crit_damage);
float AttitudeDamage(int attitude);
int DamageCounter(int atk, int def, float crit_rate, float crit_damage, int attitude);
int DamageCounter(int atk, int def);
int DamageCounter(int atk, int def, float crit_damage);

extern Character kanon;
extern Equipment weapon;
extern Equipment armor;
extern Accessory accessory;
extern Potion small_hp_potion;
extern Potion big_hp_potion;
extern Potion attack_potion;
extern enemy small_slime;
extern enemy medium_slime;
extern enemy big_slime;
extern boss galaxy;
extern vector<enemy> enemy_list;
extern Items item;
extern AttackPoint point;
extern int stage;
extern int system_counter;
extern int enemy_clock;
extern int kanon_changed_attack;
extern bool combat_point_achieve;