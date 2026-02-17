class Solution:
    def overlapInt(self, arr):
        # code here
        ans = []
        for s, e in arr:
            ans.append([s, 1])
            ans.append([e + 1, -1])
            
        ans.sort()
        
        best, curr = 0, 0
        for res, d in ans:
            curr += d
            best = max(best, curr)
            
        return best
        
