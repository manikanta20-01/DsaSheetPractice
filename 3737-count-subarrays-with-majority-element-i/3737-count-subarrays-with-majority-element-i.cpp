class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n);

        // Convert the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                arr[i] = 1;
            else
                arr[i] = -1;
        }

        int count = 0;

        // Check every subarray
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum > 0)
                    count++;
            }
        }

        return count;
    }
};