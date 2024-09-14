//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> posi;
        vector<int> negi;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) {
                negi.push_back(arr[i]);
            } else {
                posi.push_back(arr[i]);
            }
        }
        int i = 0,j = 0,k = 0;
        
        while(i < posi.size() and j < negi.size())
        {
            arr[k++] = posi[i++];
            arr[k++] = negi[j++];
            
            
        }
        while(i < posi.size())
        {
            arr[k++] = posi[i++];
        }
        while(j < negi.size())
        {
            arr[k++] = negi[j++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends