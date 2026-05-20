class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = []
        seen = [0] * (n + 1)
        common = 0
        
        for i in range(n):
            if seen[A[i]] == 0:
                seen[A[i]] = 1
            elif seen[A[i]] == 1:
                common += 1
            if seen[B[i]] == 0:
                seen[B[i]] = 1
            elif seen[B[i]] == 1:
                common += 1
            ans.append(common)
        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna