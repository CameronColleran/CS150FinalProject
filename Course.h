#include <string>
using namespace std;

#ifndef COURSE_H
#define COURSE_H


class Course
{
    // Instance variables
    private:
        string name;
        string description;
        char grade;
        int credits;

    public:
        // Constructor prototype
        Course(string nm, string desc, char grd, int creds);
        // Setter prototypes
        void setName(string nm);
        void setDesc(string desc);
        void setGrade(char grd);
        void setCredits(int creds);
        // Getter prototypes
        string getName();
        string getDescription();
        char getGrade();
        int getCredits();

        // Destructor
        ~Course()
        {

        }

};


#endif
