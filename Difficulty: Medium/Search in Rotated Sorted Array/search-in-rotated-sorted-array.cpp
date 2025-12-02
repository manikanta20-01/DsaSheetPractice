class Solution {
  public:
    int search(vector<int>& arr, int target) {
        // Code Here
        int n = arr.size();
        int start = 0, end = n - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == target) return mid;
            
            // check if left is sorted
            
            if(arr[mid] >= arr[start]){
                if(target >= arr[start] && target < arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            
            // check if right is sorted
            else{
                if(target > arr[mid] && target <= arr[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};