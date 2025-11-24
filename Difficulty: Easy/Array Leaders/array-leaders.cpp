

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> res;
        res.push_back(arr[n - 1]);
        
        for(int i = n - 2;i >= 0;i--)
        {
            if(arr[i] >= res.back())
            {
                res.push_back(arr[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};