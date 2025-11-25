class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int start = 0, end = n - 1;
        int maxi = n;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(mid <= target){
                maxi = max(maxi, arr[mid]);
            }
            if(arr[mid] >= target){
                maxi = mid; 
                end = mid - 1;
                
            }
            else{
                start = mid + 1;
            }
        }
      
    }
};
