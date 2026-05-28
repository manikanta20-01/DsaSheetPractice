class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>&q) {
        int n = words.size();
        unordered_map<uint64_t,int>mpp;
        int best = 0;
        uint64_t base = 313;

        auto update = [&](int& curr,int idx)
        {
            int currlen = words[curr].size();
            int nlen = words[idx].size();

            if(nlen<currlen)curr = idx;
            else if(nlen==currlen && idx<curr)curr = idx;
        };

        for(int i=0;i<n;++i)
        {
            update(best,i);
            uint64_t hash = 0;
            string& word = words[i];

            for(int j=word.size()-1;j>=0;--j)
            {
                hash = hash*base + word[j];
                if(mpp.find(hash)==mpp.end())mpp[hash] = i;
                else update(mpp[hash],i);
            }
        }

        vector<int>ans;

        for(auto&it:q)
        {
            string& s = it;
            uint64_t hash = 0;
            int saru = best;
            for(int i=s.size()-1;i>=0;--i)
            {
                hash = hash*base + s[i];
                if(mpp.find(hash)!=mpp.end())
                {
                    saru = mpp[hash];
                }
                else break;
            }
            ans.push_back(saru);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna