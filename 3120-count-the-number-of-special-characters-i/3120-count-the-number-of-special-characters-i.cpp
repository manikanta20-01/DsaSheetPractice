class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> upper;
        for (char c : word) {
            if (islower(c)) {
                lower.insert(c);
            } else {
                upper.insert(tolower(c));
            }
        }
        int ans = 0;
        for (char c : lower) {
            if (upper.count(c)) {
                ans++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna