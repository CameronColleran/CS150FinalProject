#include <string>
#include <vector>
#include "Course.h"
using namespace std;

#ifndef SEMESTER_H
#define SEMESTER_H


class Semester
{
    // Instance variables
    private:
        string name;
        vector<Course> course_vector;
        double semester_gpa;

    public:
        // Constructor prototype
        Semester(string nm, vector<Course> v);

        // Setter prototypes
        void setName(string nm);
        void setCourseVector(vector<Course> v);

        // Getter prototypes
        string getName();
        vector<Course> getCourseVector();
        double getSemesterGpa();

        // Other function prototypes
        double getNumOfClasses();
        double getTotalGrades();
        void calculateGpa(double &gpa);
        void printReport();
        int getTotalCredits();

        // Destructor
        ~Semester()
        {

        }
};


#endif
