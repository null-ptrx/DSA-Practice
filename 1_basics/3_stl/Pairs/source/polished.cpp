#include <iostream>
#include <string>
#include <utility> // Required for std::pair

using namespace std;

int main() {
    // Initializing a pair: (int, string)
    // A pair stores two heterogeneous objects as a single unit
    pair<int, string> student(1, "Dharmveer");

    // Accessing elements using .first and .second
    cout << "ID: " << student.first << ", Name: " << student.second << endl;

    // Creating a pair using make_pair
    pair<string, double> product;
    product = make_pair("Gaming Mouse", 45.99);

    // Initializing with curly braces (C++11 and later)
    pair<int, int> coordinates = {10, 20};

    // Pairs can be compared (useful for sorting algorithms)
    // They are compared lexicographically: first by 'first', then by 'second'
    pair<int, int> p1 = {1, 10};
    pair<int, int> p2 = {1, 20};

    if (p1 < p2) {
        cout << "p1 is less than p2 because 10 < 20" << endl;
    }

    // Array of pairs: Very useful for graphs (storing edges and weights)
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
    cout << "First element of array: " << arr[0].first << ", " << arr[0].second << endl;

    return 0;
}