class Solution:
    def equalSumSpan(self, a1, a2):
        n = len(a1)
        
        # Dictionary to store first occurrence of prefix difference
        d = {0: -1}
        
        s = 0   # running difference
        maxi = 0
        
        for i in range(n):
            # Difference of prefix sums
            s += a1[i] - a2[i]
            
            if s not in d:
                d[s] = i
            else:
                maxi = max(maxi, i - d[s])
        
        return maxi