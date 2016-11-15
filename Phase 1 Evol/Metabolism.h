#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "Orgo1.h"

using namespace std;
int h2o = 1000;
int co2 = 1000;

void DailyMet()
{
	for (int i = 0; i < OrgoAlive.size(); ++i)
	{
		OrgoAlive[i].Curh2o = fmin(h2o, OrgoAlive[i].CurSize);
		OrgoAlive[i].Curco2 = fmin(co2, OrgoAlive[i].CurSize);
		OrgoAlive[i].CurAge = OrgoAlive[i].CurAge + 1;  

								  //Basic metabolism, inputs going to stored energy
		OrgoAlive[i].StorGlu = OrgoAlive[i].StorGlu + fmin(OrgoAlive[i].Curco2, OrgoAlive[i].Curh2o) * OrgoAlive[i].MetSkPG * OrgoAlive[i].MetEfPG;
		OrgoAlive[i].StorCell = OrgoAlive[i].StorCell + fmin(OrgoAlive[i].Curco2, OrgoAlive[i].Curh2o) * OrgoAlive[i].MetSkPC * OrgoAlive[i].MetEfPC;


		//cost of days living
		double No1;
		No1 = OrgoAlive[i].CurAge / 80;  //increase the denominator here to get a longer period to a daily penalty
		No1 = log(No1) / 10;  //increase the denominator here to get a longer curve, the 0 for a minimum penalty
		No1 = fmax(0, No1); 
		double No2;  //cost of size
		No2 = log(OrgoAlive[i].CurSize);  
		No2 = (No2 / 4) * (OrgoAlive[i].CurSize *.7);  //adjustment for current size


		OrgoAlive[i].StorGlu = OrgoAlive[i].StorGlu - No1 - No2;


		//Limit Energy Stores by CurSize
		
		OrgoAlive[i].StorGlu = fmin(OrgoAlive[i].StorGlu, fmin(OrgoAlive[i].CurSize * 10, 50));
		OrgoAlive[i].StorCell = fmin(OrgoAlive[i].StorCell, OrgoAlive[i].CurSize * 10);

	}



}