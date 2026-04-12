class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++)
        {
            int j = i;
            int k = 0;
            int ele = mat[j][k];
            while (j<n && k<m)
            {
                
                if (ele!=mat[j][k])
                {
                    return false;
                }
                j++;
                k++;
            }
            
        }
        for(int i = 1;i<m;i++)
        {
            int j = 0;
            int k = i;
            int ele = mat[j][k];
            while (j<n && k<m)
            {
                
                if (ele!=mat[j][k])
                {
                    return false;
                }
                j++;
                k++;
            }
            
        }
        return true;

    }
};