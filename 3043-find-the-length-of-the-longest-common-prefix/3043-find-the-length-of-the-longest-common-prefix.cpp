class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            string s = to_string(num);
            string temp = "";

            for (char ch : s) {
                temp += ch;
                prefixes.insert(temp);
            }
        }

        int ans = 0;

        // Check prefixes in arr2
        for (int num : arr2) {
            string s = to_string(num);
            string temp = "";

            for (char ch : s) {
                temp += ch;

                if (prefixes.find(temp) != prefixes.end()) {
                    ans = max(ans, (int)temp.size());
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna