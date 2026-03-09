class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
    
    vector<int> last(256, -1);
    for (int i = 0; i < n; i++) {
        last[s[i]] = i;
    }

    for (int i = 0; i < n; i++) {
       
        for (char c = 'z'; c > s[i]; c--) {
            if (last[c] > i) {
                
                swap(s[i], s[last[c]]);
                return s;
            }
        }
    }
    return s; 
    }
};