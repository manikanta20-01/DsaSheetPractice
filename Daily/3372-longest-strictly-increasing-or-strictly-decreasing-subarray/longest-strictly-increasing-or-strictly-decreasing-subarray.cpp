#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        // Edge case: Single element array
        if (nums.size() == 1) {
            return 1;
        }

        int max_len = 1; // To store the maximum length of any valid subarray
        int inc_len = 1; // Length of the current strictly increasing subarray
        int dec_len = 1; // Length of the current strictly decreasing subarray

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) { // Strictly increasing
                inc_len += 1;
                dec_len = 1; // Reset decreasing length
            } else if (nums[i] < nums[i - 1]) { // Strictly decreasing
                dec_len += 1;
                inc_len = 1; // Reset increasing length
            } else { // Equal elements
                inc_len = 1;
                dec_len = 1;
            }

            // Update the maximum length
            max_len = std::max(max_len, std::max(inc_len, dec_len));
        }

        return max_len;
    }
};