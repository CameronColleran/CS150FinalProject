#include <iostream>
#include <iomanip>
using namespace std;
#include "Semester.h"

// Filling out constructor
Semester::Semester(string nm, vector<Course> v)
{
    setName(nm);
    setCourseVector(v);
}
// Filling out setters
void Semester::setName(string nm)
{
    name = nm;
}
void Semester::setCourseVector(vector<Course> v)
{
    course_vector = v;
}
// Filling out getters
string Semester::getName()
{
    return name;
}
vector<Course> Semester::getCourseVector()
{
    return course_vector;
}
double Semester::getSemesterGpa()
{
    calculateGpa(semester_gpa);
    return semester_gpa;
}
// Filling out getNumOfClasses function
double Semester::getNumOfClasses()
{
    return course_vector.size();
}
// Function which gets the total numeric value of the grades that student earned during the semester
double Semester::getTotalGrades()
{
    double total_grades = 0;

    for (Course c : course_vector)
    {
        switch (c.getGrade())
        {
            case 'A':
                total_grades+= 4;
                continue;
            case 'a':
                total_grades+= 4;
                continue;
            case 'B':
                total_grades += 3;
                continue;
            case 'b':
                total_grades += 3;
                continue;
            case 'C':
                total_grades += 3;
                continue;
            case 'c':
                total_grades += 2;
                continue;
            case 'D':
                total_grades += 1;
                continue;
            case 'd':
                total_grades += 1;
                continue;
                // Otherwise F which adds 0 to total grades
        }
    }
    return total_grades;
}

// Filling out calc gpa function
void Semester::calculateGpa(double &gpa)
{
    // GPA = (grades) / (# of classes)
    gpa = getTotalGrades() / getNumOfClasses();
}
// Filling out printReport function, formatted output
void Semester::printReport()
{
    cout << "=======================================================================" << endl;
    cout << setw(40) << right << getName() << endl;
    cout << left << setw(15) << "Course" << setw(38) << "Description" << setw(10) << "Grade" << setw(10) << "Credits" << endl;
    cout << "------         -----------                           -----     ------- " << endl;
    for (Course c : course_vector)
    {
        cout << setw(15) << c.getName() << setw(40) << c.getDescription() << setw(11) << c.getGrade() << c.getCredits() << endl;
    }
    cout << "\nSEMESTER GPA: " << setprecision(3) << fixed << setw(34) << getSemesterGpa() << "TOTAL CREDITS:" << right << setw(5) << getTotalCredits() <<  endl;
    cout << "=======================================================================" << endl;
}
int Semester::getTotalCredits()
{
    int credits = 0;
    for (Course c : course_vector)
    {
        credits += c.getCredits();
    }
    return credits;
}
