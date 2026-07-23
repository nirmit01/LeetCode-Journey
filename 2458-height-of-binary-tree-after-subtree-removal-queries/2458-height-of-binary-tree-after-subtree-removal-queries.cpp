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
    unordered_map<int,int> height, ans;

    int getheight(TreeNode* root)
    {
        if(root==nullptr)
            return -1;
        int l=getheight(root->left);
        int r=getheight(root->right);

        return height[root->val]= 1+max(l,r);
    }

    void dfs(TreeNode* root, int up,int depth)
    {
        ans[root->val]=up;
        if(root->left)
        {
            int hgt= (root->right) ? height[root->right->val] : -1;
            int newup = max(up,depth+1+hgt);
            dfs(root->left,newup,depth+1);
        }
        if(root->right)
        {
            int hgt= (root->left) ? height[root->left->val] : -1;
            int newup = max(up,depth+1+hgt);
            dfs(root->right,newup,depth+1);
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getheight(root);
        dfs(root,0,0);
        vector<int> vec;
        for(int i:queries)
            vec.push_back(ans[i]);

        return vec;
    }
};