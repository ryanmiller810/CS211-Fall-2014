/* Main program - Created by
   Ryan Miller on 12/03/2012 */

#ifndef Main_CPP
#define Main_CPP

#include<iostream>
#include<string>

using namespace std;

#include "Family.h"

//-----------------------------------

int main()
{

  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
  return 0;

}

//-----------------------------------

#endif // Main_CPP
