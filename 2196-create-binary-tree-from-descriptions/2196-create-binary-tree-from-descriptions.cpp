/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*> mpp;

        for(int i = 0; i < desc.size(); i++)
        {
            int parent = desc[i][0];
            int child = desc[i][1];
            int isleft = desc[i][2];

            if(mpp.find(parent) == mpp.end())
                mpp[parent] = new TreeNode(parent);

            if(mpp.find(child) == mpp.end())
                mpp[child] = new TreeNode(child);

            if(isleft)
                mpp[parent]->left = mpp[child];
            else
                mpp[parent]->right = mpp[child];
        }

        for(int i = 0; i < desc.size(); i++)
        {
            int child = desc[i][1];
            mpp.erase(child);
        }

        auto it = mpp.begin();
        return it->second;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna