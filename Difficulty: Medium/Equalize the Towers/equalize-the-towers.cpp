class Solution {
  public:
  
  long long getCost(int H,vector<int>& heights,vector<int>& cost){
        long long total=0;
        
        for(int i=0;i<heights.size();i++){
            total+=1LL*abs(heights[i]-H)*cost[i];
        }
        
        return total;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int low=INT_MAX;
        int high=INT_MIN;
        int n=heights.size();
        
        for(int i=0;i<n;i++){
            low=min(low,heights[i]);
            high=max(high,heights[i]);
        }
    
        
        while(low<high){
            
            int mid=low+(high-low)/2;
            
            long long cost1=getCost(mid,heights,cost);
            long long cost2=getCost(mid+1,heights,cost);
            
            if(cost1<=cost2){
                high=mid;
            } 
            else{
                low=mid+1;
            }
        }
        
        return getCost(low, heights, cost);
    }
};
