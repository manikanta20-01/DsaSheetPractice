class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int ele;

        for(int i = 0;i < arr.size();i++)
        {
            if(count == 0)
            {
                count = 1;
                ele = arr[i];
            }
            else if(arr[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
         count = 0;
        for(int i = 0;i < arr.size();i++)
        {
            if(arr[i] == ele){
                count++;
            }
            if(count > arr.size() / 2){
                return ele;
            }
        }
        return -1;
    }
};