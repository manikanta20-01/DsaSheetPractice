#include <vector>
using namespace std;

class Solution {
private:
    int sumOf(const vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        return sum;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = sumOf(nums);
        if ((sum & 1) == 1) return false;
        sum /= 2;
        
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        vector<bool> curr(sum + 1, false);
        curr[0] = true;

        if (nums[0] <= sum) prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= sum; k++) {
                bool dont = prev[k];
                bool pick = (nums[i] <= k) ? prev[k - nums[i]] : false;
                curr[k] = (pick || dont);
            }
            swap(prev, curr);
        }
        return prev[sum];
    }
};