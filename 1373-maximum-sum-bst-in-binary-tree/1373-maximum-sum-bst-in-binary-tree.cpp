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
    struct info{
        bool isbst;
        int maxval;
        int minval;
        int cnt;
    };
    int ans=0;
    info dfs(TreeNode* node)
    {
        if(!node)
            return {true,INT_MIN,INT_MAX,0};
        
        auto l=dfs(node->left);
        auto r=dfs(node->right);

        if(l.isbst && r.isbst && l.maxval<node->val && r.minval>node->val)
        {
            int tot=r.cnt+l.cnt+node->val;
            ans=max(ans,tot);
            return {true,max(node->val,r.maxval),min(node->val,l.minval),tot};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};