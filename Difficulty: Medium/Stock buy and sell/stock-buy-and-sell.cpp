class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0,j = 1;
        int profit = 0;
        while(j < n)
        {
            if(arr[j] > arr[i])
            {
                profit = profit + (arr[j]- arr[i]);
            }
            i++;
            j++;
        }
        return profit;
        
    }
};