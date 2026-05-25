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

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);

        int k1=0,k2=0;
        if(root->left && root->left->val==root->val)
            k1=1+left;
        if(root->right && root->right->val==root->val)
            k2=1+right;
        ans=max(ans,k1+k2);
        return max(k1,k2);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};