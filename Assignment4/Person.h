/* Class Person file. Created by
   Ryan Miller on 11/29/2012. */

#ifndef Person_H
#define Person_H

#include<iostream>
#include<string>

using namespace std;

class Wife;
class Husband;
class Child;

typedef Wife* WifePtr;
typedef Husband* HusbandPtr;
typedef Child* ChildPtr;

//----------------------------------------

class Person
{

  friend class Family;

 protected:

  long SSN;
  string fName;
  string lName;

};

//----------------------------------------

class Wife:public Person
{

  friend class Family;

 protected:

  ChildPtr myChildren;
  long HusbId;

 public:

  Wife(){SSN = HusbId = 0; fName = lName = " "; myChildren = NULL;}
  Wife(long id, string fN, string lN, long hId){SSN = id; fName = fN; lName = lN; HusbId = hId; myChildren = NULL;}

};

//----------------------------------------

class Husband:public Person
{

  friend class Family;

 protected:

  HusbandPtr nextFamily;
  WifePtr myWife;

 public:

  Husband(){SSN = 0; fName = lName = " "; nextFamily = NULL; myWife = NULL;}
  Husband(long id, string fN, string lN){SSN = id; fName = fN; lName = lN; nextFamily = NULL; myWife = NULL;}

};

//----------------------------------------

class Child:public Person
{

  friend class Family;

 protected:

  ChildPtr mySibling;
  long HusbId;

 public:

  Child(){SSN = HusbId = 0; fName = lName = " "; mySibling = NULL;}
  Child(long id, string fN, string lN, long hId){SSN = id; fName = fN; lName = lN; HusbId = hId; mySibling = NULL;}

};

//----------------------------------------

#endif // Person_H
