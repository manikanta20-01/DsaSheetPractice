// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>post;
        vector<int>negi;
        
        for(int i = 0;i < n;i++)
        {
            if(arr[i] < 0)
            {
                negi.push_back(arr[i]);
            }
            else{
                post.push_back(arr[i]);
            }
        }
        
        int i = 0, j = 0, k = 0;
        
        while(i < post.size() && j < negi.size())
        {
            arr[k++] = post[i++];
            arr[k++] = negi[j++];
        }
        
        while(i < post.size())
        {
            arr[k++] = post[i++];
        }
        while(j < negi.size())
        {
            arr[k++] = negi[j++];
        }
        
    }
};