class Solution {
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl

public:
    int n;
    vector<vector<long long>> flat;   

    long long convert(long long x, long long y, long long s) {
        if (y == 0)
            return x; // bottom

        if (y == s)   // top
            return 2LL * s + (s - x);

        if (x == 0)   // left
            return 3LL * s + (s - y);

        if (x == s)   // right
            return s + y;

        return 0;
    }

    bool check(long long x, int k) {
        for (int i = 0; i < n; i++) {

            vector<long long> curr = flat[i];
            vector<long long> st = flat[i];
            bool flag = true;

            for (int j = 1; j < k; j++) {
                // deb(curr);
                auto next = lower_bound(
                    flat.begin(), flat.end(), curr[0] + x,
                    [](const vector<long long>& a, long long value) {
                        return a[0] < value;
                    }
                );

                if (next == flat.end()) {
                    flag = false;
                    break;
                }
                curr = *next;
            }

            if (flag &&
                llabs(st[1] - curr[1]) + llabs(st[2] - curr[2]) >= x)
                return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {

        n = points.size();

        for (int i = 0; i < n; i++) {
            long long flat_x = convert(points[i][0], points[i][1], side);
            flat.push_back({flat_x, points[i][0], points[i][1]});
        }

        sort(flat.begin(), flat.end(),
             [](const vector<long long>& a, const vector<long long>& b) {
                 return a[0] < b[0];
             });

        long long l = 0, r = 4LL * side, ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;

            if (check(mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return (int)ans;
    }
};
