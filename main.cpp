// sam205 - vector basics and basic <algorithm> functions   Jan 2025
//
// https://en.cppreference.com/w/cpp/container/vector

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  A vector is a C++ Container that stores a list of elements (using an underlying array)
 *  A vector has two important features:
 *   1. vector can GROW as new elements are added to it.
 *   2. vector elements can be ACCESSED BY INDEX, so fast access [ O(1) ] is possible using the index.
 *     (indexing is possible because a vector uses an internal array to store elements)
 *
 * This sample shows:
 * - accessing the elements using: vector.at(index) OR vector[index]
 * - iterating through the elements with for loops
 * - passing a vector into a function by reference (using a reference parameter)
 *   (vectors can be passed by value, but that is inefficient)
 * - using selected functions from the Algorithms Library <algorithm> to process vector elements
 *    functions:  count, count_if
 *                use of lambdas, use of predicates
 */

// function prototype
void display(const vector<int> &);  // parameter type is a "reference to a constant vector of int" (pass-by-reference)
// the "const" means that the parameter references a constant vector - meaning that,
// the reference can not be used to modify the contents of the vector.


int main()
{
    cout << "sam205 - vector basics" << endl;

    // Create a vector called "ages_vector" to store the ages of students in a class.
    // The "ages_vector" is an object that is of type 'vector of ints'

	vector<int> ages_vector;  // declare an object that is a vector of int - initially empty

    // add elements to end of the vector
	ages_vector.push_back(18);
	ages_vector.push_back(17);
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    ages_vector.push_back(21);

    cout << "The ages_vector contains elements:";
    for (int& age : ages_vector) {      // 'age' is a reference to an int, and is used to reference
       cout << age << ", ";             //       each element of the vector in sequence.
    }
    cout << endl; // end of line

    // alternatively
    cout << "The ages_vector contains elements:";
    for (size_t i=0; i<ages_vector.size(); ++i) {      // the size_t type is often used to declare an index.
        cout << ages_vector.at(i) << ", ";          // It is a type that can hold an int value that is big enough
    }                                                   // to access the maximum possible index of a vector.
    cout << endl; // end of line

    // We can access vector elements using an INDEX (two ways are possible)
    // 1. access elements by index using at() - vector.at(index)
    cout << "Element at index position 3 : ages_vector.at(3) = " << ages_vector.at(3) << endl;

    // using .at(index) will throw an "out_of_range" exception if array index
    // is out of bounds and the program terminates.
    // Uncomment the line below to test.
//     cout << "Element at index position 99 is = " << ages_vector.at(99) << endl;

    // 2. access vector elements using array notation "vector[index]"
    cout << "Element at index position 3 : ages_vector[3] = " << ages_vector[3] << endl;

    // array notation "ages_vector[index]" will NOT throw an error if the array
    // index is out of bounds, and will return an unreliable result (here, zero is returned)
    // So, it is usually safer to use the .at(index) function.
    // Uncomment the following line to see the that no exception is thrown even though index is too large.
    cout << "Element at index position 999 is = " << ages_vector[999] << " ERROR - Unreliable Value Returned!" <<endl;

    int& front = ages_vector.front();   // returns reference to the front element
    int& back = ages_vector.back();     // returns reference to the back element (last added)
    cout << "Front = " << front << ", Back = " << back << endl;

    // We could also use the following code.
    // int front = ages_vector.front();
    // front() accesses the first element and returns/evaluates to
    // a reference to the first element. This reference to the first element is then used to assign
    // a COPY of the element into the int variable front.  However, this is often less efficient.

    // a vector can be assigned to another vector replacing
    // all the elements in the target vector.
    vector<int> ages_vector_copy = ages_vector;  // assignment operator copies whole vector ( O(N) )
    cout << "Contents of copied vector ages_vectorCopy:";
    display(ages_vector_copy);

    cout << "Adding two more values to ages_vector..." << endl;
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    cout << "Contents of ages_vector is now : " ;
    display(ages_vector);   // pass a vector into a function (by reference)

    // the contents of two vectors can be swapped using vector.swap() - a potentially expensive operation

    cout << "Program finished - goodbye." << endl;
}

/**
 * Display the elements from a vector of integers.
 * @param vect is a reference to a 'constant vector of int'
 * - a reference is an alias - another name for the vector 'ages_vector' in this case.
 */
void display(const vector<int>& vect)
{
    for (int i=0; i < vect.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << vect.at(i);
    }
    cout << endl;
}
