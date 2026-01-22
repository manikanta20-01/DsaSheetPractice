class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long maxSum = 0, minSum = 0;
        stack<int> st;

        //  maximum
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] < arr[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                maxSum += (long long)arr[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        //  minimum
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                minSum += (long long)arr[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        return (int)(maxSum - minSum);
    }
};
