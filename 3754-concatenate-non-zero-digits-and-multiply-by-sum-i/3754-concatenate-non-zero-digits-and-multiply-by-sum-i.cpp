class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
    long long digitSum = 0;

    if (n == 0) return 0;  // edge case

    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            // build x in reverse first
            x = x * 10 + d;
            digitSum += d;
        }
        n /= 10;
    }

    // x was built in reverse; reverse it back
    long long rev = 0;
    long long temp = x;
    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    return rev * digitSum;
    }
};