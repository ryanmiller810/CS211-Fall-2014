#ifndef Department_CPP
#define Department_CPP

#include<iostream>
#include<string>

using namespace std;

//----------------------------------------

#include "Department.h"

long Department::nextDepartId = 100;

//----------------------------------------

Department::Department()
{

  depId = chairId = 0;
  name = location = " ";
  nextDepartId++;

}

//----------------------------------------

Department::Department(string n, string l, long chair)
{

  depId = nextDepartId;
  name = n;
  location = l;
  chairId = chair;
  nextDepartId++;

}

//----------------------------------------

void Department::Print() const
{

  cout << depId << " " << name << " " << location << " " << chairId << " " << nextDepartId << endl;

}

//----------------------------------------

#endif // Department_CPP
