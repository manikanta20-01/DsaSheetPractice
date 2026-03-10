class Solution:
    def countSubarrays(self, arr):
        # code here
        
        n = len(arr)
        count = 0
        s = [(0, n)]
        for i in reversed(range(n)):
            while s[-1][0] >= arr[i]:
                s.pop()
            count += s[-1][1] - i
            s.append((arr[i], i))
        return count