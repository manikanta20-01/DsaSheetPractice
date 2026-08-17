class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> p(n+1,0);
        for(int i=0;i<n;i++) p[i+1]=p[i]+stoneValue[i];
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    int l=p[k+1]-p[i],r=p[j+1]-p[k+1];
                    if(l<r) dp[i][j]=max(dp[i][j],l+dp[i][k]);
                    else if(r<l) dp[i][j]=max(dp[i][j],r+dp[k+1][j]);
                    else dp[i][j]=max(dp[i][j],l+max(dp[i][k],dp[k+1][j]));
                }
            }
        }
        return dp[0][n-1];
    }
};