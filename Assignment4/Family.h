/* Class Family file. Created by
   Ryan Miller 11/29/2012. */

#ifndef Family_H
#define Family_H

#include<iostream>
#include<string>

using namespace std;

class Husband;
typedef Husband* HusbandPtr;

class Family
{

 protected:

  HusbandPtr top;
  static bool success;
  static bool failure;

 public:

  bool AddHusband(long id, string fN, string lN);
  HusbandPtr SearchForHusband(long id);
  bool RemoveHusband(long id);
  bool AddWife(long id, string fN, string lN, long hId);
  bool RemoveWife(long HusbId);
  bool AddChild(long id, string fN, string lN, long hId);
  bool RemoveChild(long ChildId, long DadId);
  bool PrintAFamily(long HusbId);
  bool PrintAllFamilies();
  Family(){top = NULL;}
  ~Family(){destroy(top);}
  bool destroy(HusbandPtr& top);
  void ReadTransactionFile();

};

#endif // Family_H
