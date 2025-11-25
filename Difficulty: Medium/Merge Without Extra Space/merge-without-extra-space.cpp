class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size(), n = b.size();
        int i = m - 1, j = 0;
        
        while(i >= 0 && j < n && a[i] > b[j]){
            swap(a[i], b[j]);
            i--;j++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
    }
};