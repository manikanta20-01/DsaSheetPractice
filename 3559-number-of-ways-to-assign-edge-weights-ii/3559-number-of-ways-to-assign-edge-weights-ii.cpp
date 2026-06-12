class Solution {
public:
    vector<int> depth;
    vector<vector<int>> up;
    int logN;
    unordered_map<int,vector<int>> adj;
    int mod = 1e9+7;
    int power(int a,int b){
        if(b==0){
            return 1;
        }
        long long half = power(a,b/2)%mod;
        if(b%2){
            return ((half%mod)*(half%mod)*(a%mod))%mod;
        }
        return ((half%mod)*(half%mod))%mod;
    }
    void dfs(int s,int p){
        depth[s] = depth[p]+1;
        up[s][0] = p;
        for(int i = 1;i<logN;i++){
            up[s][i] = up[up[s][i-1]][i-1];
        }
        for(auto e:adj[s]){
            if(e!=p){
                dfs(e,s);
            }
        }
    }
    int lca(int u,int v){
        if(depth[u]<depth[v]){
            swap(u,v);
        }
        int diff = depth[u]-depth[v];
        for(int i = 0;i<logN;i++){
            if((1<<i)&diff){
                u = up[u][i];
            }
        }
        if(u==v){
            return u;
        }
        for(int i = logN-1;i>=0;i--){
            if(up[u][i]!=up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int n = adj.size();
        logN = ceil(log2(n));
        depth.resize(n+1);
        up.resize(n+1,vector<int>(logN));
        dfs(1,1);
        for(auto e:queries){
            int u = e[0];
            int v = e[1];
            int dist = depth[u]+depth[v]-2*(depth[lca(u,v)]);
            int res = (u==v)?0:power(2,dist-1);
            ans.push_back(res);
        }
        return ans;
    }
};