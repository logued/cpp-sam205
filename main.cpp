// sam205 - vector basics and basic <algorithm> functions
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
 *   2. vector elements can be ACCESSED BY INDEX, so fast access is possible using the index.
 *     (indexing is possible because a vector uses an internal array to store elements)
 *
 * This sample shows:
 * - accessing the elements using: vector.at(index) OR vector[index]
 * - iterating through the elements with for loops
 * - passing a vector into a function by reference (using reference parameter)
 *   (vectors can be passed by value, but that that is inefficient)
 * - using selected functions from the Algorithms Library <algorithm> to process vector
 *    functions:  count, count_if
 *                  use of lambdas, use of predicates
 */

// function prototype
void display(const vector<int> &);  // parameter type is a "reference to a vector of int" (pass-by-reference)
// the "const" means that the parameter references a constant vector - meaning that,
// the reference can not be used to modify the contents of the vector.

int main()
{
    cout << "sam205 - vector basics" << endl;

    // Create a vector called "ages_vector" to store the ages of students in a class.
    // The "ages_vector" is an object that is of type vector.

	vector<int> ages_vector;  // declare an object that is a vector of int - initially empty

    // add elements at end of the vector
	ages_vector.push_back(18);
	ages_vector.push_back(17);
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    ages_vector.push_back(21);

    cout << "The ages_vector contains elements:";
    for (int age : ages_vector) {      // for each value in the vector
       cout << age << ", ";
    }
    cout << endl; // end of line

    // alternatively
    cout << "The ages_vector contains elements:";
    for (size_t i=0; i<ages_vector.size(); ++i) {      // for each value in the vector
        cout << ages_vector.at(i) << ", ";
    }
    cout << endl; // end of line

    // We can access vector elements using an INDEX (two ways are possible)
    // 1. access elements by index using at() - vector.at(index)
    cout << "Element at index position 3 : ages_vector.at(3) = " << ages_vector.at(3) << endl;

    // using .at(index) will throw an "out_of_range" exception if array index
    // is out of bounds and the program terminates. Uncomment below to test.
//     cout << "Element at index position 99 is = " << ages_vector.at(99) << endl;

    // 2. access vector elements using array notation "vector[index]"
    cout << "Element at index position 3 : ages_vector[3] = " << ages_vector[3] << endl;

    // array notation "ages_vector[index]" will NOT throw an error if the array
    // index is out of bounds, and will return an unreliable result (here, zero is returned)
    // So, it is usually safer to use the .at(index) function.
    // Uncomment the following line to see the that no exception is thrown.
    cout << "Element at index position 999 is = " << ages_vector[999] << " ERROR - Unreliable Value Returned!" <<endl;

    int front = ages_vector.front();   // returns reference to the front element
    int back = ages_vector.back();     // returns reference to the back element (last added)
    cout << "Front = " << front << ", Back = " << back << endl;
    // (note above, the front value is accessed and its value is copied into the variable front.)


    // a vector can be assigned to another vector replacing
    // all the elements in the target vector.
    vector<int> ages_vector_copy = ages_vector;  // assignment operator copies whole vector
    cout << "Contents of copied vector ages_vectorCopy:";
    display(ages_vector_copy);

    cout << "Adding two more values to ages_vector..." << endl;
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    cout << "Contents of ages_vector is now : " ;
    display(ages_vector);

    // the contents of two vectors can be swapped using vector.swap()

    ////// Processing vectors using functions from the                //////
    ////// Algorithms Library <algorithm> and using lambda functions  //////

    // use the count() function from <algorithm> library
    // Let's count the number of ages in the vector that are = 18
    int age = 18;

    int num_items = count(ages_vector.begin(), ages_vector.end(), age);  // counts all matches (=18) from beginning to end of vector
    cout << "Count of students aged " << age << " = " << num_items << endl;

    // begin() returns an iterator that points at the beginning of the vector
    // end() returns an iterator that points at (one past) the last element of the vector


    // use the count_if() function from <algorithm> library
    // and a lambda expression to count student ages that are less than 18
    int count_under18 = count_if(ages_vector.begin(), ages_vector.end(), [] (int i) { return i < 18; } );
    cout << "Count of students aged under 18 = " << count_under18 << '\n';

    // Lambda expression:  "[] (int i) { return i < 18; }"
    // A "lambda" is a type of function that does not have a name.
    // the count_if() function iterates over all elements in the vector, from beginning to end.
    // The function count_if()  applies the "lambda" to each element as it meets them.
    // This lambda applies the "predicate" ("i<18") - to test whether each element (age)
    // is less than 18 or not.  It returns true or false in each case.
    // count_if increments a count for each time "true" is returned, and
    // finally returns the count.

    cout << "Program finished - goodbye." << endl;
}

/**
 * Display the elements from a vector of integers.
 * @param vector_ref is a reference to a 'constant vector of int'
 * - a reference is an alias - another name for the vector 'ages_vector' in this case.
 */
void display(const vector<int>& vector_ref)
{
    for (int i=0; i < vector_ref.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << vector_ref.at(i);
    }
    cout << endl;
}
