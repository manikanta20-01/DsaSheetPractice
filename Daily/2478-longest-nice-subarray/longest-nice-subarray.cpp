class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0,bitMask=0;
        int n=nums.size();
        int maxi=0;
        for(int right=0;right<n;right++){
            while((bitMask&nums[right])!=0){
                bitMask-=nums[left];
                left++;
            }
            bitMask+=nums[right];
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};