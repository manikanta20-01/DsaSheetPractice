class Solution {
  public:
    bool twoSum(vector<int>& nums, int target) {
        // code here
        map<int, int>mpp;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            int num = nums[i];
            int moreNeed = target - num;
            if(mpp.find(moreNeed) != mpp.end())
            {
                return true;
            }
            
            mpp[num] = i;
        }
        return false;
    }
};