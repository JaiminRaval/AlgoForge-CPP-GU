#include <iostream>
using namespace std; // this line does the magic

int binarySearchBruteForce(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // Check if mid element is the target
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search left half
        else if (arr[mid] > target)
            right = mid - 1;

        // If target is larger, search right half
        else
            left = mid + 1;
    }
    // Target not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    int result = binarySearchBruteForce(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
