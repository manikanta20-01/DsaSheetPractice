//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
        // code here
        unordered_map<int, int> frequency;
        int duplicate = -1;
        int missing = -1;
        
        for(int i = 0;i < arr.size();i++)
        {
            frequency[arr[i]]++;
            
        }
        for(int i = 1;i <= arr.size();i++)
        {
            if(frequency[i] > 1){
                duplicate = i;
            }
            else if(frequency[i] == 0){
                missing = i;
            }
        }
        return {duplicate,missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends