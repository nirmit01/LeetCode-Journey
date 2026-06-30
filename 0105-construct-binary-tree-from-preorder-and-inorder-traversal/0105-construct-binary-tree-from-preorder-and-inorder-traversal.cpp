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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p1,int p2,int i1,int i2,unordered_map<int,int>& mpp)
    {
        if(p1>p2)
            return nullptr;
        if(i1>i2)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[p1]);
        int idx=mpp[preorder[p1]];
        int leftsize=idx-i1;
        root->left = build(preorder,inorder,p1+1,p1+leftsize,i1,idx-1,mpp);
        root->right = build(preorder,inorder,p1+leftsize+1,p2,idx+1,i2,mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1,0,n-1,mpp);
    }
};