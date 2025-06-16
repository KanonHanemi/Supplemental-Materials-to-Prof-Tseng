#pragma once
#include "pch.h"
#include "data_format.h"
#include <math.h>
#include <random>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void boss::AttackChange(float rate) {
	atk = atk * rate + 1;
}

void boss::DefenseChange(float rate) {
	def = def * rate + 1;
}

void boss::DirectAttack(float rate, Character& character) {
	character.hp = character.hp - character.max_hp*rate;
}

void boss::AdditionalTurn(int turn, Character& character) {
	character.cd = character.cd + turn;
}

void LoadImage(const char* image_name, PictureBox^ picture_box) {
	Bitmap^ image;
	String^ name = gcnew String(image_name);
	image = safe_cast<Bitmap^>(Image::FromFile(name));
	picture_box->Image = image;
}

void SaveCharacterData(Character& character) {
	FILE* out;
	out = fopen("character.dat", "w");
	fprintf(out, "%d\n", character.atk);
	fprintf(out, "%d\n", character.def);
	fprintf(out, "%d\n", character.max_hp);
	fclose(out);
}

void LoadCharacterData(Character& character) {
	FILE* input;
	input = fopen("character.dat", "r");
	fscanf(input, "%d", character.atk);
	fscanf(input, "%d", character.def);
	fscanf(input, "%d", character.max_hp);
	fclose(input);
}

float GenerateRandomFloat(double a, double b) {
	random_device rd;
	default_random_engine generator(rd());
	uniform_real_distribution<float> distribution(a, b);
	return distribution(generator);
}

float CriticalDamage(float crit_rate, float crit_damage) {
	float s = GenerateRandomFloat(0.0, 100.0);
	if (s < crit_rate) {
		return 1.0 + crit_damage / 100.0;
	}
	else {
		return 1.0;
	}
}

float AttitudeDamage(int attitude) {
	if (attitude == 1) {
		return 1.15;
	}
	else {
		return 0.85;
	}
}

int DamageCounter(int atk, int def, float crit_rate, float crit_damage, int attitude) {
	int dmg;
	dmg = atk * CriticalDamage(crit_rate, crit_damage) * AttitudeDamage(attitude) - def;
	dmg = dmg * GenerateRandomFloat(0.95, 1.05);
	if (dmg <= 0) {
		dmg = 1;
	}
	return dmg;
}

int DamageCounter(int atk, int def) {
	int dmg;
	dmg = atk - def;
	if (dmg <= 0) {
		dmg = 1;
	}
	return dmg;
}

int DamageCounter(int atk, int def, float crit_damage) {
	int dmg;
	dmg = atk - def;
	dmg = dmg * crit_damage;
	if (dmg <= 0) {
		dmg = 1;
	}
	return dmg;
}