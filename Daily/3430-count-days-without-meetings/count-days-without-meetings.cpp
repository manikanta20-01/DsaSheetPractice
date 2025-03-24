class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>&num) {
        vector<vector<int>>ans;
        sort(num.begin(),num.end());
        int mini=num[0][0],maxi=num[0][1],k=0;
        vector<int>take;
        for(int i=0;i<num.size();i++){
            if(maxi>=num[i][0]){
                if(maxi<=num[i][1]){
                maxi=num[i][1];
                }
            }
            else{
                take.push_back(mini);
                take.push_back(maxi);
                ans.push_back(take);
                take.clear();
                mini=num[i][0];
                maxi=num[i][1];
            }
            if(i==(num.size()-1)){
                take.push_back(mini);
                take.push_back(maxi);
                ans.push_back(take);
                take.clear();
                mini=num[i][0];
                maxi=num[i][1];
            }
        }
        return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        meetings=mergeIntervals(meetings);
       
        for(int i=0;i<meetings.size();i++)
        days=days-(meetings[i][1]-meetings[i][0]+1);
        return days;
    }
};