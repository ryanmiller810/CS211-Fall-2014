#ifndef Course_H
#define Course_H

#include<iostream>
#include<string>

using namespace std;

//----------------------------------------

class Course
{

  friend class University;

 protected:

  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;

 public:

  Course();
  Course(string n, long depId, long taught, int max);
  void Print() const;

};

//----------------------------------------

#endif // Course_H
