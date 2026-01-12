class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        vector<int>finalans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i],i});
            if(i>=k-1)
            {
                while(!pq.empty() && pq.top().second<=i-k)
                pq.pop();
                finalans.push_back(pq.top().first);
            }
            
        }
        return finalans;
    }
};