#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "Orgo1.h"

using namespace std;

void Actions()
{
	for (int i = 0; i < OrgoAlive.size(); ++i)
	{
		//Vitality Check and Actions
		double Vital = fmin(OrgoAlive[i].StorGlu + OrgoAlive[i].StorCell, OrgoAlive[i].StorGlu);
		if (Vital > OrgoAlive[i].VitalThresh)
		{

			//Choose your own adventure
			std::random_device rd;
			std::default_random_engine generator(rd());
			std::discrete_distribution<int> pick_action{ OrgoAlive[i].ActPrRep,OrgoAlive[i].ActPrDef,OrgoAlive[i].ActPrDis,OrgoAlive[i].ActPrDor,OrgoAlive[i].ActPrGr,OrgoAlive[i].ActPrMov };
			int Action = pick_action(generator);
			cout << Action;

			if (Action == 0) { OrgoAlive[i].KidNum = OrgoAlive[i].KidNum + 1; OrgoAlive[i].StorGlu = OrgoAlive[i].StorGlu - OrgoAlive[i].StartSize; }
			if (Action == 1) { OrgoAlive[i].Defense = OrgoAlive[i].Defense + 1; }
			if (Action == 2) { OrgoAlive[i].Display = OrgoAlive[i].Display + 1; }
			if (Action == 4) { OrgoAlive[i].CurSize = OrgoAlive[i].CurSize + 1; OrgoAlive[i].StorGlu = OrgoAlive[i].StorGlu - 1; OrgoAlive[i].StorCell = OrgoAlive[i].StorCell - 2; }


		
		}
	}
}