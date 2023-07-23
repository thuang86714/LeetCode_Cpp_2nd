// Self implementation of
// the Vector Class in C++

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
class vectorClass {

	// arr is the integer pointer
	// which stores the address of our vector
	int* arr;

	// capacity is the total storage
	// capacity of the vector
	int capacity;

	//count is the number of elements
	// currently present in the vector
	int count;

public:
	vectorClass();
    ~vectorClass();

    void push(int data);
    void push(int data, int index);
    int get(int index);
    void pop();
    int size();
    int getcapacity();
    void print();
};
// Default constructor to initialise
	// an initial capacity of 1 element and
	// allocating storage using dynamic allocation
vectorClass::vectorClass(){
		arr = new int[MAX];
		capacity = MAX;
 		count = 0;
}
	//destructor to deallocate storage allocated by dynamic allocation
	//to prevent memory leak
vectorClass::~vectorClass(){
		delete [] arr;
}

	// Function to add an element at the last
void vectorClass::push(int data){

		// if the number of elements is equal to the
		// capacity, that means we don't have space to
		// accommodate more elements. We need to double the
		// capacity
		if (count == capacity) {
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
		arr[count] = data;
		count++;
}

	// function to add element at any index
void vectorClass::push(int data, int index){

		// if index is equal to capacity then this
		// function is same as push defined above
		if (index == capacity)
			push(data);
		else
			arr[index] = data;
}

	// function to extract element at any index
int vectorClass::get(int index){

		// if index is within the range
		if (index < count)
			return arr[index];
}

	// function to delete last element
void vectorClass::pop() {count--; }

	// function to get size of the vector
int vectorClass::size() { return count; }

	// function to get capacity of the vector
int vectorClass::getcapacity() { return capacity; }

	// function to print array elements
void vectorClass::print(){
	for (int i = 0; i ; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Driver code
int main()
{
	vectorClass<int> v;
	vectorClass<char> v1;
	v.push(10);
	v.push(20);
	v.push(30);
	v.push(40);
	v.push(50);
	v1.push(71);
	v1.push(72);
	v1.push(73);
	v1.push(74);

	cout << "Vector size : " << v.size() << endl;
	cout << "Vector capacity : " << v.getcapacity() << endl;

	cout << "Vector elements : ";
	v.print();

	v.push(100, 1);

	cout << "\nAfter updating 1st index" << endl;

	cout << "Vector elements of type int : " << endl;
	v.print();
	// This was possible because we used templates
	cout << "Vector elements of type char : " << endl;
	v1.print();
	cout << "Element at 1st index of type int: " << v.get(1)
		<< endl;
	cout << "Element at 1st index of type char: "
		<< v1.get(1) << endl;

	v.pop();
	v1.pop();

	cout << "\nAfter deleting last element" << endl;

	cout << "Vector size of type int: " << v.size() << endl;
	cout << "Vector size of type char: " << v1.size()
		<< endl;
	cout << "Vector capacity of type int : "
		<< v.getcapacity() << endl;
	cout << "Vector capacity of type char : "
		<< v1.getcapacity() << endl;

	cout << "Vector elements of type int: ";
	v.print();
	cout << "Vector elements of type char: ";
	v1.print();

	return 0;
}
