#ifndef Person_CPP
#define Person_CPP

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//----------------------------------------

#include "Person.h"

long Student::nextStId = 500;
long Faculty::nextFacultyId = 600;

//----------------------------------------

Person::Person()
{

  id = 0;
  name = email = address = dateOfBirth = gender = " ";

}

//----------------------------------------

Person::Person(long no, string n, string e, string a, string dob, string g)
{

  id = no;
  name = n;
  email = e;
  address = a;
  dateOfBirth = dob;
  gender = g;

}

//----------------------------------------

void Person::Print() const
{

  cout << id << " " << name << " " << email << " " << address << " " << dateOfBirth << " " << gender << endl;

}

//----------------------------------------

Student::Student()
{

  yearOfStudy = 0;
  name = email = address = dateOfBirth = gender = major = " ";
  advisorId = 0;
  id = nextStId;
  nextStId++;

}

//----------------------------------------

Student::Student(string sN, string sE, string sA, string sDOB, string sG, int sYOS, string sM, long sAID)
{

  id  = nextStId;
  name = sN;
  email = sE;
  address = sA;
  dateOfBirth = sDOB;
  gender = sG;

  yearOfStudy = sYOS;
  major = sM;
  advisorId = sAID;

  nextStId++;

}

//----------------------------------------

void Student::Print() const
{

  cout << id << " " << name << " " << email << " " << address << " " << dateOfBirth << " " << gender << " " << yearOfStudy << " " << major << " " << advisorId << endl;

}

//----------------------------------------

Faculty::Faculty()
{

  salary = 0.0;
  yearOfExp = 0;
  departId = 0;
  id = nextFacultyId;
  name = email = address = dateOfBirth = gender = " ";

  nextFacultyId++;

}

//----------------------------------------

Faculty::Faculty(string fN, string fE, string fA, string fDOB, string fG, float fS, int fYOE, long fDID)
{

  id = nextFacultyId;
  name = fN;
  email = fE;
  address = fA;
  dateOfBirth = fDOB;
  gender = fG;

  salary = fS;
  yearOfExp = fYOE;
  departId = fDID;

  nextFacultyId++;

}

//----------------------------------------

void Faculty::Print() const
{

  cout << id << " " << name << " " << email << " " << address << " " << dateOfBirth << " " << gender << " " << salary << " " << yearOfExp << " " << departId << endl;

}

//----------------------------------------

#endif // Person_CPP
