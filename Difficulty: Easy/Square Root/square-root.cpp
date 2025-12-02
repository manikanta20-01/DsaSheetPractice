class Solution {
  public:
    int floorSqrt(int n) {
        
        int start = 0, end = n;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(mid * mid == n) return mid;
            
            else if(mid * mid > n) end = mid - 1;
            
            else start = mid + 1;
            
        }
        return end;
    }
};