#pragma once

#include <iostream>
#include <string>
#include "MyBagTemplate.h"

using namespace std;

class Course
{
private:
    string courseName;

    MyBagTemplate::MyBag<int> studentIDs;
    MyBagTemplate::MyBag<string> studentNames;
    MyBagTemplate::MyBag<double> studentScores;
    MyBagTemplate::MyBag<char> studentGrades;

public:
    // Constructors and destructor
    Course();
    Course(string name);
    ~Course();

    // Accessors
    string getCourseName() const;
    int getNumberOfStudents() const;

    // Mutators
    void setCourseName(string name);

    // Operations
    bool readFile(const string& filename);
    int searchStudentID(int id) const;
    int searchStudentName(const string& name) const;
    bool removeStudent(int index);
    double getAverageScore() const;

    // Friend functions
    friend ostream& operator<<(ostream& out, const Course& course);
    friend bool operator<(const Course& left, const Course& right);
};