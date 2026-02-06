// sam205 - vector basics and basic <algorithm> functions   Feb 2026
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
void display(const vector<int> &);
// parameter type is a "reference to a constant vector of constant int values" (pass-by-reference)
// the "const" means that the parameter references a constant vector - meaning that,
// the reference can not be used to modify the contents of the vector.
// 'const int' means that individual elements can not be modified.

int main()
{
    cout << "sam205 - vector basics" << endl;

    // Create a vector called "ages_vector" to store the ages of students in a class.
    // The "ages_vector" is an object that is of type 'vector of int'

	vector<int> ages_vector;  // declare an object that is a vector of int - initially empty

    // add elements to end of the vector
	ages_vector.push_back(18);
	ages_vector.push_back(17);
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    ages_vector.push_back(21);

    cout << "The ages_vector contains elements:";
    for (const int& age : ages_vector) {      // 'age' is a reference to a constant int, and is used to reference
       cout << age << ", ";                   // each element of the vector in sequence.
    }                                   // 'const' prevents 'age' being used to change values in the vector
    cout << endl; // end of line

    // alternatively
    cout << "The ages_vector contains elements:";
    for (size_t i=0; i<ages_vector.size(); ++i) {   // the size_t type is often used to declare an indexes type.
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
    // Uncomment the following line, and run, to see the that
    // no exception is thrown even though index is out of bounds.
    cout << "Element at index position 999 is = " << ages_vector[999] << " Not good - index of 999 does not cause an exception" <<endl;

    int & frontValue = ages_vector.front();   // returns reference to the element in the first element
    int & backValue = ages_vector.back();     // returns reference to the element at the back (last added)
    cout << "Front = " << frontValue << ", Back = " << backValue << endl;

    // We could also use the following code.
    // int front = ages_vector.front();
    // front() accesses the first element and returns/evaluates to
    // a reference to the first element. This reference to the first element is then used to assign
    // a COPY of the element into the int variable front.  However, this is often less efficient.

    // a vector can be assigned to another vector replacing
    // all the elements in the target vector.
    vector<int> ages_vector_copy = ages_vector;  // assignment operator (=) copies whole vector ( O(N) )
    cout << "Contents of copied vector ages_vectorCopy:";
    display(ages_vector_copy);

    cout << "Adding two more values to ages_vector..." << endl;
    ages_vector.push_back(21); // add at end
    ages_vector.push_back(18);

    cout << "Contents of ages_vector is now : " ;
    display(ages_vector);   // pass a vector into a function (by reference)

    // the contents of two vectors can be swapped using vector.swap() - a potentially expensive operation

    ////// Processing vectors using functions from the                //////
    ////// Algorithms Library <algorithm> and using lambda functions  //////

    // use the count() function from the <algorithm> library
    // Let's count the number of ages in the vector that are = 18
    int age = 18;

    // counts all matches (==18) from beginning to end of vector
    // begin() and end() functions return iterators
    size_t num_items = count(ages_vector.begin(), ages_vector.end(), age);

    cout << "Count of students aged " << age << " = " << num_items << endl;

    // begin() returns an iterator that points at the beginning of the vector
    // end() returns an iterator that points immediately past the last element of the vector

    // use the count_if() function from <algorithm> library
    // and a lambda function expression to count student ages that are less than 18
    size_t count_of_under18s = count_if(ages_vector.begin(),
                                 ages_vector.end(),
                                 [] (int i) { return i < 18; }    // predicate
                                 );
    cout << "Count of students aged under 18 = " << count_of_under18s << '\n';

    // Lambda expression:  "[] (int i) { return i < 18; }"
    // A "lambda" is a type of function that does not have a name.
    // the count_if() function iterates over all elements in the vector, from beginning to end.
    // The function count_if()  applies the "lambda" function to each element as it meets them.
    // Elements are passed into the parameter "i" - one by one, for each lambda call.
    // This lambda applies the "predicate" ("i<18") - to test whether each element (age)
    // is less than 18 or not.  It returns true or false.
    // count_if increments a count for each time "true" is returned, and
    // finally returns the count.

    cout << "Program finished -  goodbye." << endl;
}

/**
 * Display the elements from a vector of integers.
 * @param theVector is a reference to a 'constant vector of int'
 * - a reference is an alias - another name for the vector 'ages_vector' in this case.
 *
 */
void display(const vector<int>& theVector)
{
    for (int i=0; i < theVector.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << theVector.at(i);
    }
    cout << endl;
}
