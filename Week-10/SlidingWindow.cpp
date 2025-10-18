#include <algorithm> // For std::min
#include <iostream>  // For std::cout
#include <vector>    // For std::vector
#include <limits>    // For std::numeric_limits

// Finds the minimum length of a contiguous subarray whose sum is >= target.
// Returns 0 if no such subarray exists.
int minSubArrayLen(int target, const std::vector<int>& nums) {
    int minLength = std::numeric_limits<int>::max(); // Initialize with maximum possible int value
    int currentSum = 0;                               // Sum of elements in the current window
    int windowStart = 0;                              // Left boundary of the window

    // Iterate with 'windowEnd' as the right boundary
    for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
        currentSum += nums[windowEnd]; // Expand window, add current element

        // Contract window from the left as long as the sum meets the target
        while (currentSum >= target) {
            minLength = std::min(minLength, windowEnd - windowStart + 1); // Update minimum length
            currentSum -= nums[windowStart];                              // Shrink window
            windowStart++;                                                // Move left boundary
        }
    }
    // Return 0 if no valid subarray was found, otherwise return the minLength
    return (minLength == std::numeric_limits<int>::max()) ? 0 : minLength;
}

// Helper function to run and print test cases
void testCase(const std::vector<int>& nums, int target) {
    std::cout << "Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\nTarget: " << target << std::endl;

    int result = minSubArrayLen(target, nums);
    std::cout << "Minimum subarray length: " << result << std::endl;
    std::cout << "--------------------\n";
}

int main() {
    testCase({2, 3, 1, 2, 4, 3}, 7);
    testCase({1, 4, 4}, 4);
    testCase({1, 1, 1, 1, 1}, 10);
    testCase({10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 18, 1}, 50);
    testCase({1, 2, 3, 4, 5}, 15); // Edge case: sum of all elements

    return 0;
}
