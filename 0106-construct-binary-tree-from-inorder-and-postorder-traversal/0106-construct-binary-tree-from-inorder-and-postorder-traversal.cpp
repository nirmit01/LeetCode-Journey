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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int i1,int i2,int p1,int p2,unordered_map<int,int>& mpp)
    {
        if(i1>i2)
            return nullptr;
        if(p1>p2)
            return nullptr;
        TreeNode* root= new TreeNode(postorder[p2]);
        int idx=mpp[postorder[p2]];
        int leftsize=idx-i1;
        root->left = build(inorder,postorder,i1,idx-1,p1,p1+leftsize-1,mpp);
        root->right = build(inorder,postorder,idx+1,i2,p1+leftsize,p2-1,mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(inorder, postorder,0,n-1,0,n-1,mpp);
    }
};