class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0; int j = 0;
        while(i < nums1.size() and j < nums2.size()) {
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna