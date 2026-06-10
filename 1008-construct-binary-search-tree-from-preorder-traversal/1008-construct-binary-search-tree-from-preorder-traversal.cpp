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

    TreeNode* insert(TreeNode* root, int val)
    {
        if(!root)
            return new TreeNode(val);

        if(val>root->val)
            root->right=insert(root->right,val);
        else
            root->left=insert(root->left,val);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=nullptr;
        for(int i:preorder)
        {
            root=insert(root,i);
        }
        return root;
    }
};