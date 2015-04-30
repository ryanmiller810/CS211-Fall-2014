#ifndef Department_H
#define Department_H

#include<iostream>
#include<string>

using namespace std;

//----------------------------------------

class Department
{

  friend class University;

 protected:

  long depId;
  string name;
  string location;
  long chairId;
  static long nextDepartId;

 public:

  Department();
  Department(string n, string l, long chair);
  void Print() const;

};

//----------------------------------------

#endif // Department_H
