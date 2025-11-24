class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if (n == 0) return 0;
        
        sort(arr.begin(), arr.end());
        
        int count = 1, longest = 1;
        
        for(int i = 1;i < n;i++)
        {
            if(arr[i] == arr[i - 1])
            {
                continue;
            }
            else if(arr[i] == arr[i - 1] + 1)
            {
                count++;
            }
            else{
                count = 1;
            }
            longest = max(count, longest);
        }
        return longest;
    }
};