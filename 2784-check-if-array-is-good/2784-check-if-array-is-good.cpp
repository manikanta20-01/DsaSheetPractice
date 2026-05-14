class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int mx = nums[n - 1];

        if (n != mx + 1)
            return false;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] != i + 1)
                return false;
        }

        return nums[n - 1] == mx;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna