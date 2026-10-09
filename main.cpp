//Name: Hany, Aleeza, and Thanh
// Date: 10/12/2026
// Description: Module 6 - Templates, Iterators, and STL

#include <iostream>
#include "input.h"
#include "MyBag.h"

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
		case 'A':
		{
			bag.clear();
			cout << "\n\t\tMyBag is cleared of all elements.\n\n"; 
			system("pause");

			break;
		}
		case 'B':
		{
			int value = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
			bag.insert(value);

			cout << "\n\t\t" << value << " has been inserted into MyBag.\n\n";
			system("pause");
			break;
		}
		case 'C':
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
		case 'D':
		{
			if (bag.getSize() == 0)
			{
				cout << "\n\t\tMyBag is empty.\n";
			}
			else
			{
				int index = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, bag.getSize() - 1);
				bag.remove(index);
			}
			cout << "\n";
			system("pause");
			break;
		}
		case 'E':
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
		case 'F':
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

void templateOption()
{
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
		case 'A':

			break;
		case 'B':

			break;
		case 'C':

			break;
		case 'D':

			break;
		case 'E':

			break;
		case 'F':

			break;
		case '0':
			running = false;
			break;
		default:
			cout << "\n\t\tInvalid option. Please try again.\n";
			break;
		}
	}
}

void applicationOption()
{
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
		cout << "\n\t\t  0> return\n";
		cout << "\t\t" << string(100, char(196));
		option = toupper(inputChar("\n\t\t  Option: ", static_cast<string>("1,2,3,4,5,0")));
		switch (option)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '0':
			running = false;
			break;
		default:
			cout << "\n\t\tInvalid option. Please try again.\n";
			break;
		}
	}
}