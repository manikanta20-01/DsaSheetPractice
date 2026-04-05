class Solution:
    def totalWays(self, arr, target):
        # code here
        from functools import cache
        
        n = len(arr)
        
        @cache
        def dfs(i, target):
            if i >= n:
                return 1 if target == 0 else 0
            return dfs(i+1, target+arr[i]) + dfs(i+1, target-arr[i])
            
        return dfs(0, target)