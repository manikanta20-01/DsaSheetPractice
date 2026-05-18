class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool> vis(n,false);
        queue<int> Q;
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        Q.push(0);
        int result=0;
        while(Q.size()>0){
            int sz=Q.size();
            while(sz--){
                int indx=Q.front();
                Q.pop();
                if(indx==n-1)
                    return result;
                if(indx+1<n && !vis[indx+1]){
                    Q.push(indx+1);
                    vis[indx+1]=true;
                }
                if(indx-1>=0 && !vis[indx-1]){
                    Q.push(indx-1);
                    vis[indx-1]=true;
                }
                for(auto x:mp[arr[indx]]){
                    if(!vis[x]){
                        Q.push(x);
                        vis[x]=true;
                    }
                }
                mp[arr[indx]].clear();
            }
            result++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna