class Solution:
    def largest(self, arr):
        # code here
        l = arr[0]
        
        for i in arr:
            if i>l:
                l = i
        return l
        
