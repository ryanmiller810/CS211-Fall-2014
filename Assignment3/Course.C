#ifndef Course_CPP
#define Course_CPP

#include<iostream>
#include<string>

using namespace std;

//----------------------------------------

#include "Course.h"

long Course::nextCRN = 200;

//----------------------------------------

Course::Course()
{

  CRN = nextCRN; 
  departId = assignedSeats = isTaughtBy = 0;
  maxAvailableSeats = 0;
  name = " ";
  nextCRN++;

}

//----------------------------------------

Course::Course(string n, long dept, long taught, int max)
{

  CRN = nextCRN;
  maxAvailableSeats = max;
  name = n;
  departId = dept;
  assignedSeats = 0;
  isTaughtBy = taught;
  nextCRN++;

}

//----------------------------------------

void Course::Print() const
{

  cout << CRN << " " << maxAvailableSeats << " " << name << " " << departId << " " << assignedSeats << " " << isTaughtBy << " " << nextCRN << endl;

}

//----------------------------------------

#endif // Course_CPP
