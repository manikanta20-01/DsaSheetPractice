class Solution {
  public:
    int single(vector<int>& arr) {
        
        int n = arr.size();
        int start = 0, end = n - 1;
        
        while(start < end){
            int mid = start + (end - start) / 2;
            
            if(mid % 2 == 1){
                mid--;
            }
            
            if(arr[mid] == arr[mid + 1]){
                start = mid + 2;
            }
            else{
                end = mid;
            }
        }
        return arr[start];
    }
};