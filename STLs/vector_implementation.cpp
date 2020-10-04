// Self implementation of
// the Vector Class in C++

#include <bits/stdc++.h>
using namespace std;

class vectorClass {

	// arr is the integer pointer
	// which stores the address of our vector
	int* arr;

	// capacity is the total storage
	// capacity of the vector
	int capacity;

	// current is the number of elements
	// currently present in the vector
	int current;

public:
	// Default constructor to initialise
	// an initial capacity of 1 element and
	// allocating storage using dynamic allocation
	vectorClass()
	{
		arr = new int[1];
		capacity = 1;
		current = 0;
	}

	// Function to add an element at the last
	void push(int data)
	{

		// if the number of elements is equal to the capacity,
		// that means we don't have space
		// to accommodate more elements.
		// We need to double the capacity
		if (current == capacity) {
			int* temp = new int[2 * capacity];

			// copying old array elements to new array
			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			// deleting previous array
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}

		// Inserting data
		arr[current] = data;
		current++;
	}

	// function to add element at any index
	void push(int data, int index)
	{

		// if index is equal to capacity then this
		// function is same as push defined above
		if (index == capacity)
			push(data);
		else
			arr[index] = data;
	}

	// function to extract element at any index
	int get(int index)
	{

		// if index is within the range
		if (index < current)
			return arr[index];
	}

	// function to delete last element
	void pop()
	{
		current--;
	}

	// function to get size of the vector
	int size()
	{
		return current;
	}

	// function to get capacity of the vector
	int getcapacity()
	{
		return capacity;
	}

	// function to print array elements
	void print()
	{
		for (int i = 0; i < current; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

// Driver code
int main()
{
	vectorClass v;
	v.push(100);
	v.push(200);
	v.push(300);
	v.push(400);
	v.push(500);

	cout << "Vector size : "
		<< v.size() << endl;
	cout << "Vector capacity : "
		<< v.getcapacity() << endl;

	cout << "Vector elements : ";
	v.print();

	v.push(1000, 1);

	cout << "\nAfter updating 1st index"
		<< endl;

	cout << "Vector elements : ";
	v.print();

	cout << "Element at 1st index : "
		<< v.get(1) << endl;

	v.pop();

	cout << "\nAfter deleting last element"
		<< endl;

	cout << "Vector size : "
		<< v.size() << endl;
	cout << "Vector capacity : "
		<< v.getcapacity() << endl;

	cout << "Vector elements : ";
	v.print();

	return 0;
}
