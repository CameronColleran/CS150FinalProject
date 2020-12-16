/*
 * main.cpp: Program for keeping track of semesters and their corresponding classes, in addition to semester gpa and
 * credits, and also cumulative gpa and credits
 * Author: Cameron Colleran
 * Module: Final Project
 * Problem statement: Create a program which allows user to keep track of their classes taken, in which semester they were taken, in
 * addition to their semester credits and gpa, and cumulative gpa and credits
 *
 * Algorithm:
 * 1. Create classes representing a Course and Semester
 *      Course class:
 *          instance variables: name, description, grade, credits
 *      Semester class:
 *          instance variables: name, vector<Course>, semester_gpa
 * 2. Fill those classes with appropriate functions
 * 3. Create function in main.cpp which:
 *      Starts loop, prompting user whether they want to view their classes or add new ones
 *              - If they want to view, open data file (courses.csv) and input data, then display nicely to screen
 *              - If they want to add, prompt them to add, then write to courses.csv file
 *              - Otherwise exit the program
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Course.h"
#include "Semester.h"

using namespace std;
typedef string user_input; // type def for input, could change to different type if we want to do an int input for example

static const int CREDIT_LIMIT = 24;
void launchMenu();
// Driver
int main()
{
    launchMenu();
    return 0;
}

// Function which launches menu and does I/O, is the heart of the program
void launchMenu()
{

    // Starting menu system
    // ASCII art header:
    cout << " ________  ________  ________  ________  _______           _________  ________  ________  ________  ___  __    _______   ________     \n"
            "|\\   ____\\|\\   __  \\|\\   __  \\|\\   ___ \\|\\  ___ \\         |\\___   ___\\\\   __  \\|\\   __  \\|\\   ____\\|\\  \\|\\  \\ |\\  ___ \\ |\\   __  \\    \n"
            "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\   __/|        \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|\\ \\   __/|\\ \\  \\|\\  \\   \n"
            " \\ \\  \\  __\\ \\   _  _\\ \\   __  \\ \\  \\ \\\\ \\ \\  \\_|/__           \\ \\  \\ \\ \\   _  _\\ \\   __  \\ \\  \\    \\ \\   ___  \\ \\  \\_|/_\\ \\   _  _\\  \n"
            "  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\           \\ \\  \\ \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\ \\  \\_|\\ \\ \\  \\\\  \\| \n"
            "   \\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\_______\\ \\_______\\           \\ \\__\\ \\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \\__\\\\ _\\ \n"
            "    \\|_______|\\|__|\\|__|\\|__|\\|__|\\|_______|\\|_______|            \\|__|  \\|__|\\|__|\\|__|\\|__|\\|_______|\\|__| \\|__|\\|_______|\\|__|\\|__|" << endl;
    cout << "\nWELCOME TO GRADE TRACKER" << endl;

    user_input input;
    cout << "(1) Print report of your grades" << endl;
    cout << "(2) Add a new semester and classes" << endl;
    cout << "(3) Exit program" << endl;
    cin >> input;

    while (input != "3")
    {
        // Print reports of all semesters
        if (input == "1")
        {
            // HOOKING UP TO CSV FILE TO GET SAVED DATA (FILE I/O)


            // Creating vector of semester objects
            vector<Semester> semester_vector;

            // Connecting to csv file to populate vector with saved semester objects
            string line;
            ifstream file;
            file.open("/Users/cameroncolleran/CLionProjects/CS 150/FinalProject/courses.csv");


            // Loop to go through csv and add semesters and their subsequent courses to the semester vector
            // Format for csv: semester name followed by each class in that semester all on the same line, with each element separated by commas
            while (getline(file, line))
            {
                // Parsing line by comma
                vector<string> line_elements;
                stringstream ss(line);
                string element;

                while(ss.good())
                {
                    getline(ss, element, ',');
                    line_elements.push_back(element);
                }


                // First element of string vector will always be the semester name
                string semester_name = line_elements[0];

                // Creating course vector
                vector<Course> temp_course_vector;

                // Looping through string array and creating course objects to add to vector
                for (int i = 1; i < line_elements.size(); i+=4)
                {
                    // Courses will always have the same format(name, description, grade, credits), so can parse vector in this format
                    string name = line_elements[i];
                    string desc = line_elements[i + 1];
                    string grade_str = line_elements[i + 2];

                    char grade = grade_str[0];
                    double credits = stod(line_elements[i  + 3]);
                    Course temp_course(name, desc, grade, credits);
                    temp_course_vector.push_back(temp_course);
                }

                // Making semester object
                Semester temp_semester(semester_name, temp_course_vector);

                // Adding semester object to semester vector
                semester_vector.push_back(temp_semester);
            }

            file.close();
            file.clear();

            int total_classes = 0;
            int total_grades = 0;
            int total_credits = 0;

            // Looping through semester vector and printing data to console
            for (Semester s : semester_vector)
            {
                s.printReport();
                total_classes += s.getNumOfClasses();
                total_grades += s.getTotalGrades();
                total_credits += s.getTotalCredits();

                cout << endl;
            }
            // Printing final cumulative gpa and credits to
            double cumulative_gpa = (double) total_grades / (double) total_classes;

            cout << "CUMULATIVE GPA: " << cumulative_gpa << setw(30) << "TOTAL CREDITS: " << total_credits << endl << endl;
        }

        // Add a new semester
        else if (input == "2")
        {
            cin.clear();
            fflush(stdin);
            // Prompting user to enter name for semester
            cout << "Please enter the semester name (i.e. \"Fall 2020\"): ";
            string semester_name;
            getline(cin,semester_name);

            vector<Course> temp_course_vector;
            int total_credits = 0;

            string name, desc;
            char grade;
            int credits;
            int keep_going = 0;

            while (keep_going == 0)
            {
                // Prompting user to enter course name
                cout << "Enter course name (i.e. \"CS 150\"): ";
                getline(cin,name);

                // Prompting user to enter course description
                cout << "Enter course description (\"C++ PROGRAMMING\"): ";
                getline(cin,desc);

                // Prompting user to enter a grade for the course, and making sure that they enter the right input
                while (true)
                {
                    cout << "Enter letter grade for course (i.e. \"B\"): ";
                    cin >> grade;
                    // If proper input, then break
                    if (grade == 'A' || grade == 'a' || grade == 'B' || grade == 'b' || grade == 'C' || grade == 'c'
                    || grade == 'D' || grade == 'd' || grade == 'F' || grade == 'f')
                        break;
                    cout << "Improper input, please retry" << endl;
                }

                // Prompting user to enter number of credits
                cout << "Enter number of credits course is worth: ";
                cin >> credits;
                total_credits += credits;

                // Max credits of 24 per semester can be taken
                if (total_credits > CREDIT_LIMIT)
                {
                    cout << "Cannot take more than 24 credits per semester" << endl;
                    break;
                }
                temp_course_vector.push_back(Course(name,desc,grade,credits));

                cin.clear();
                fflush(stdin);
                // Prompting user to enter if they would like to enter another class for the semester
                cout << "Would you like to enter another class? (0 = yes, 1 = no): ";
                cin >> keep_going;
            }

            // Outputting semester to csv file to save persistently
            ofstream file;
            file.open("/Users/cameroncolleran/CLionProjects/CS 150/FinalProject/courses.csv", std::ios_base::app | std::ios_base::out);

            // Outputting semester name first
            file << endl << semester_name;

            // Outputting each course on same line as name
            for (Course c : temp_course_vector)
            {
                file << "," << c.getName() << "," << c.getDescription() << "," << c.getGrade() << "," << c.getCredits();
            }
            cout << endl;


        }
        // Otherwise was invalid input
        else
        {
            cout << "Invalid input, retry" << endl;
        }

        // Re-prompting user
        cout << "(1) Print report of your grades" << endl;
        cout << "(2) Add a new semester and classes" << endl;
        cout << "(3) Exit program" << endl;
        cin >> input;
    }

    cout << "Exiting program..." << endl;


}
