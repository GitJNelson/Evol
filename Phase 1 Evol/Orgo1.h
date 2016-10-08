#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;
string OrName;
int OrgoID;

//Defining Structure for Plant Organism
struct orgo1 {
	
	int OrgoID;
	int Curh2o, Curco2;
		string OrName;
	double MetSkPG, MetSkPC, VitalThresh, ActPrRep, ActPrGr, ActPrDis, ActPrDef, ActPrDor, ActPrMov;

	//Instantiate class
	orgo1(int ID, double a, double b, double c, double d, double e, double f, double g, double h, double i) :
		OrgoID(ID), MetSkPG(a), VitalThresh(b), ActPrRep(c), ActPrGr(d), ActPrDis(e), ActPrDef(f), ActPrDor(g), ActPrMov(h), MetSkPC (i) {}  //user input variable
		
	double CurAge = 1;
	double StorGlu = 0;
	double StorCell = 0;  
	double MetEfPG = 0.6;
	double MetEfPC = 0.6; 
	float CurSize = 1;
	float KidNum = 0;
	float Defense = 0;
	float Display = 0;
	float StartSize = 1;
	


	int getID() const { return OrgoID; }
	double getStorGlu() const { return StorGlu; }
	double getStorCell() const { return StorCell; }
	double getCurSize() const { return CurSize; }
	double getKidNum() const { return KidNum; }
	string getName() const { return OrName; }
	double getMetSkew() const { return MetSkPG; }
	double getCurAge() const { return CurAge; }
	
};


typedef std::vector<orgo1> group_type;
group_type OrgoAlive;

void CreateOrgo1()
{
	
	double a, b, c, d, e, f, g, h, i;
	cout << "Orgo Number: " << OrgoID << endl;
	//cout << "Enter Name: ";
	//getline(cin, OrName);
	//Define metskew 
	cout << "Scale 1 to 10, 1 is slow and grow, 10 is live fast die young: ";
	cin >> a;
	a = a * .1;
	i = 1 - a;
	//define vitalthresh
	cout << "Scale 1 to 10, 1 live on the edge, 10 very cautious: ";
	cin >> b;
	//Define Action Preference
	cout << "Scale 1 to 10, 10 being the most, Orgo likes to: " << endl;
	cout << "Have Kids:  ";
	cin >> c;
	cout << "Grow Larger:  ";
	cin >> d;
	cout << "Look Fancy:  ";
	cin >> e;
	cout << "Defend Itself:  ";
	cin >> f;
	cout << "Do Nothing:  ";
	cin >> g;
	cout << "Move Around:  ";
	cin >> h;
	cout << endl << endl;

	orgo1 orgo1(OrgoID, a, b, c, d, e, f, g, h, i);
	OrgoAlive.push_back(orgo1);

	
}

