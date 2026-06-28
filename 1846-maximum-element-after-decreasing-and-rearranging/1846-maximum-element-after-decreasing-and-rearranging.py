class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr.sort()
        ans=1
        for x in arr[1:]:
            ans=min(x, ans+1)
        return ans
        