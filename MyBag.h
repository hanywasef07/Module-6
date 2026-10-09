#pragma once
#include <iostream>

class MyBag
{
private:
	int* data; // Pointer to the dynamic array that holds the elements of the bag
	int size; // Current number of elements in the bag
	int capacity; // Maximum number of elements the bag can hold before needing to resize
public:
	//constructors
	MyBag();
	MyBag(int capacity);
	MyBag(const MyBag& other);
	//destructor
	~MyBag();
	//getters
	int getSize() const;
	int getCapacity() const;
	//setters
	void setSize(int size);
	void setCapacity(int capacity);

	void clear(); // Clear the bag of all elements
	void insert(int value); // Insert a value into the bag
	int search(int value) const; // Search for a value in the bag and return its index, or -1 if not found
	bool remove(int index); // Remove the element at the specified index and return true if successful, false otherwise
	void sort(); // Sort the elements in the bag in ascending order
	// Overload the << operator to display the contents of the bag
	friend std::ostream& operator<<(std::ostream& out, const MyBag& bag);
};

