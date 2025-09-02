#include <iostream>
using namespace std; // this line does the magic remember!




// Constant Time O(1), simple return func;
// Step: No loop, no recursion. Doesn't depend on n. So O(1).[23][26]
int getFirstElement(int arr[], int n) {
    return arr[0];
}

// Linear Time: O(n), simple sum func;
// Step: Single loop from 0 to n. Time grows linearly with n. So O(n).[23][26][27]
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}




// Quadratic Time O(n2), simple printing func with nested loops;
// Step: Two nested loops over n. For each i, ALL j. So n*n = O(n^2).[25][26][27]
void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cout << arr[i] << "," << arr[j] << "\n";
}



// Logarithmic Time O(log⁡n), simple binary search which uses divide & conquer technique;
// Step: Each iteration halves the search space. So O(log n).[29][26]
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}



void merge(int arr[], int l, int m, int r) {
    // merge code will come here
}

// O(nlogn), func for Merge Sort;
// Step: Recursively divides array; merge operation is O(n). Total is O(n log n).[26][30]
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r); // merges two halves
    }
}



// Quick Actionable Steps to Identify Big-O:
//  -   Break the algorithm into steps and look for loops and recursion.
//  -   For each loop, identify its dependency on n.
//  -   Nested loops: Multiply their sizes if dependent.
//  -   If the algorithm halves/divides the data at each iteration, suspect log or n log n.
//  -   Ignore constant work and constant multiples.
//  -   Always analyze for the "worst case" unless specified otherwise.
