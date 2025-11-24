class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        
        vector<int> v;
        
        long long ans = 1;
        v.push_back(ans);
        
        for(int i = 1;i < n;i++)
        {
            ans = ans * (n - i);
            ans = ans / (i);
            v.push_back(ans);
        }
        return v;
    }
};
