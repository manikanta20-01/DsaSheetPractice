class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        set<int>st;
        for(auto &e: nums){
            if(e < k) return -1;
            else if(e != k)st.insert(e);

        }
        return st.size();
    }
};