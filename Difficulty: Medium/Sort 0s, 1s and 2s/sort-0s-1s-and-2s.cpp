class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int left = 0, mid = 0,right = n - 1;
        
        while(mid <= right)
        {
            if(arr[mid] == 0)
            {
                swap(arr[mid], arr[left]);
                left++;
                mid++;
            }
            else if(arr[mid] == 1)
            {
                mid++;
            }
            else{
                swap(arr[right], arr[mid]);
                right--;
            }
        }
    }
};