#include "Course.h"
// Filling out Course constructor
Course::Course(string nm, string desc, char grd, int creds)
{
    setName(nm);
    setDesc(desc);
    setGrade(grd);
    setCredits(creds);
}
// Filling out setters
void Course::setName(string nm)
{
    name = nm;
}
void Course::setDesc(string desc)
{
    description = desc;
}
void Course::setGrade(char grd)
{
    grade = grd;
}
void Course::setCredits(int creds)
{
    credits = creds;
}
// Filling out getters
string Course::getName()
{
    return name;
}
string Course::getDescription()
{
    return description;
}
char Course::getGrade()
{
    return grade;
}
int Course::getCredits()
{
    return credits;
}
