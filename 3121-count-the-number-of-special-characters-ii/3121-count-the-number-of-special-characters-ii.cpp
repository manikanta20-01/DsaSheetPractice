class Solution {
public:
    int numberOfSpecialChars(string word) {
        // islower

        vector<int>lowercasest(27,-1);
        vector<int>uppercasest(27,-1);

        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(islower(ch)){
                lowercasest[ch -'a'] = i;
            }
            else{
                if(uppercasest[ch-'A'] == -1) uppercasest[ch-'A'] = i;
            }
        }

        int cnt = 0;
        for(int i=0;i<27;i++){
            if((lowercasest[i] != -1 && uppercasest[i] != -1) && lowercasest[i] < uppercasest[i]) cnt++;
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna