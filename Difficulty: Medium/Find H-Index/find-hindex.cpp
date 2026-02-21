class Solution {
  public:
    int hIndex(vector<int>& ans) {
        // code here
        sort(ans.rbegin(),ans.rend());
        
       int n=ans.size();
       int i=1;
       for(i=1;i<=n;i++){
           if(ans[i-1]>=i)continue;
           break;
       }
       return i-1;
    }
};