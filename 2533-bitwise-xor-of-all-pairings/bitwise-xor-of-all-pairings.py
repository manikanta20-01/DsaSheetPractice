class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        xor1, xor2 = 0, 0
        
        # Compute XOR of all elements in nums1
        for num in nums1:
            xor1 ^= num
        
        # Compute XOR of all elements in nums2
        for num in nums2:
            xor2 ^= num
        
        # Determine the number of times each array contributes to the result
        len1, len2 = len(nums1), len(nums2)
        
        # XOR of all elements in nums3
        result = 0
        
        if len2 % 2 == 1:  # nums1 elements appear an odd number of times
            result ^= xor1
        
        if len1 % 2 == 1:  # nums2 elements appear an odd number of times
            result ^= xor2
        
        return result