class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();

        // Edge case: If k == n, return the max element
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }
       
        // Count occurrences in every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j < k; j++) {
                freq[nums[i + j]]++;
            }
        }

        // Find the largest number appearing exactly once
        int res = -1;
        for (auto& it : freq) {
            if (it.second == 1) {
                res = max(res, it.first);
            }
        }

        return res;
    }
};