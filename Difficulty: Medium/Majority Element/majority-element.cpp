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
        
            int count = 0;
        int ele = 0;

        // First pass: Find a candidate for majority element
        for (int i = 0; i < arr.size(); i++) {
            if (count == 0) {
                ele = arr[i];
                count = 1;
            } else if (arr[i] == ele) {
                count++;
            } else {
                count--;
            }
        }
        
        // Second pass: Verify the candidate
        int count1 = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == ele) {
                count1++;
            }
        }

        // Check if the candidate is indeed the majority element
        if (count1 > arr.size() / 2) {
            return ele;
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