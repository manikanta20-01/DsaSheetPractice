class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long long count = 0;
    int prefXOR = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; 

    for (int val : arr) {
        prefXOR ^= val;
        count += mp[prefXOR ^ k];
        mp[prefXOR]++;
    }
    return count;
    }
};