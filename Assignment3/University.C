/* This program is to create a database of university information
including items such as Department, Courses, Students, and Faculty.
The user will be able to create a file of such items that the program
will read into separate storage methods. 

Created by Ryan Miller 11/06/2012
Please feel free to email me at ryanmiller810@gmail.com with any questions */

#ifndef University_CPP
#define University_CPP

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//---------------------------------------------

#include "University.h"

bool University::failure = false; // Creating boolean attributes
bool University::success = true;

//---------------------------------------------

University::University()
{

}

//---------------------------------------------

University::~University()
{

}

//---------------------------------------------

bool University::CreateNewDepartment(string depName, string depLoc, long chairId) // Function to create a new department 11/06/2012
{

  bool valid = CheckFacValidity(chairId); // Checks for faculty validity
    if(!valid)
      {
	cout << "The department chair id " << chairId << " is not valid" << endl;
	return failure;
      }

    Department newDep(depName, depLoc, chairId); //If pre-cond past then new department is created
  Departments.push_back(newDep);

  return success;

}

//---------------------------------------------

bool University::CheckFacValidity(long chairId) // Function to check for faculty validity 11/06/2012
{

  for(int i=0; i<Faculties.size(); i++)
    {
      if(Faculties[i].id == chairId)
	return success;
    }

  return failure;
}

//---------------------------------------------

bool University::RemoveADepartment(long depId) // Function to remove a current department 11/06/2012
{

  bool valid = CheckDepValidity(depId); //Checks for department validity
  if(!valid)
    {
      cout << "The department id number " << depId << " is not valid" << endl;
      return failure;
    }

  int count = CountFac(depId); //Checks to see if there are any existing faculty within department
  if(count > 0)
    {
      cout << "This department includes " << count << " employees and cannot be removed" << endl;
      return failure;
    }

  count = CountCourse(depId); //Checks to see if there are any existing courses within department
    if(count > 0)
      {
	cout << "The department includes " << count << " courses and cannot be removed" << endl;
	return failure;
      }

    //count = CountMajors(depId);
    //if(count > 0)
    //{
    //cout << "The department includes " << count << " majors and cannot be removed" << endl;
    //return failure;
    //}

}

//---------------------------------------------

bool University::CheckDepValidity(long depId) // Function to check if department exists 11/06/2012
{

  for(int i=0; i<Departments.size(); i++)
    {
      if(!Departments[i].depId)
	return success;
    }

  return failure;
}

//---------------------------------------------

int University::CountFac(long depId) //Counts existing faculty within a department 11/06/2012
{

  int count;
  for(int i=0; i<Faculties.size(); i++)
    {
      if(Faculties[i].departId == depId)
	{
	  count++;
	}

      return count;
    }
}
  
//---------------------------------------------

int University::CountCourse(long depId) //Counts existing courses within a department 11/06/2012
{

  int count;
  for(int i=0; i<Courses.size(); i++)
    {
      if(Courses[i].departId == depId)
	{
	  count++;
	}

      return count;
    }
}

//---------------------------------------------

bool University::CreateNewStudent(long sNo, string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId) // Function to create a new student 11/06/2012
{

  bool valid = CheckMajorValidity(sMajor); // Checks students major for validity
  if(!valid)
    {
      cout << "The following major ::" << sMajor << ":: is not valid" << endl;
      return failure;
    }

  valid = CheckAdvValidity(sAdvisorId); //Checks students advisor validity
  if(!valid)
    {
      cout << "The following advisor id " << sAdvisorId << " is not valid" << endl;
      return failure;
    }

  Student newStud(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId); // Creates new student
  //nextStId++;
    Students.push_back(newStud);

  return success;

}

//---------------------------------------------

bool University::CheckMajorValidity(string sMajor) // Function to check students major validity 11/06/2012
{

  for(int i=0; i<Departments.size(); i++)
    {
    if(Departments[i].name == sMajor)
      return success;
    }

  return failure;

}

//---------------------------------------------

bool University::CheckAdvValidity(long sAdvisorId) // Function to check students advisor validity 11/06/2012
{

  for(int i=0; i<Faculties.size(); i++)
    {
      if(Faculties[i].id == sAdvisorId)
	return success;
    }

  return failure;

}

//---------------------------------------------

bool University::RemoveAStudent(long sStId) // Function to remove a current student 11/06/2012
{

  bool valid = CheckStIdValidity(sStId);
    if(!valid)
      {
	cout << "The student ID " << sStId << " is not valid" << endl;
	return failure;
      }



}

//---------------------------------------------

bool University::CheckStIdValidity(long sStId) // Function to check for student id validity 11/06/2012
{

  for(int i=0; i<Students.size(); i++)
    {
      if(Students[i].id == sStId)
	return success;
    }

  return failure;

}

//---------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat) // Function to create a new course 11/06/2012
{

  bool valid = CheckTaughtByValidity(cTaughtBy); // Checks for valid faculty teaching course
  if(!valid)
    {
      cout << cTaughtBy << " is not valid for this course" << endl;
      return failure;
    }

  valid = CheckDepIdValidity(cDepId); // Checks for valid department id
  if(!valid)
    {
      cout << "The department id " << cDepId << " is not valid" << endl;
      return failure;
    }

  Course newCourse(cName, cDepId, cTaughtBy, cMaxSeat); //Creates a new course
  Courses.push_back(newCourse);

  return success;

}

//---------------------------------------------

bool University::CheckTaughtByValidity(long cTaughtBy) // Function to check what faculty is teaching a course 11/06/2012
{

  for(int i=0; i<Courses.size(); i++)
    {
      if(Courses[i].isTaughtBy == cTaughtBy);
      return success;
    }

  return failure;

}

//---------------------------------------------

bool University::CheckDepIdValidity(long cDepId) // Function to check for a valid department id 11/06/2012
{

  for(int i=0; i<Courses.size(); i++)
  {
    if(Courses[i].departId == cDepId)
      return success;
  }

  return failure;

}

//---------------------------------------------

bool University::RemoveACourse(long cCRN) // Function to remove a course 11/06/2012
{

  bool valid = CheckCRNValidity(cCRN); // Function to check course id validity
  if(!valid)
    {
      cout << "The " << cCRN << " is not valid" << endl;
      return failure;
    }

 

}

//---------------------------------------------

bool University::CheckCRNValidity(long cCRN) // Function to check course id validity 11/06/20212
{

  for(int i=0; i<Courses.size(); i++)
    {
      if(Courses[i].CRN == cCRN)
	return success;
    }

  return failure;

}

//---------------------------------------------

bool University::CreateNewFaculty(long fNo, string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId) // Function to create a new faculty member 11/06/2012
{

  bool valid = CheckFDepIdValidity(fDepId); // Checks for proper faculty id
  if(!valid)
    {
      cout << "The " << fDepId << " is not valid" << endl;
      return failure;
    }

  Faculty newFac(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId); //Creates new faculty member
  Faculties.push_back(newFac);

  return success;

}

//---------------------------------------------

bool University::CheckFDepIdValidity(long fDepId) // Function to check for valid department faculty id 11/06/2012
{

  for(int i=0; i<Faculties.size(); i++)
    {
      if(Faculties[i].departId == fDepId)
	return success;
    }

  return failure;

}

//---------------------------------------------

bool University::RemoveAFaculty(long fFactId) // Function to remove a current faculty member 11/06/2012
{

  bool valid = CheckFactIdValidity(fFactId); // Check for valid existing faculty id
  if(!valid)
    {
      cout << "The faculty id " << fFactId << " does not exist" << endl;
      return failure;
    }


}

//---------------------------------------------

bool University::CheckFactIdValidity(long fFactId) // Function to check for a valid existing faculty id 11/06/2012
{

  for(int i=0; i<Faculties.size(); i++)
    {
      if(Faculties[i].id == fFactId)
	return success;
    }

  return failure;

}

//---------------------------------------------

bool University::ListCoursesTaughtByFaculty(long fFactId) // Function to list courses taught by a specific faculty member 11/06/2012
{

  bool valid = CheckFactIdValidity(fFactId); // Checks for validity faculty id
  if(!valid)
    {
      cout << "The faculty id " << fFactId << " does not exist" << endl;
      return failure;
    }
  else
    {
      for(int i=0; i<Courses.size(); i++)
	if(Courses[i].isTaughtBy == fFactId)
	  {
	    cout << "The following course is taught by " << fFactId << "\t"
		 << "Course Name: " << Courses[i].name << " and Course ID: " << Courses[i].departId << endl;
	  }

    } 

  return success;

}

//---------------------------------------------

bool University::ListCoursesTakenByStudent(long sStId) // Function to list all courses taken by a specific student 11/06/2012
{

  bool valid = CheckStIdValidity(sStId); // Checks for valid student id
  if(!valid)
    {
      cout << "The student id " << sStId << " does not exist" << endl;
      return failure;
    }
  //else
  //{
  //for(int i=0; i<Courses.size(); i++)
  //if(Courses[i].isTaughtBy == fFactId)
  //{
  //cout << "The following course is taught by " << fFactId << "\t"
  //<< "Course Name: " << Courses[i].name << " and Course ID: " << Courses[i].departId << endl;
  //}

  //}

  //return success;
  /* Need to modify add a course for student first since coursesTaken vector has not been established */

}

//---------------------------------------------

bool University::ListFacultiesInDepartment(long depId) // Function to list all current faculties within a department 11/06/2012
{

  bool valid = CheckDepValidity(depId); // Checks for a valid department id
  if(!valid)
    {
      cout << "The department id " << depId << " does not exist" << endl;
      return failure;
    }
  else
    {
      for(int i=0; i<Faculties.size(); i++)
        if(Faculties[i].departId == depId)
          {
            cout << "The following faculties belong to department id: " << depId << "\t"
                 << "Faculty Name: " << Faculties[i].name << " and Faculty ID: " << Faculties[i].id << endl;
          }

    }

  return success;

}

//---------------------------------------------

bool University::ListStudentsOfAFaculty(long fFactId) // Function to list all students of a faculty member 11/06/2012
{

  bool valid = CheckFactIdValidity(fFactId); // Checks for a valid faculty id
  if(!valid)
    {
      cout << "The faculty id " << fFactId << " does not exist" << endl;
      return failure;
    }
  else
    {
      for(int i=0; i<Students.size(); i++)
        if(Students[i].advisorId == fFactId)
          {
            cout << "The following students belong to faculty id: " << fFactId << "\t"
                 << "Student Name: " << Students[i].name << " and Student ID: " << Students[i].id << endl;
          }

    }

  return success;

}

//---------------------------------------------

bool University::ListCoursesOfADepartment(long depId) // Function to list all courses within a department 11/06/2012
{

  bool valid = CheckDepValidity(depId); // Checks department validity
  if(!valid)
    {
      cout << "The department id " << depId << " does not exist" << endl;
      return failure;
    }
  else
    {
      for(int i=0; i<Courses.size(); i++)
        if(Courses[i].departId == depId)
          {
            cout << "The following courses exist in department " << depId << "\t"
                 << "Course Name: " << Courses[i].name << " and Course ID: " << Courses[i].departId << endl;
          }

    }

  return success;

}

//---------------------------------------------

bool University::AddACourseForAStudent(long cCRN, long sStId) // Function to add a course for a specific student 11/06/2012
{

  bool valid = CheckCRNValidity(cCRN); // Checks course id validity
  if(!valid)
    {
      cout << "The course id provided " << cCRN << " is not valid" << endl;
      return failure;
    }

  valid = CheckStIdValidity(sStId); // Checks student id validity
  if(!valid)
    {
      cout << "The student id provided " << sStId << " is not valid" << endl;
      return failure;
    }

  for(int i=0; i<Courses.size(); i++) // Assigns the course to student
    if(Courses[i].CRN == cCRN)
      if(Courses[i].assignedSeats < Courses[i].maxAvailableSeats)
	{
	  for(int j=0; j<Students.size(); j++)
	    if(Students[j].id == sStId)
	      {
		Students[j].coursesTaken.push_back(Courses[i]);
		Courses[i].assignedSeats++;
	      }
	
  return success;

  }

  return failure;

}

//---------------------------------------------

bool University::DropACourseForAStudent(long cCRN, long sStId) // Function to drop a course for a specific student 11/06/2012
{

  bool valid = CheckCRNValidity(cCRN); // Checks course if validity
  if(!valid)
    {
      cout << "The course id provided " << cCRN << " is not valid" << endl;
      return failure;
    }

  valid = CheckStIdValidity(sStId); // Checks student id validity
  if(!valid)
    {
      cout << "The student id provided " << sStId << " is not valid" << endl;
      return failure;
    }

  for(int i=0; i<Courses.size(); i++) // Removes course
    if(Courses[i].CRN == cCRN)
      //if(Courses[i].assignedSeats < Courses[i].maxAvailableSeats)
        {
          for(int j=0; j<Students.size(); j++)
            if(Students[j].id == sStId)
              {
                //Students[j].coursesTaken.erase(Courses[i]);
                Courses[i].assignedSeats--;
              }

	  return success;

	}

  return failure;

}

//---------------------------------------------

bool University::AssignDepartmentChair(long facultyId, long departId)
{

}

//---------------------------------------------

bool University::AssignInstructorToCourse(long facultyId, long courseId)
{

}

//---------------------------------------------

bool University::ListDepartments() // Function to list all departments 11/06/2012
{

  for(int i=0; i<Departments.size(); i++)
    {
    cout << "The department id is: " <<  Departments[i].depId << " and department name is: " << Departments[i].name << endl; 
    return success;
    }

}

//---------------------------------------------

bool University::ListStudents() // Function to list all students 11/06/2012
{

  for(int i=0; i<Students.size(); i++)
    {
      cout << "The student id is: " <<  Students[i].id << " and student name is: " << Students[i].name << endl;
      return success;
    }

}

//---------------------------------------------

bool University::ListCourses() // Function to list all courses 11/06/2012
{

  for(int i=0; i<Courses.size(); i++)
    {
      cout << "The course id is: " <<  Courses[i].CRN << " and course name is: " << Courses[i].name << endl;
      return success;
    }

}

//---------------------------------------------

bool University::ListFaculties() // Function to list all faculty members 11/06/2012
{

  for(int i=0; i<Faculties.size(); i++)
    {
      cout << "The faculty id is: " <<  Faculties[i].id << " and faculty name is: " << Faculties[i].name << endl;
      return success;
    }

}

//---------------------------------------------

bool University::ProcessTransFile(string fileName) // Function to process a file created by a user 11/06/2012
{

  cout << "Please type in the file name that you wish to process" << endl;
  cin >> fileName; // reads in file name

  ifstream fin;
  fin.open(fileName.data());

  if(!fin); // checks to see if file exists
  cout << "The file you have inputed does not exist" << endl;

  string cmd;
  string wd, wd2, wd3, wd4, wd5, wd6;
  long num, num2, num3;
  float float1;
  int int1, int2;
 
  while(!fin.eof())
    fin >> cmd; // reads first string into a command variable

  if(cmd == "CreateNewDepartment") // depending on command variable functions are carried out to complete command
    {
      CreateNewDepartment(wd, wd2, num);
      return success;
    }
  if(cmd == "RemoveADepartment")
    {
      RemoveADepartment(num);
      return success;
    }
  if(cmd == "CreateNewStudent")
    {
      CreateNewStudent(int1, wd, wd2, wd3, wd4, wd5, int2, wd6, num);
      return success;
    }
  if(cmd == "RemoveAStudent")
    {
      RemoveAStudent(num);
      return success;
    }
  if(cmd == "CreateNewCourse")
    {
      CreateNewCourse(wd, num, num2, int1);
      return success;
    }
  if(cmd == "RemoveACourse")
    {
      RemoveACourse(num);
      return success;
    }
  if(cmd == "CreateNewFaculty")
    {
      CreateNewFaculty(int1, wd, wd2, wd3, wd4, wd5, float1, int2, num);
      return success;
    }
  if(cmd == "RemoveAFaculty")
    {
      RemoveAFaculty(num);
      return success;
    }
  if(cmd == "ListCoursesTaughtByFaculty")
    {
      ListCoursesTaughtByFaculty(num);
      return success;
    }
  if(cmd == "ListCoursesTakenByStudent")
    {
      ListCoursesTakenByStudent(num);
      return success;
    }
  if(cmd == "ListFacultiesInDepartment")
    {
      ListFacultiesInDepartment(num);
      return success;
    }
  if(cmd == "ListStudentsOfAFaculty")
    {
    ListStudentsOfAFaculty(num);
    return success;
    }
  if(cmd == "ListCoursesOfADepartment")
    {
      ListCoursesOfADepartment(num);
      return success;
    }
  if(cmd == "AddACourseForAStudent")
    {
      AddACourseForAStudent(num, num2);
      return success;
    }
  if(cmd == "DropACourseForAStudent")
    {
      DropACourseForAStudent(num, num2);
      return success;
    }
  if(cmd == "AssignDepartmentChair")
    {
      AssignDepartmentChair(num, num2);
      return success;
    }
  if(cmd == "AssignInstructorToCourse")
    {
      AssignInstructorToCourse(num, num2);
      return success;
    }
  if(cmd == "ListDepartments")
    {
      ListDepartments();
      return success;
    }
  if(cmd == "ListStudents")
    {
      ListStudents();
      return success;
    }
  if(cmd == "ListCourses")
    {
      ListCourses();
      return success;
    }
  if(cmd == "ListFaculties")
    {
      ListFaculties();
      return success;
    }

  fin.close();
}

//---------------------------------------------

#endif // University_CPP
