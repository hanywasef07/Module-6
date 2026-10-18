//Name: Hany, Aleeza, and Thanh
// Date: 10/12/2026
// Description: Module 6 - Templates, Iterators, and STL

#include <iostream>
#include "input.h"
#include "MyBag.h"
#include "MyBagTemplate.h"
#include "Course.h"

using namespace std;
// Function prototypes
char menuOption();
void nonTemplateOption();
void templateOption();
void applicationOption();

int main() 
{
	bool running = true;
	char option;

	while (running)
	{
		system("cls");
		option = menuOption();
		switch (option)
		{
		case '1':
			nonTemplateOption();
			break;
		case '2':
			templateOption();
			break;
		case '3':
			applicationOption();
			break;
		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}

	return 0;
}

//precondition: none
//postcondition: returns a char value of the menu option selected by the user
char menuOption()
{
	cout << "\tCMPR131 Chapter 6: non-template and template Container by Hany, Aleeza, and Thanh (10/12/26)\n";
	cout << "\t" << string(105, char(205));
	cout << "\n\t\t1> Non-template MyBag container of int";
	cout << "\n\t\t2> Template MyBag<double> container";
	cout << "\n\t\t3> Application using MyBag container\n";
	cout << "\t" << string(105, char(196));
	cout << "\n\t\t0 > Exit\n";
	cout << "\t" << string(105, char(205));
	char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,0")));
	return option;
}

//precondition: none
//postcondition: executes the non-template MyBag of integers menu option
void nonTemplateOption()
{
	MyBag bag; // Create an instance of MyBag for integers
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\n\t1> Non-template MyBag of integers\n";
		cout << "\t" << string(100, char(205));
		cout << "\n\t\tA> clear";
		cout << "\n\t\tB> insert";
		cout << "\n\t\tC> search";
		cout << "\n\t\tD> remove";
		cout << "\n\t\tE> sort";
		cout << "\n\t\tF> display\n";
		cout << "\t" << string(100, char(196));
		cout << "\n\t\t0> return\n";
		cout << "\t" << string(100, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,E,F,0")));
		switch (option)
		{
		case 'A': // Clear the bag
		{
			bag.clear();
			cout << "\n\t\tMyBag is cleared of all elements.\n\n"; 
			system("pause");

			break;
		}
		case 'B': // Insert a value into the bag
		{
			int value = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
			bag.insert(value);

			cout << "\n\t\t" << value << " has been inserted into MyBag.\n\n";
			system("pause");
			break;
		}
		case 'C': // Search for a value in the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				int value = inputInteger("\n\t\tEnter a value to search from MyBag: ");
				int index = bag.search(value);
				if (index != -1)
				{
					cout << "\n\t\tValue " << value	<< " is found at subscript #" << index << " from MyBag.\n";
				}
				else
				{
					cout << "\n\t\tValue " << value << " is not found from MyBag.\n";
				}
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 'D': // Remove a value from the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				int index = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, bag.getSize() - 1);

				// Save the value before removing it
				int valueToRemove = bag.getValue(index);

				if (bag.remove(index))
				{
					cout << "\n\t\tValue " << valueToRemove << " has been deleted from MyBag.\n";
				}
			}

			cout << "\n";
			system("pause");
			break;
		}
		case 'E': // Sort the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				bag.sort();

				cout << "\n\t\tMybag has been sorted.\n";
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 'F': // Display the contents of the bag
		{
			cout << "\n\t\t" << bag << "\n";
			cout << "\n";
			system("pause");
			break;
		}
		case '0':
			running = false;
			break;
		default:
			cout << "\n\t\tInvalid option. Please try again.\n";
			break;
		}
	}
}

//precondition: none
//postcondition: executes the template MyBag of doubles menu option
void templateOption()
{
	// Create an instance of MyBag for doubles
	MyBagTemplate::MyBag<double> bag;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\n\t2> Template MyBag of doubles\n";
		cout << "\t" << string(100, char(205));
		cout << "\n\t\tA> clear";
		cout << "\n\t\tB> insert";
		cout << "\n\t\tC> search";
		cout << "\n\t\tD> remove";
		cout << "\n\t\tE> sort";
		cout << "\n\t\tF> display\n";
		cout << "\t" << string(100, char(196));
		cout << "\n\t\t0> return\n";
		cout << "\t" << string(100, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,E,F,0")));
		switch (option)
		{
		case 'A': // Clear the bag
		{
			bag.clear();
			cout << "\n\t\tMyBag is cleared of all elements.\n";
			cout << "\n";
			system("pause");
			break;
		}
		case 'B': // Insert a value into the bag
		{
			double value = inputDouble("\n\t\tEnter a value and insert into MyBag: ");

			bag.insert(value);
			cout << "\n\t\t" << value << " has been inserted into MyBag.\n";
			cout << "\n";
			system("pause");
			break;
		}
		case 'C': // Search for a value in the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				double value = inputDouble("\n\t\tEnter a value to search from MyBag: ");

				int index = bag.search(value);

				if (index != -1)
				{
					cout << "\n\t\tValue " << value << " is found at subscript #" << index << " from MyBag.\n";
				}
				else
				{
					cout << "\n\t\tValue " << value << " is not found from MyBag.\n";
				}
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 'D': // Remove a value from the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				int index = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, bag.getSize() - 1);
				double valueToRemove = bag.getValue(index);
				if (bag.remove(index))
				{
					cout << "\n\t\tValue " << valueToRemove << " has been deleted from MyBag.\n";
				}
				//bag.remove(index);
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 'E': // Sort the bag
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				bag.sort();
				cout << "\n\t\tMybag has been sorted.\n";
			}

			system("pause");
			break;
		}
		case 'F': // Display the contents of the bag
		{
			cout << "\n\t\t" << bag << "\n";
			cout << "\n";
			system("pause");
			break;
		}

		case '0':
			running = false;
			break;
		default:
			cout << "\n\t\tInvalid option. Please try again.\n";
			break;
		}
	}
}


//precondition: none
//postcondition: executes the application menu option
void applicationOption()
{
	Course* courses = nullptr; // Pointer to an array of Course objects
	int numberOfCourses = 0; // Number of courses
	int loadedCourses = 0; // Number of loaded courses
	const int ONE = 1;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\n\t\t3> Courses using MyBags of integers, strings, doubles, and chars\n";
		cout << "\t\t" << string(100, char(196));
		cout << "\n\t\t  1> Specify the number of courses";
		cout << "\n\t\t  2> Read in data file and insert into courses";
		cout << "\n\t\t  3> Search for a student record from a course";
		cout << "\n\t\t  4> Remove a student record from a course";
		cout << "\n\t\t  5> Display course(s)\n";
		//cout << "\t" << string(100, char(196));
		cout << "\t\t  0> return\n";
		cout << "\t\t" << string(100, char(196));
		option = toupper(inputChar("\n\t\t  Option: ", static_cast<string>("1,2,3,4,5,0")));
		switch (option)
		{
		case '1':
		{
			int newNumberOfCourses = inputInteger("\n\t\t1> Enter the number of courses: ", 1, 100); // Limit to 100 courses for practicality
			delete[] courses; // Delete the previous array of courses if it exists
			courses = new Course[newNumberOfCourses]; // Allocate a new array of courses
			numberOfCourses = newNumberOfCourses; // Store the new number of courses
			// Reset because the previous courses were deleted
			loadedCourses = 0; // Reset the count of loaded courses
			cout << "\n\t\t" << numberOfCourses << " Course(s) has been created.\n"; // Inform the user that the courses have been created
			cout << "\n";
			system("pause");
			break;
		}
		case '2':
		{
			// Check if courses have been specified
			if (courses == nullptr || numberOfCourses == 0)
			{
				cout << "\n\t\tERROR: number of courses has not been assigned.\n";
			}
			else
			{
				int courseIndex = 0; // Start from the first course to read data into
				// Loop to read data files for each course
				while (courseIndex < numberOfCourses)
				{
					string filename = inputString("\n\t\t2> Enter a data file name for course[" + to_string(courseIndex) + "] (STOP - return): ", false);

					if (filename == "STOP" || filename == "stop")
					{
						break;
					}

					if (courses[courseIndex].readFile(filename))
					{
						cout << "\n\t\tData from file, " << filename << ", has been read and stored into Courses[" << courseIndex << "].\n";
						courseIndex++;
						if (courseIndex > loadedCourses)
						{
							loadedCourses = courseIndex;
						}
					}
					else
					{
						cout << "\n\t\tERROR: file, " << filename << ", cannot be found. Please re-specify.\n";
					}
				}
			}

			cout << "\n";
			system("pause");
			break;
		}
		case '3':
		{
			// Check if courses have been loaded
			if (courses == nullptr || loadedCourses == 0)
			{
				cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n";
			}
			else
			{
				bool searching = true;
				// Loop to allow searching for student records
				while (searching)
				{
					cout << "\n\t\t\t3> Search by\n";
					cout << "\t\t\t" << string(50, char(196)) << "\n";
					cout << "\t\t\t\t1. ID Number\n";
					cout << "\t\t\t\t2. Name\n";
					cout << "\t\t\t\t0. return\n";
					cout << "\t\t\t" << string(50, char(196)) << "\n";
					char searchOption = inputChar("\t\t\t\tOption: ", static_cast<string>("1,2,0"));
					switch (searchOption)
					{
					case '1': // Search by ID
					{
						int id = inputInteger("\n\t\tEnter a student ID to search: ");
						bool found = false;
						for (int i = 0; i < loadedCourses; i++)
						{
							int index = courses[i].searchStudentID(id);

							if (index != -1)
							{
								cout << "\n\t\tID: " << id << " has been found in Course: " << courses[i].getCourseName() << "\n";
								found = true;
							}
						}

						if (!found)
						{
							cout << "\n\t\tNo student ID: " << id << " found.\n";
						}
						cout << "\n";
						searching = false; // Exit the search loop after searching by ID
						break;
					}

					case '2': // Search by Name
					{
						string name = inputString("\n\t\tEnter a student name to search: ", true);
						bool found = false;
						for (int i = 0; i < loadedCourses; i++)
						{
							int index = courses[i].searchStudentName(name);
							if (index != -1)
							{
								cout << "\n\t\tName '" << name << "' has been found in Course: " << courses[i].getCourseName() << "\n";
								found = true;
							}
						}
						if (!found)
						{
							cout << "\n\t\tNo student name: " << name << " found.\n";
						}
						cout << "\n";
						searching = false;
						break;
					}

					case '0':
					{
						searching = false;
						break;
					}
					}
				}
			}

			cout << "\n";
			system("pause");
			break;
		}
		case '4':
		{
			
			// Check if courses have been loaded
			if (courses == nullptr || loadedCourses == 0)
			{
				cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n";
			}
			else
			{
				cout << "\n\t\t4> Course(s)\n";
				cout << "\t\t" << string(70, char(196)) << "\n";

				// Display available courses
				for (int i = 0; i < loadedCourses; i++)
				{
					cout << "\t\t\t" << i + ONE << ". " << courses[i].getCourseName() << "\n";
				}

				cout << "\t\t" << string(70, char(196)) << "\n";
				// Select a course
				int selection = inputInteger("\t\t\tOption: ", 1, loadedCourses); // Validate selection

				int courseIndex = selection - ONE; // Adjust for 0-based index

				// Enter student ID
				int id = inputInteger("\n\t\tEnter a student ID to search and delete: ");

				// Search for student
				int studentIndex = courses[courseIndex].searchStudentID(id);
				// If student is found, remove the record
				if (studentIndex == -1)
				{
					cout << "\n\t\tNo student ID: " << id << " found.\n";
				}
				else
				{
					// Remove student record
					if (courses[courseIndex].removeStudent(studentIndex))
					{
						cout << "\n\t\tID: " << id << " has been found in Course '" << courses[courseIndex].getCourseName() << "' and has been removed.\n";
					}
				}
			}

			cout << "\n";
			system("pause");
			break;
		}
		case '5':
		{
			if (courses == nullptr || loadedCourses == 0)
			{
				cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n";
			}
			else
			{
				cout << "\n\t\tCourse(s)\n";
				cout << "\t\t" << string(70, char(196)) << "\n";

				// Display the available courses
				for (int i = 0; i < loadedCourses; i++)
				{
					cout << "\n\t\t" << i + ONE << ". " << courses[i].getCourseName();
				}

				// Display the All option
				cout << "\n\t\t" << loadedCourses + ONE << ". all\n";
				cout << "\t\t" << string(70, char(196));
				// Get the user's selection
				int selection = inputInteger("\n\t\tOption: ", 1, loadedCourses + ONE);
				// Display all courses
				if (selection == loadedCourses + ONE)
				{
					for (int i = 0; i < loadedCourses; i++)
					{
						cout << courses[i] << "\n";
					}
				}
				else
				{
					// Display the selected course
					cout << courses[selection - ONE] << "\n";
				}
			}

			cout << "\n";
			system("pause");
			break;
		}
		case '0':
			running = false;
			break;
		default:
			cout << "\n\t\tInvalid option. Please try again.\n";
			break;
		}
	}
	delete[] courses;
}
