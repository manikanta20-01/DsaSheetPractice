//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // your code here
        if(arr.size() == 1) return arr[0];
        for(int i = 0;i < arr.size();i++)
        {
            int count = 1;
            int n = arr.size()/2;
            for(int j = 0;j < arr.size();j++)
            {
                if(i == j)continue;
                if(arr[i] == arr[j])count++;
                if(count > n)return arr[i];
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends