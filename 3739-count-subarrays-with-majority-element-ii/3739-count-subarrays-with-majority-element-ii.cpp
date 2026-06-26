class Solution {
public:
    long long mergeSort(vector<int>& pref, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;

        long long ans = mergeSort(pref, l, mid);
        ans += mergeSort(pref, mid + 1, r);

        // Count pairs
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && pref[j] <= pref[i])
                j++;
            ans += (r - j + 1);
        }

        // Merge
        vector<int> temp;
        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {
            if (pref[i] <= pref[j])
                temp.push_back(pref[i++]);
            else
                temp.push_back(pref[j++]);
        }

        while (i <= mid) temp.push_back(pref[i++]);
        while (j <= r) temp.push_back(pref[j++]);

        for (int k = l; k <= r; k++)
            pref[k] = temp[k - l];

        return ans;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> counter;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                counter.push_back(1);
            else
                counter.push_back(-1);
        }

        vector<int> pref(counter.size() + 1, 0);
        for (int i = 0; i < counter.size(); i++) {
            pref[i + 1] = pref[i] + counter[i];
        }

        return mergeSort(pref, 0, pref.size() - 1);
    }
};