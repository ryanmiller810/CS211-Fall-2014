/* This file provides the functions needed to construct
a multiple families within a linked list. There are also
the capabilities to remove single family members and
or entire families. Also, the user may print single
or all families to the screen.

Created by Ryan Miller on 11/29/2012.
Please feel free to contact me with any questions
@ ryanmiller810@gmail.com */

#ifndef Family_CPP
#define Family_CPP

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "Family.h"
#include "Person.h"

//----------------------------------

bool Family::success = true; // Declaring boolean variables
bool Family::failure = false;

//----------------------------------

bool Family::AddHusband(long id, string fN, string lN) // Function to add a husband. Created 11/29/2012.
{

  HusbandPtr H = SearchForHusband(id); // Checks to see if husband already exists
  if(H != NULL)
    {
      cout << "This family already exists." << endl;
      return failure; // returns a failure if husband exists
    }

  H = new Husband(id, fN, lN); // Creates new husband
  H->nextFamily = top; // Links existing families to new husband node
  top = H;

}

//----------------------------------

HusbandPtr Family::SearchForHusband(long id) // Function to search for existing husband. Created 11/29/2012.
{

  HusbandPtr H = top;
  while(H != NULL)
    {
      if(H->SSN == id)
	{
	return H;
	}
      H = H->nextFamily;
    }
	
  return NULL;

}

//----------------------------------

bool Family::RemoveHusband(long id) // Function to remove an existing husband. Created 12/03/2012.
{

  HusbandPtr H = SearchForHusband(id); // Searches to make sure that husband exists
  if(H == NULL)
    {
      cout << "Husband " << id << " does not exist." << endl;
      return failure;
    }

  WifePtr W = H->myWife;
  ChildPtr C = W->myChildren;
  ChildPtr D = W->myChildren;

  while(W->myChildren != NULL) // Any existing child nodes must be deleted prior
    {
      D = D->mySibling;
      delete C;
      W->myChildren = D;
      C = D;
    }

  delete W; // Deletion of wife node
  delete H; // Deletion of husband node
  H = NULL;

  return success;
}

//----------------------------------

bool Family::AddWife(long id, string fN, string lN, long hId) // Function to add a wife. Created 11/29/2012.
{

  HusbandPtr H = SearchForHusband(hId); // Searches to make sure that husband exists
  if(H == NULL)
    {
      cout << hId << " is not an existing husband." << endl;
      return failure;
    }

  if(H->myWife != NULL) // Checks to make sure that husband is not already married.
    {
      cout << "Husband " << hId << " already has a wife." << endl;
      return failure;
    }

  WifePtr W = new Wife(id, fN, lN, hId); // Creates new wife and attaches to selected husband node.
  H->myWife = W;

}

//----------------------------------

bool Family::RemoveWife(long HusbId) // Function to remove a wife. Created 12/03/2012.
{

  HusbandPtr H  = SearchForHusband(HusbId); // Searches to make sure that husband exists.
  if(H == NULL)
    {
      cout << "Husband " << HusbId << " does not exist." << endl;
      return failure;
    }

  WifePtr W = H->myWife;
  ChildPtr C = W->myChildren;
  ChildPtr D = W->myChildren;

  while(W->myChildren != NULL) // Deletes and children nodes attached to wife first
    {
      D = D->mySibling;
      delete C;
      W->myChildren = D;
      C = D;
    }

  delete W; // Deletes wife node
  H->myWife = NULL;

  return success;

}

//----------------------------------

bool Family::AddChild(long id, string fN, string lN, long hId) // Function to add a child. Created 11/29/2012.
{

  HusbandPtr H = SearchForHusband(hId); // Searches for an existing Father.
  if(H == NULL)
    {
      cout << hId << " is not an existing father." << endl;
      return failure;
    }

  if(H->myWife == NULL) // Checks to see if existing father has a wife.
    {
      cout << "Father " << hId << " does not have a wife to create children." << endl;
      return failure;
    }

  WifePtr W = H->myWife;
  if(W->myChildren != NULL) // If wife already has a child node the pointer cycles through until NULL is reached
    {
      ChildPtr C = W->myChildren;
      while(C->mySibling != NULL)
	{
	  C = C->mySibling;
	}
      ChildPtr D = new Child(id, fN, lN, hId); // New child is then created
      C->mySibling = D;
      return success;
    }

  ChildPtr E = new Child(id, fN, lN, hId); // If myChildren was == NULL then new child is created
  W->myChildren = E;
  return success;

}

//----------------------------------

bool Family::RemoveChild(long ChildId, long DadId) // Function to remove a child. Created 12/03/2012. 
{

  HusbandPtr H = SearchForHusband(DadId); // Searches for an existing husband.
    if(H == NULL)
      {
	cout << "Father " << DadId << " does not exist." << endl;
	return failure;
      }

  WifePtr W = H->myWife; // Searches for an existing wife.
  if(W == NULL)
    {
      cout << "Husband " << DadId << " does not have a wife therefore does not have any children." << endl;
      return failure;
    }

  ChildPtr C = W->myChildren;
  ChildPtr D = W->myChildren;
 
  if(C->SSN == ChildId) // Searches for correct child and removes child.
    {
      D = D->mySibling;
      delete C;
      W->myChildren = D;

      return success;
    }

  while(C->SSN != ChildId)
  {

  D = C;
  C = C->mySibling;

  if(C->mySibling == NULL)
    {
    cout << "The child " << ChildId << " does not exist." << endl;
    return failure;
    }

  }


  ChildPtr E = C->mySibling;
  delete C;
  D->mySibling = E;

  return success;

}

//----------------------------------

bool Family::PrintAFamily(long HusbId) // Function to print a selected family. Created 11/29/2012.
{

  HusbandPtr H = SearchForHusband(HusbId);
  if(H == NULL)
    {
      cout << "Family " << HusbId << " does not exist." << endl; // Check to see if family exist
      return failure;
    }

  while(H != NULL) // Searches through family linked list and prints each member to screen.
      {
	if(H->SSN == HusbId)
	  {
	    cout << "Husband information is as follows: " << H->SSN << " " << H->fName << " " << H->lName << endl;
	    WifePtr W = H->myWife;
	    if(W != NULL)
	      {
		cout << "Wife information is as follows: " << W->SSN << " " << W->fName << " " << W->lName << endl;
		ChildPtr C = W->myChildren;
		if(C != NULL)
		  {
		    cout << "Child information is as follows: " << C->SSN << " " << C->fName << " " << C->lName << endl;
		    ChildPtr D = C->mySibling;
		    while(D != NULL)
		      {
			cout << "Child information is as follows: " << D->SSN << " " << D->fName << " " << D->lName << endl;
			D = D->mySibling;
		      }
		  }
	      }
	  }

	H = H->nextFamily;
      }

  return success;

}

//----------------------------------

bool Family::PrintAllFamilies() // Function to print all existing families. Created 11/29/2012.
{

  HusbandPtr H = top;
  while(H != NULL) // Goes through each family one by one and prints all members to screen.
    {
      PrintAFamily(H->SSN);
      H = H->nextFamily;
    }

}

//----------------------------------

bool Family::destroy(HusbandPtr& top) // Destroy function. Created 11/29/2012.
{

  HusbandPtr H = top;
  HusbandPtr B = top;

  while(B != NULL)
    {
      B = B->nextFamily;
      delete H;
      H = B;
    }

}

//----------------------------------

void Family::ReadTransactionFile() // Function to process a transaction file of commands. Created 12/03/2012.
{

  long id, hId, HusbId, ChildId, DadId;
  string fN, lN;

  ifstream fin;
  fin.open("transfile.txt");

  string cmd;

  while(!fin.eof())
    {
      fin >> cmd;
  if(cmd == "AddHusband")
    {
      fin >> id >> fN >> lN;
      AddHusband(id, fN, lN);
    }
  if(cmd == "AddWife")
    {
      fin >> id >> fN >> lN >> hId;
      AddWife(id, fN, lN, hId);
    }
  if(cmd == "AddAchild")
    {
      fin >> id >> fN >> lN >> hId;
      AddChild(id, fN, lN, hId);
    }
  if(cmd == "RemoveAchild")
    {
      fin >> ChildId >> DadId;
      RemoveChild(ChildId, DadId);
    }
  if(cmd == "RemoveWife")
    {
      fin >> HusbId;
      RemoveWife(HusbId);
    }
  if(cmd == "RemoveHusband")
    {
      fin >> id;
      RemoveHusband(id);
    }
  if(cmd == "PrintAFamily")
    {
      fin >> HusbId;
      PrintAFamily(HusbId);
    }
  if(cmd == "PrintAllFamilies")
    {
      PrintAllFamilies();
    }
    }

  fin.close();     

}

//----------------------------------

#endif // Family_CPP
