#include <iostream> // Required for input/output operations (e.g., cout)
#include <vector>   // Required for using the std::vector container
#include <algorithm> // Required for std::sort

// This function finds a pair of numbers in a sorted array that sum up to a target value
// It uses the two-pointers technique.
// The array MUST be sorted for this technique to work efficiently.
std::vector<int> findPairWithSum(std::vector<int>& nums, int target) {
    // Initialize the left pointer at the beginning of the array.
    int left = 0;
    // Initialize the right pointer at the end of the array.
    int right = nums.size() - 1;

    // Loop as long as the left pointer is less than the right pointer.
    // If left crosses right, it means we have checked all possible unique pairs.
    while (left < right) {
        // Calculate the current sum of the elements pointed to by left and right.
        int currentSum = nums[left] + nums[right];

        // If the current sum equals the target, we found our pair.
        if (currentSum == target) {
            // Return a new vector containing the two numbers.
            return {nums[left], nums[right]};
        }

        // If the current sum is less than the target,
        else if (currentSum < target) {
            left++; // Move left pointer one step to the right
        }

        // If the current sum is greater than the target,
        else { // currentSum > target
            right--; // Move right pointer one step to the left
        }
    }

    // This indicates that no such pair exists in the array.
    return {};
}

void RuntestCase(std::vector<int> nums, int target) {
    std::cout << "Original Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\nTarget: " << target << std::endl;

    std::sort(nums.begin(), nums.end()); // Ensure array is sorted

    std::vector<int> result = findPairWithSum(nums, target);

    if (!result.empty()) {
        std::cout << "Pair found: (" << result[0] << ", " << result[1] << ")" << std::endl;
    } else {
        std::cout << "No pair found." << std::endl;
    }
    std::cout << "--------------------\n";
}

int main() {
    RuntestCase({1, 2, 3, 4, 5, 6, 7}, 9);
    // RuntestCase({10, 20, 30, 40, 50}, 100);
    // RuntestCase({7, 1}, 8);
    // RuntestCase({5, 2, 8, 1, 9}, 10); // Array needs sorting
    // RuntestCase({-1, 0, 1, 2, 3}, 2); // Handles negative numbers

    return 0;
}
