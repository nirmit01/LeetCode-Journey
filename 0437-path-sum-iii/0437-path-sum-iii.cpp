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
    void solve(TreeNode* root, long long curr, int tgt, unordered_map<long long,int>& mpp, int& ans)
    {
        if(!root)
            return;

        curr+=root->val;
        ans+=mpp[curr-tgt];
        mpp[curr]++;

        solve(root->left,curr,tgt,mpp,ans);
        solve(root->right,curr,tgt,mpp,ans);

        mpp[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mpp;
        mpp[0]=1;
        int ans=0;
        solve(root, 0, targetSum, mpp, ans);
        return ans;
    }
};