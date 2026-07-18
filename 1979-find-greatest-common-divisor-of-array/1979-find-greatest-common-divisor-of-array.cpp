class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = 1e9;
        int maxi = -1e9;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        return gcd(maxi,mini);
    }
};