class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return 0;
        }

        // Initialize dp and dp2 arrays
        vector<vector<long long>> dp(n + 1);
        vector<vector<long long>> dp2(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = vector<long long>(n + 1 - i, 0);
            dp2[i] = vector<long long>(n + 1 - i, 0);
        }

        // Initialize max_h array
        vector<long long> max_h(n + 1, 0);

        for (int j = 1; j < n; ++j) {
            long long dp_0 = 0;
            for (int h = 0; h <= n; ++h) {
                for (int i = 0; i <= h; ++i) {
                    if (dp[i][h - i] > dp_0) {
                        dp_0 = dp[i][h - i];
                    }
                }
                dp2[h][0] = dp_0;
                if (h < n) {
                    dp_0 += grid[h][j - 1];
                }
                for (int i = 0; i <= h; ++i) {
                    if (max_h[h] > dp2[h][0]) {
                        dp2[h][0] = max_h[h];
                    }
                }

                long long s = 0, max_val = dp2[h][0];
                for (int l = 1; l <= n - h; ++l) {
                    s += grid[h + l - 1][j];
                    dp2[h][l] = max_h[h + l] + s;
                    if (dp2[h][l] > max_val) {
                        max_val = dp2[h][l];
                    }
                }
                max_h[h] = max_val;
            }
            dp.swap(dp2);
        }

        // Find the maximum value
        long long res = dp[0][0];
        for (const auto& r : dp) {
            for (const auto& v : r) {
                if (v > res) {
                    res = v;
                }
            }
        }
        return res;
    }
};