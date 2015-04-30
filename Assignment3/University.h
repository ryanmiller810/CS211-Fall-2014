#ifndef University_H
#define University_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//----------------------------------------

#include "Course.h"
#include "Department.h"
#include "Person.h"

class University
{

 protected:

  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;

 public:

  University();
  ~University();

  bool CreateNewDepartment(string depName, string depLoc, long chairId);
  bool CheckFacValidity(long chairId);
  bool RemoveADepartment(long depId);
  bool CheckDepValidity(long depId);
  int CountFac(long depId);
  int CountCourse(long depId);
  bool CreateNewStudent(long sNo, string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  bool CheckMajorValidity(string sMajor);
  bool CheckAdvValidity(long sAdvisorId);
  bool RemoveAStudent(long sStId);
  bool CheckStIdValidity(long sStId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool CheckTaughtByValidity(long cTaughtBy);
  bool CheckDepIdValidity(long cDepId);
  bool RemoveACourse(long cCRN);
  bool CheckCRNValidity(long cCRN);
  bool CreateNewFaculty(long fNo, string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool CheckFDepIdValidity(long fDepId);
  bool RemoveAFaculty(long fFactId);
  bool CheckFactIdValidity(long fFactId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment(long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse(long facultyId, long courseId);

  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  bool ProcessTransFile(string fileName);

};

#endif // University_H
