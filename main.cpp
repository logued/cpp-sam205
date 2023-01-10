// sam205 - vector basics and basic algorithm functions
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
 *
 * This sample shows:
 * - accessing the elements using: vector.at(index) OR vector[index]
 * - iterating through the elements with for loops
 * - passing a vector into a function by reference (using reference parameter)
 * - using the Algorithms Library <algorithm> to process vector
 *    functions:  count, count_if, find, find_if, all_f, none_of
 *    use of lambdas, use of predicates
 */

// function prototype
void display(const vector<int> &);  // parameter is a reference to a vector (pass-by-reference)
// the "const" means that the parameter references a constant vector - meaning that,
// the reference can not be used to modify the contents of the vector.

int main()
{
    // Create a vector called "ages_vector" to store the age students in a class
    // (unlike Java, we don't need to use 'new' in this case.)
    // "ages_vector" is an object that is of type vector.
    cout << "Vector basics" << endl;

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

    // We can access vector elements using an INDEX (two ways are possible)
    // 1. access elements by index using - vector.at(index)
    cout << "Element at index position 3 : ages_vector.at(3) = " << ages_vector.at(3) << endl;

    // using .at(index) will throw an "out_of_range" exception if array index
    // is out of bounds and the program terminates. Uncomment below to test.
    // cout << "Element at index position 99 is = " << ages_vector.at(99) << endl;

    // 2. access vector elements using array notation "vector[index]"
    cout << "Element at index position 3 : ages_vector.at[3] = " << ages_vector[3] << endl;

    // array notation "ages_vector[index]" will NOT throw an error and will return
    // an unreliable result. So, it is usually safer to use the .at(index) function.
    // Uncomment the following line to see the exception thrown.
    // cout << "Element at index position 13 is = " << ages_vector[99] << endl;

    int front = ages_vector.front();   // returns reference to the front element
    int back = ages_vector.back();     // returns reference to the back element (last added)
    cout << "Front = " << front << ", Back = " << back << endl;

    // a vector can be assigned to another vector replacing
    // all the elements in the target vector.
    vector<int> ages_vectorCopy = ages_vector;  // assignment operator copies whole vector
    cout << "Contents of copied vector ages_vectorCopy:";
    display(ages_vectorCopy);

    cout << "Adding two more values to ages_vector..." << endl;
    ages_vector.push_back(21);
    ages_vector.push_back(18);
    cout << "Contents of ages_vector:" ;
    display(ages_vector);

    // the contents of two vectors can be swapped using vector.swap().

    ////// Processing vectors using functions from the Algorithms Library <algorithm> and lambda functions //////

    // use the count() function from <algorithm> library
    // Let's count the number of ages in the vector that are = 18
    int age = 18;

    int num_items = count(ages_vector.cbegin(), ages_vector.cend(), age);  // counts all matches (=18) from beginning to end of vector
    cout << "Count of students aged " << age << " = " << num_items << endl;

    // use the count_if() function from <algorithm> library
    // and a lambda expression to count student ages that are under 18
    int count_under18 = count_if(ages_vector.begin(), ages_vector.end(), [] (int i) { return i < 18; } );
    cout << "Count of students aged under 18 = " << count_under18 << '\n';

    // Using Iterators.

    // std::ranges only available at C++ 20 or above, so,
    // Edit the CMakeLists.txt file to make sure the following is set
    // set(CMAKE_CXX_STANDARD 20)

    // Use case - check that all of the students in the class are older than 16
    // Check the range (begin -> end) using a lambda predicate to check each element
    if (std::ranges::all_of(ages_vector.cbegin(), ages_vector.cend(), [](int i){ return i > 16; }))
        std::cout << "All ages_vector are > 16\n";

    // Use case : check to see that none of the students are under 17
    if (std::ranges::none_of(ages_vector.cbegin(), ages_vector.cend(), [](int i){ return i < 17; }))
        std::cout << "None of the students are under 17\n";

    // auto defines the right type automatically based on return type of find()
    //
    auto result1 = find( begin(ages_vector), end(ages_vector), 17); // call find() to find 17
    // did the iterator run past the end of the range
    (result1 != end(ages_vector))? cout << " found at least one value 17\n" : cout << "NO value 17 in vector " << endl;

    auto is_even = [](int i){ return i%2 == 0; };   // define a lambda function and store in variable

    auto result2 = find_if( begin(ages_vector), end(ages_vector), is_even ); // call find_if() to find elements that satisfy the is_even lambda

    (result2 != end(ages_vector))? cout << " found one value that satisfied the is_even lambda expression \n" : cout << "NO even values found" << endl;

    cout << "Program finished - goodbye." << endl;
}

/**
 * Display the elements in a vector of integers.
 * @param vector_ref is a reference to a 'constant vector of int'
 * - a reference is an alias - another name for the vector 'ages_vector' in this case.
 */
void display(const vector<int>& vector_ref)
{
    for (int i=0; i<vector_ref.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << vector_ref.at(i);
    }
    cout << endl;
}
