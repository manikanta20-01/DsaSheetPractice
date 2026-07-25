class Solution {
public:
    int maxProduct(int n) {
        int firstLargestNum = 0;
        int secondLargestNum = 0;
        while (n > 0) {
            int rem = n % 10;
            if (rem >= firstLargestNum) {
                secondLargestNum = firstLargestNum;
                firstLargestNum = rem;
            } else if (rem < firstLargestNum && rem > secondLargestNum) {
                secondLargestNum = rem;
            }
            n /= 10;
        }
        return (firstLargestNum * secondLargestNum);
    }
};