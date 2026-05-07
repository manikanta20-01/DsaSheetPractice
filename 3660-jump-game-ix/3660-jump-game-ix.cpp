#define ll int
#define vl vector<int>
class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        ll n=a.size();
        vl pm(n);
        pm[0]=a[0];
        for(ll i=1;i<n;i++)
        {
            pm[i]=max(pm[i-1],a[i]);
        }
        priority_queue<pair<ll,ll>> q;
        vl ans(n);
        for(ll i=n-1;i>=0;i--)
        {
            ll temp=max(a[i],pm[i]);
            while(!q.empty()&&a[q.top().first]>=temp)
            {
                q.pop();
            }
            if(q.empty())
            {
                ans[i]=pm[i];
                q.push({i,ans[i]});
            }else{
                ans[i]=max({ans[i],pm[i],q.top().second});
                q.push({i,ans[i]});
            }
        }
        return ans;
    }
};