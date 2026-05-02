class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            bool isValid = true;
            bool isDiff = false;

            while(x > 0) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) {
                    isValid = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    isDiff = true;
                }
                x /= 10;
            }
            if (isValid && isDiff) cnt++;
        }
        return cnt;
    }
};