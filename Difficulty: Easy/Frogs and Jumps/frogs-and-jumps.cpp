//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        bool visited[leaves + 1] = {false};

    // Sort frogs by their jump strength to process smaller jumps first
    // Ensures that we process frogs with smaller jumps, marking those leaves early
    for (int i = 0; i < N; ++i) {
        int jump = frogs[i];

        // If the frog's jump strength is less than or equal to the number of leaves
        if (jump <= leaves) {
            // If the first leaf in this frog's jump sequence is already visited, we skip it
            if (!visited[jump]) {
                // Mark all multiples of 'jump' as visited
                for (int j = jump; j <= leaves; j += jump) {
                    visited[j] = true;
                }
            }
        }
    }

    // Count the number of unvisited leaves
    int unvisitedCount = 0;
    for (int i = 1; i <= leaves; ++i) {
        if (!visited[i]) {
            ++unvisitedCount;
        }
    }

    return unvisitedCount;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends