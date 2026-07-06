class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int,int>>st;

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
        {
            if(a[1]==b[1])return a[0]>b[0];
            return a[1]<b[1];
        });

        for(auto&v:intervals)
        {
            int l = v[0];
            int r = v[1];

            while(!st.empty() && st.back().first>=l)
            {
                st.pop_back();
            }
            st.push_back({l,r});
        }

        return (int)st.size();
    }
};