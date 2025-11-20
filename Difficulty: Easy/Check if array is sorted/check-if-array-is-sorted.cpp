class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        
        bool check = true;
        
        for(int i = 0;i < arr.size() - 1;i++){
            if(arr[i + 1] < arr[i]){
                check = false;
            };
        };
        return check;
        
    }
};