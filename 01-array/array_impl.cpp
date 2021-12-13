/**
 * C++ example to demonstrate Array data structure
 */
#include <iostream>
using namespace std;

// Mmaximum capacity
#define CAPACITY 10

/**
 * Array implementation
 */
class Array
{
    // Array data
    int array[CAPACITY];
    
    // Size of the array
    int size;
    
public:
    // Constructor
    Array() : size(0) {}
    
    // Insert an element into the given position
    void insertAt(int element, int pos);
    
    // Delete an element by the given position
    void deleteAt(int pos);
    
    // Search the given element and return the position
    int search(int element);
    
    // Access the element at given position
    int get(int pos);
    
    // Print the array elements
    void print(const std::string& msg);
};

void Array::insertAt(int element, int pos)
{
    // Step 1. Check if the Array is full. If true, return error.
    if (size >= CAPACITY) {
        throw std::runtime_error("array capacity reached");
    }
    
    // Step 2. Check if the given position is out of data range. If true, return error.
    // Allow to insert at the end of array anyway.
    if (pos < 0 || pos > size) {
        throw std::runtime_error("position out of insertion range");
    }
    
    // Step 3. Free up the space for the new element by shifting the elements to next position.
    for (int i=size ; i > pos ; --i) {
        array[i] = array[i-1];
    }
    
    // Step 4. Insert the new element at the given position
    array[pos] = element;
    
    // Step 5. Increment the size by 1
    ++size;
}

void Array::deleteAt(int pos)
{
    // Step 1. Check if the given position is out of data range. If true, return error.
    if (pos < 0 || pos >= size) {
        throw std::runtime_error("position out of data range");
    }
    
    // Step 2. Delete the element by shifting the elements to previous position.
    for (int i=pos; i < (size-1); ++i) {
        array[i] = array[i+1];
    }
    
    // Step 3. Decrement the size by 1
    --size;
}

int Array::search(int element)
{
    // Step 1. Traverse the array from the first position
    for (int i=0; i < size; i++) {
        // Step 2. Check if the element exists in the position. If true, return the position.
        if (array[i] == element) {
            return i;
        }
    }
    // Step 4. If the element is not found after the traversal, return -1
    return -1;
}

int Array::get(int pos)
{
    // Step 1. Check if the given position is out of array range. If true, return error.
    if (pos < 0 || pos >= size) {
        throw std::runtime_error("position out of data range");
    }
    
    // Step 2. Return the element at the given position
    return array[pos];
}

void Array::print(const std::string& msg)
{
    cout << msg << endl;
    cout << "[";
    for (int i=0; i < size; i++) {
        cout << "  " << array[i];
    }
    cout << "  ]" << endl;
}

int main()
{
    // Creating an Array
    Array arr;
    
    // Insert elements
    arr.insertAt(0, 0);
    arr.print("Array after insertAt(0, 0)");
    //==> [ 0 ]
    
    arr.insertAt(10, 1);
    arr.print("Array after insertAt(10, 1)");
    //==> [ 0, 10 ]
    
    arr.insertAt(20, 2);
    arr.print("Array after insertAt(20, 2)");
    //==> [ 0, 10, 20 ]
    
    arr.insertAt(5, 1);
    arr.print("Array after insertAt(5, 1)");
    //==> [ 0, 5, 10, 20 ]
    
    arr.insertAt(15, 3);
    arr.print("Array after insertAt(15, 3)");
    //==> [ 0, 5, 10, 15, 20 ]
    
    cout << "Access element at index 3 = " << arr.get(3) << endl;
    
    cout << "Searching element 5 found at index = " << arr.search(5) << endl;
    
    // Delete elements
    arr.deleteAt(1);
    arr.print("Array after deleteAt(1)");
    //==> [ 0, 10, 15, 20 ]
    
    arr.deleteAt(2);
    arr.print("Array after deleteAt(2)");
    //==> [ 0, 10, 20 ]
    
    return 0;
}
