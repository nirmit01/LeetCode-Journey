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
    int ans=0;
    pair<int,int> dfs(TreeNode* root)
    {
        if(!root)
            return {-1,-1};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        
        int le=1+(l.second);
        int ri=1+(r.first);

        ans=max(ans,max(le,ri));
        return {le,ri};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};