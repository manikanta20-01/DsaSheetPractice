class Solution {
public:
    int n;
    vector<int>dp;
    int dfs(int i,vector<int>&arr,int d){
        int maxi=1;
        if(dp[i]!=-1) return dp[i];
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[i]<=arr[j]) break;
            maxi=max(maxi,1+dfs(j,arr,d));
        }
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[i]<=arr[j]) break;
            maxi=max(maxi,1+dfs(j,arr,d));
        }
        return dp[i]=maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        this->n=arr.size();
        dp.assign(n,-1);
        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dfs(i,arr,d));
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna