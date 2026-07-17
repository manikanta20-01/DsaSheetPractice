class Solution {

public:
    typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        ll n=nums.size();
        ll vals=*max_element(nums.begin(),nums.end());
        vector<ll>freq(vals+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<ll>multiples(vals+1,0);
        
        for(int i=1;i<=vals;i++){
            for(int j=i;j<=vals;j+=i){
                multiples[i]+=freq[j];
            }
        }
        for(int i=1;i<=vals;i++){
            ll x=multiples[i];
            multiples[i]=(x*(x-1)*1ll)/2;
        }
        for(int i=vals;i>=1;i--){
            for(int j=2*i;j<=vals;j+=i){
                multiples[i]-=multiples[j];
            }
        }
        vector<ll>pref(vals+1,0);
        for(int i=1;i<=vals;i++){
            pref[i]=pref[i-1]+multiples[i];
            cout<<pref[i]<<endl;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ll q=queries[i]+1;
            auto it=lower_bound(pref.begin(),pref.end(),q);
            ll dis=it-pref.begin();
            
            ans.push_back(dis);
        }
        return ans;

    }
};