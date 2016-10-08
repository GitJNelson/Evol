#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include "Orgo1.h"
#include "Metabolism.h"
#include "Actions.h"

int Turns;
int CurDate;

int main()
{

	//Create Organisms
	int CROR;
		cout << "Creat How Many Orgos?" << endl;
	cin >> CROR;
		for (CROR > 0; CROR--;)
	{
		CreateOrgo1();

		OrgoID = OrgoID + 1;

	}

		//Daily game loop

		//Setting the base parameters
		int h2o = 1000;
		int co2 = 1000;
		//Input to run for
		cout << "Set Start Date:  ";
		cin >> CurDate;
		cout << "Number of Ticks to Run:  ";
		cin >> Turns;
		//Create output file
		ofstream outputFile;
		outputFile.open("Evoldata.txt", ios::trunc);

		//Turn Loop
		for (Turns > 0; Turns = Turns - 1;)
		{
			//Iterate through all Orgos via metabolism header file
			DailyMet();

			//Run action choide
			Actions();

			
			for (int i = 0; i < OrgoAlive.size(); ++i)
			{
				//Dump to file, CSV text
				ofstream outputFile;
				outputFile.open("Evoldata.txt", ios::app);
				outputFile << OrgoAlive[i].OrgoID << "," << CurDate << "," << OrgoAlive[i].StorGlu << "," << OrgoAlive[i].StorCell << "," << OrgoAlive[i].CurSize << "," << OrgoAlive[i].KidNum << "," << endl;
			}
			//move date forward
			CurDate = CurDate + 1;
			cout << "Date" << CurDate << endl;

		}



//Output of information
	for (int i = 0; i < OrgoAlive.size(); ++i) {
	cout << "OrgoID  " << OrgoAlive[i].getID() << " MetSkew " << OrgoAlive[i].getStorGlu() << endl;

	}

    return 0;
}

