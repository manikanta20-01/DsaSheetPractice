//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  void prefixHelp(const vector<int> &arr, int n, int index, int sum, vector<int> &ans) {
    if (index == n) {
        return;  
    }
    
    sum += arr[index];
    
    int avg = sum / (index + 1);
    
    ans.push_back(avg);
    
    prefixHelp(arr, n, index + 1, sum, ans);
}
  
  vector<int> prefixAvg(const vector<int> &arr) {
    vector<int> result;
    int n = arr.size();
    
    prefixHelp(arr, n, 0, 0, result);
    
    return result;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.prefixAvg(arr);

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends