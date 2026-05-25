class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        set<int> st;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                st.insert(i);
        queue<int> q, temp;
        q.push(0);
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (n + 1 == s.size())
                return true;
            auto it = st.lower_bound(n + minJump);
            while (it != st.end() && (*it) <= n + maxJump) {
                q.push(*it);
                temp.push(*it);
                it++;
            }
            while (!temp.empty()) {
                st.erase(temp.front());
                temp.pop();
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna