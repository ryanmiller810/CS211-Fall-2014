#ifndef Person_H
#define Person_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//----------------------------------------

#include "Course.h"

class Person
{

  friend class University;

 protected:

  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:

  Person();
  Person(long no, string n, string e, string a, string dob, string g);
  void Print() const;

};

//----------------------------------------

class Student:public Person
{

  friend class University;

 protected:

  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;

 public:

  Student();
  Student(string n, string e, string a, string dob, string g, int year, string m, long adv);
  void Print() const;

};

//----------------------------------------

class Faculty:public Person
{

  friend class University;

 protected:

  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;

 public:

  Faculty();
  Faculty(string n, string e, string a, string dob, string g, float s, int year, long dept);
  void Print() const;

};

//----------------------------------------

#endif // Person_H
