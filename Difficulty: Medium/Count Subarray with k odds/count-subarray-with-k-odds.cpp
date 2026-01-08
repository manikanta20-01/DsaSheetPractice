class Solution {
  public:
    virtual int atleastk(vector<int> &arr, int k){
      int i=0, j=0, n=arr.size();
      int c=0, ans=0;
      
      for(int j=0; j<n; j++){
        if(arr[j] & 1) c++;
        while(c==k){
          ans+=(n-j);
          if(arr[i] & 1) c--;
          i++;
        }
      }
      
      return ans;        
    }
    
    virtual int countSubarrays(vector<int> &arr, int k){
      return atleastk(arr, k) - atleastk(arr, k+1);
    }
};