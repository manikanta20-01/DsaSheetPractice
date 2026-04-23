class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<long long>ans(n);
        unordered_map<int,vector<long long>>mpp;
        for(int i=0;i<n;++i)mpp[nums[i]].push_back(i);

        for(auto&it:mpp)
        {
            int ele = it.first;
            vector<long long>&v = it.second;
            int nn = v.size();
            if(nn==1)
            {
                ans[v[0]] = 0;
                continue;
            }
            vector<long long>suff(nn+1);
            for(int i=nn-1;i>=0;--i)
            {
                suff[i] = suff[i+1]+v[i];
            }
            
            long long pre = 0;
            for(int i=0;i<nn;i++)
            {
                ans[v[i]] = i*v[i]-pre;
                ans[v[i]] += max(0LL,suff[i+1]-(nn-i-1)*v[i]);
                pre += v[i];
            }
        }
        return ans;
    }
};