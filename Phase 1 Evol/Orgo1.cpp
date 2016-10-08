#include "Orgo1.h"
#include "stdafx.h"
#include <iostream>

using namespace std;


int CreateOrgo1()
{

typedef std::vector<orgo1> group_type;
group_type OrgoAlive;

int a, b, c, d, e, f, g, h, i, j, k, l;
cout << "Orgo Number: " << OrgoID << endl;
cout << "Enter Name: " << endl;
getline(cin, OrName);
//Define metskew 
cout << "Scale 1 to 10, 1 is slow and grow, 10 is live fast die young: " << endl;
cin >> a;
a = a * .1;
//define vitalthresh
cout << "Scale 1 to 10, 1 live on the edge, 10 very cautious: " << endl;
cin >> b;
//Define Action Preference
cout << "Scale 1 to 10, 10 being the most, Orgo likes to: " << endl;
cout << "Have Kids:  ";
cin >> c;
cout << endl << "Grow Larger:  ";
cin >> d;
cout << endl << "Look Fancy:  ";
cin >> e;
cout << endl << "Defend Itself:  ";
cin >> f;
cout << endl << "Do Nothing:  ";
cin >> g;
cout << endl << "Move Around:  ";
cin >> h;

orgo1 orgo1(OrName, a, b, c, d, e, f, g, h);
OrgoAlive.push_back(orgo1);



return 0;

}