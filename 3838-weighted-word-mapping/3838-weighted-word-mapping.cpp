class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        unordered_map<char, int> d;
        for (int i = 0; i < 26; i++) {
            d[alpha[i]] = weights[i];
        }
        vector<int> cnt;
        for (string& word : words) {
            int add = 0;
            for (char x : word) {
                add += d[x];
            }
            int res = add % 26;
            cnt.push_back(res);
        }
        string ans = "";
        for (int i : cnt) {
            ans += char(96 + 26 - i);
        }
        return ans;
    }
};