class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProduct=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxProduct=max(maxProduct,(nums[i]-1)*(nums[j]-1));
            }
        }
        return maxProduct;
    }
};