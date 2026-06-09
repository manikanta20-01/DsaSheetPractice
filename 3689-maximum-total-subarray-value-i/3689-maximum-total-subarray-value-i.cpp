class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1LL * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) * k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna