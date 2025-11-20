class Solution:
    def reverseingroups(self, arr, k):
        #code here
        n = len(arr)
        i = 0
        
        while(i < n):
            start = i
            end = min(i + k - 1,n - 1)
            
            while(start < end):
                arr[start], arr[end] = arr[end], arr[start]
                start+=1
                end-=1
            i += k
                
        return arr
                