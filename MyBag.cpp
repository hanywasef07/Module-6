#include "MyBag.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Default Constructor
//precondition: none
//postcondition: initializes size to 0, capacity to 5, and allocates memory for the data array
MyBag::MyBag()
{
	size = 0;
	capacity = 5; 
	data = new int[capacity];
}

//constructor with capacity parameter
//precondition: capacity must be a positive integer
//postcondition: initializes size to 0, capacity to the specified value, and allocates memory for the data array
MyBag::MyBag(int capacity)
{
	size = 0;	
	if (capacity <= 0)
	{
		capacity = 5; //default capacity 
	}

	this->capacity = capacity; // use this-> to refer to the member variable
	data = new int[this->capacity]; // allocate memory for the data array
}

//Copy constructor
//precondition: other is a valid MyBag object
//postcondition: creates a new MyBag object that is a copy of the other MyBag object
MyBag::MyBag(const MyBag& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];

	for (int i = 0; i < size && i < capacity; i++)
	{
		data[i] = other.data[i];
	}
}

//Copy assignment operator
//Precondition: other is a valid MyBag object
//Postcondition: performs a deep copy of the other MyBag
MyBag& MyBag::operator=(const MyBag& other)
{
	if (this != &other)
	{
		int* temp = new int[other.capacity];

		for (int i = 0; i < other.size; i++)
		{
			temp[i] = other.data[i];
		}

		delete[] data;

		data = temp;
		size = other.size;
		capacity = other.capacity;
	}

	return *this;
}

//Destructor
//precondition: none
//postcondition: deallocates memory for the data array
MyBag::~MyBag()
{
	delete[] data;
}

//Getters
//precondition: none
//postcondition: returns the current size of the MyBag object
int MyBag::getSize() const
{
	return size;
}
//precondition: none
//postcondition: returns the current capacity of the MyBag object
int MyBag::getCapacity() const
{
	return capacity;
}
// Get value at a specific index
int MyBag::getValue(int index) const
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}

	return 0;
}

//Setters
//precondition: size must be a non-negative integer
//postcondition: sets the size of the MyBag object to the specified value, ensuring it does not exceed capacity
void MyBag::setSize(int size)
{
	if (size < 0)
	{
		this->size = 0;
	}
	else if (size > capacity)
	{
		this->size = capacity;
	}
	else
	{
		this->size = size;
	}
}

//precondition: capacity must be a positive integer
//postcondition: sets the capacity of the MyBag object to the specified value, reallocating memory for the data array if necessary
void MyBag::setCapacity(int capacity)
{
	if (capacity < size)
	{
		capacity = size;
	}

	if (capacity <= 0)
	{
		capacity = 1;
	}

	int* temp = new int[capacity];

	for (int i = 0; i < size && i < capacity; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;

	data = temp;
	this->capacity = capacity;
}

//precondition: none
//postcondition: clears the MyBag object by resetting size to 0, but keeps the capacity and data intact
void MyBag::clear()
{
	size = 0; // reset size to 0, but keep the capacity and data intact
}

// Precondition: None
// Postcondition: Inserts the value into the bag, resizing if necessary.
void MyBag::insert(int value)
{
	const int FIVE = 5, TWO = 2;
	if (capacity <= 0)
	{
		setCapacity(FIVE);
	}

	if (size >= capacity)
	{
		setCapacity(capacity * TWO);
	}

	data[size] = value;
	size++;
}

// Precondition: None
// Postcondition: Returns the index of the value if found, otherwise -1.
int MyBag::search(int value) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}

	return -1;
}

// Precondition: index must be a valid subscript
// Postcondition: Removes the element at the specified index
bool MyBag::remove(int index)
{
	const int ONE = 1, TWO = 2, FOUR = 4, FIVE = 5;

	if (index < 0 || index >= size)
	{
		return false;
	}

	//int valueToRemove = data[index];

	// Shift elements to the left
	for (int i = index; i < size - ONE; i++)
	{
		data[i] = data[i + ONE];
	}

	size--;

	// Reduce capacity when appropriate
	if (capacity > FIVE && size <= capacity / FOUR)
	{
		int newCapacity = capacity / TWO;

		if (newCapacity < FIVE)
		{
			newCapacity = FIVE;
		}

		setCapacity(newCapacity);
	}
	//cout << "\n\t\tValue " << valueToRemove << " has been deleted from MyBag.\n";

	return true;
}

// Precondition: None
// Postcondition: Sorts the elements in the bag in ascending order.
void MyBag::sort()
{
	std::sort(data, data + size); 
}

// Overloaded output operator
// Precondition: None
// Postcondition: Outputs the contents of the MyBag object to the provided ostream.
std::ostream& operator<<(std::ostream& out, const MyBag& bag)
{
	const int ONE = 1;
	if (bag.size == 0)
	{
		out << "MyBag is empty.";
	}
	else
	{
		out << "Mybag contains these sorted integers:\n";

		for (int i = 0; i < bag.size; i++)
		{
			out << "\t\t[" << i << "] - " << bag.data[i];

			if (i < bag.size - ONE)
			{
				out << "\n";
			}
		}
	}

	return out;
}


