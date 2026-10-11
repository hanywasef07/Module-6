#include "Course.h"
#include <fstream>
#include <sstream>
#include <iomanip>

// Default constructor
// Precondition: None
// Postcondition: Initializes courseName to an empty string
Course::Course()
{
    courseName = "";
}

// Constructor with course name
// Precondition: name is a valid string representing the course name
// Postcondition: Initializes courseName to the given name
Course::Course(string name)
{
    courseName = name;
}

// Destructor
// Precondition: None
// Postcondition: Cleans up any resources used by the Course object
Course::~Course()
{
}
// Precondition: None
// Postcondition: Returns the course name
string Course::getCourseName() const
{
    return courseName;
}

// Precondition: None
// Postcondition: Returns the number of students
int Course::getNumberOfStudents() const
{
    return studentIDs.getSize();
}

// Precondition: None
// Postcondition: Sets the course name
void Course::setCourseName(string name)
{
    courseName = name;
}

// Precondition: filename contains the name of a data file
// Postcondition: Reads course information and student records from the file
bool Course::readFile(const string& filename)
{
    ifstream inputFile(filename);

    // Check if the file opened successfully
    if (!inputFile.is_open())
    {
        return false;
    }

    string line;

    // Read the course name from the first line
    if (!getline(inputFile, line))
    {
        return false;
    }

    // Clear existing student records
    studentIDs.clear();
    studentNames.clear();
    studentScores.clear();
    studentGrades.clear();

    courseName = line;

    // Read student records
    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string idText;
        string name;
        string scoreText;

        // Read comma-separated values
        if (!getline(ss, idText, ',') || !getline(ss, name, ',') || !getline(ss, scoreText))
        {
            continue;
        }

        int id;
        double score;

        stringstream idStream(idText);
        stringstream scoreStream(scoreText);

        if (!(idStream >> id) || !(scoreStream >> score))
        {
            continue;
        }

        // Remove leading spaces from student name
        size_t first = name.find_first_not_of(" \t");

        if (first == string::npos)
        {
            continue;
        }

        name = name.substr(first);

        // Determine the student's letter grade
        char grade;

        if (score >= 90)
        {
            grade = 'A';
        }
        else if (score >= 80)
        {
            grade = 'B';
        }
        else if (score >= 70)
        {
            grade = 'C';
        }
        else if (score >= 60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        // Store student information in the four MyBag containers
        studentIDs.insert(id);
        studentNames.insert(name);
        studentScores.insert(score);
        studentGrades.insert(grade);
    }

    inputFile.close();

    return true;
}

// Precondition: None
// Postcondition: Searches for a student ID and returns its index, or -1 if not found
int Course::searchStudentID(int id) const
{
    return studentIDs.search(id);
}

// Precondition: None
// Postcondition: Searches for a student name and returns its index, or -1 if not found
int Course::searchStudentName(const string& name) const
{
    return studentNames.search(name);
}

// Precondition: index is a valid index in the MyBag containers
// Postcondition: Removes the student record at the specified index and returns true if successful, false otherwise
bool Course::removeStudent(int index)
{
    if (index < 0 || index >= studentIDs.getSize())
    {
        return false;
    }
    studentIDs.remove(index);
    studentNames.remove(index);
    studentScores.remove(index);
    studentGrades.remove(index);
    return true;
}

// Precondition: None
// Postcondition: Returns the average score of all students in the course
double Course::getAverageScore() const
{
    int numStudents = studentScores.getSize();
    if (numStudents == 0)
    {
        return 0.0;
    }
    double totalScore = 0.0;
    for (int i = 0; i < numStudents; ++i)
    {
        totalScore += studentScores.getValue(i);
    }
    return totalScore / numStudents;
}

// Precondition: course is a valid Course object
// Postcondition: Displays the course name, student records,
// and average score and grade
ostream& operator<<(ostream& out, const Course& course)
{
    out << "\n\t\t" << course.courseName;
    out << "\n\t\t" << left << setw(9) << "index" << setw(31) << "StudentID" << setw(11) << "Name" << setw(14) << "Score" << "Grade\n";
    out << "\t\t" << string(70, char(196)) << "\n";


    for (int i = 0; i < course.studentIDs.getSize(); i++)
    {
        out << "\t\t" << right << setw(5) << i << setw(13) << course.studentIDs.getValue(i)
            << setw(26) << course.studentNames.getValue(i)
            << setw(12) << course.studentScores.getValue(i)
            << setw(10) << course.studentGrades.getValue(i) << "\n";
	}

    double average = course.getAverageScore();

    char grade;

    if (average >= 90)
    {
        grade = 'A';
    }
    else if (average >= 80)
    {
        grade = 'B';
    }
    else if (average >= 70)
    {
        grade = 'C';
    }
    else if (average >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    out << "\n\t\tAverage score and grade: " << average << "(" << grade << ")\n";

    return out;
}

// Precondition: left and right are valid Course objects
// Postcondition: Compares two Course objects based on their course names
bool operator<(const Course& left, const Course& right)
{
    return left.courseName < right.courseName;
}