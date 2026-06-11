class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+2];
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        int mx=0;
        vector<int> vis(n+2,0);
        vis[1] = 1;
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                auto it = q.front();
                q.pop();
                int node = it.first;
                int level = it.second;
                mx = max(mx,level);
                for(auto x:adj[node]){
                    if(!vis[x]){
                        q.push({x,level+1});
                        vis[x] =1;
                    }
                }
            }
        }
        if(mx==0) return 0;
        int N = 1e9+7;
        long long res = 1;
        for(int i=1;i<mx;i++){
            res = (res*2)%N;
                
        }
        return res;
        
    }
};