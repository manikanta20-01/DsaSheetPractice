class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
         int count[21] = {0};
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == 5){
                count[5]++;
                continue;
            }
            if(arr[i] == 10){
                if(count[5] > 0){
                    count[5]--;
                    count[10]++;
                }
                else{
                    return false;
                }
                continue;
            }
            if(arr[i] = 20){
                if(count[10] > 0 && count[5] > 0){
                    count[10]--;
                    count[5]--;
                    count[20]++;
                    continue;
                }
                if(count[10] == 0 && count[5] >= 3){
                    count[5]--;
                    count[5]--;
                    count[5]--;
                    count[20]++;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};