class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int hi = 0, alt = 0;
        int n = gain.size();
        for(int i = 0;i < n;i++) {
            alt += gain[i];
            hi = max(alt, hi);
        }
        return hi;
    }
};