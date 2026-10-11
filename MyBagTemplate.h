#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace MyBagTemplate
{
	template <class T>
	class MyBag
	{
	private:
		T* data;
		int size;
		int capacity;
	public:
        MyBag();
		MyBag(int capacity); // Constructor with capacity
		MyBag(const MyBag<T>& other); // Copy constructor
        MyBag<T>& operator=(const MyBag<T>& other);
        ~MyBag();

        // Getters
        int getSize() const;
        int getCapacity() const;
        T getValue(int index) const;

        // Setters
        void setSize(int size);
        void setCapacity(int capacity);

        // Operations
        void clear();
        void insert(T value);
        int search(T value) const;
        bool remove(int index);
        void sort();

		// friend function to overload the << operator
        friend std::ostream& operator<<(std::ostream& out, const MyBag<T>& bag)
        {
            if (bag.size == 0)
            {
                out << "MyBag is empty.";
            }
            else
            {
                out << "Mybag contains these sorted values:\n";

                for (int i = 0; i < bag.size; i++)
                {
                    out << "\t\t[" << i << "] - " << bag.data[i] << "\n";
                }
            }

            return out;
        }
    };

    // Default constructor
	// Precondition: None
	// Postcondition: Initializes size to 0, capacity to 5, and allocates memory for the data array
    template <class T>
    MyBag<T>::MyBag()
    {
        size = 0;
        capacity = 5;
        data = new T[capacity];
    }

    // Constructor with capacity
	// Precondition: capacity is a positive integer
	// Postcondition: Initializes size to 0, sets capacity to the specified value (or 5 if invalid), and allocates memory for the data array
    template <class T>
    MyBag<T>::MyBag(int capacity)
    {
        size = 0;

        if (capacity <= 0)
        {
            capacity = 5;
        }

        this->capacity = capacity;
        data = new T[this->capacity];
    }

    // Copy constructor
	// Precondition: other is a valid MyBag object
	// Postcondition: Creates a new MyBag object that is a copy of the other MyBag object
    template <class T>
    MyBag<T>::MyBag(const MyBag<T>& other)
    {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (int i = 0; i < size && i < capacity; i++)
        {
            data[i] = other.data[i];
        }
    }

	// Destructor
	// Precondition: None
	// Postcondition: Deallocates memory for the data array
    template <class T>
    MyBag<T>::~MyBag()
    {
        delete[] data;
	}

	// Getters
	// Precondition: None
	// Postcondition: Returns the current size of the MyBag object
    template <class T>
    int MyBag<T>::getSize() const
    {
        return size;
    }
	// Precondition: None
	// Postcondition: Returns the current capacity of the MyBag object
    template <class T>
    int MyBag<T>::getCapacity() const
    {
        return capacity;
	}
	// Get value at a specific index
	// Precondition: index is a valid subscript
	// Postcondition: Returns the value at the specified index in the MyBag object
    template <class T>
    T MyBag<T>::getValue(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
	}

	// Setters
	// Precondition: size must be a non-negative integer
	// Postcondition: Sets the size of the MyBag object to the specified value, ensuring it does not exceed capacity
    template <class T>
    void MyBag<T>::setSize(int size)
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

	// Precondition: capacity must be a positive integer
	// Postcondition: Sets the capacity of the MyBag object to the specified value, reallocating memory for the data array if necessary
    template <class T>
    void MyBag<T>::setCapacity(int capacity)
    {
        if (capacity < size)
        {
            capacity = size;
        }

        if (capacity <= 0)
        {
            capacity = 1;
        }

        T* temp = new T[capacity];

        for (int i = 0; i < size && i < capacity; i++)
        {
            temp[i] = data[i];
        }

        delete[] data;

        data = temp;
        this->capacity = capacity;
    }

	// Clear the bag of all elements
	// Precondition: None
	// Postcondition: Resets the size of the MyBag object to 0, effectively clearing it of all elements
	template <class T>
    void MyBag<T>::clear()
    {
        size = 0; // reset size to 0, but keep the capacity and data intact
    }

	// Precondition: None
	// Postcondition: Inserts the value into the bag, resizing if necessary
	template <class T>
    void MyBag<T>::insert(T value)
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
	// Postcondition: Returns the index of the value if found, otherwise -1
	template <class T>
    int MyBag<T>::search(T value) const
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

	// Precondition: index is a valid subscript
	// Postcondition: Removes the element at the specified index and returns true if successful, false otherwise
	template <class T>
    bool MyBag<T>::remove(int index)
    {
        const int ONE = 1, TWO = 2, FOUR = 4, FIVE = 5;

        if (index < 0 || index >= size)
        {
            return false;
        }

        //T valueToRemove = data[index];

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
       // cout << "\n\t\tValue " << valueToRemove << " has been deleted from MyBag.\n";

        return true;
    }

	// Precondition: None
	// Postcondition: Sorts the elements in the bag in ascending order
	template <class T>
    void MyBag<T>::sort()
    {
        std::sort(data, data + size);
    }

    // Copy assignment operator
	// Precondition: other is a valid MyBag object
	// Postcondition: Assigns the contents of the other MyBag object to this MyBag object, resizing if necessary
    template <class T>
    MyBag<T>& MyBag<T>::operator=(const MyBag<T>& other)
    {
        if (this != &other)
        {
            T* temp = new T[other.capacity];

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

}