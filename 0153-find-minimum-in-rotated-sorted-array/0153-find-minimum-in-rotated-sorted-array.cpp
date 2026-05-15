class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1;
        int maxi = 0;

        while(arr[start] <= arr[end]) return arr[start];

        while(start < end){
            int mid = start + (end - start) / 2;

            if(arr[mid] > arr[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        } 
        return arr[start];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna