class Solution {
  public:
    int countStrings(int n) {
        // code here
        int prev_0=1, curr_0=0;
        int prev_1=1, curr_1=1;
        for(int i=2;i<=n;i++) {
            // curr = 1
            curr_1=prev_0;
            
            // curr=0;
            curr_0=prev_0+prev_1;
            
            prev_0=curr_0;
            prev_1=curr_1;
        }
        return prev_0+prev_1;
    }
};