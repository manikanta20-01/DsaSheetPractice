class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for(int i : nums) {
            string s = to_string(i);
            for(char c : s) res.push_back(c-'0');
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna