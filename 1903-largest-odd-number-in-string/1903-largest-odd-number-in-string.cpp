class Solution {
public:
    string largestOddNumber(string num) {
        int l = num.size();

        while(l--) {
            if((num[l] - '0') % 2) {
                return num.substr(0, l + 1);
            }
        }
        return "";
    }
};