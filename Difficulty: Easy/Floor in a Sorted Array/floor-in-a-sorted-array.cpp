class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int start = 0, end = n - 1, res = -1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(arr[mid] <= x){
                res = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return res;
    }
};
