//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int ans = 1;
        
        for(int i = 0;i < arr.size() - 1;i++)
        {
            if(arr[i] + 1 != arr[i + 1]){
                ans++;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.numOfSubset(nums)
             << endl; // Corrected the function name and argument
    }
    return 0;
}

// } Driver Code Ends