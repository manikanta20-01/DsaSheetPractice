class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        
        int val = 0;
        int maxi = 0;
        
        for(int i = prices.size() - 1;i >= 0;i--) {
            val = max(val, prices[i]);
            maxi = max(maxi, val - prices[i]);
        }
        return maxi;
    }
};
