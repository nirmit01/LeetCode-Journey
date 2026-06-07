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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp;
        unordered_map<int,bool> ischild;
        for(auto& x:descriptions)
        {
            if(!mpp[x[0]])
                mpp[x[0]]=new TreeNode(x[0]);
            if(!mpp[x[1]])
                mpp[x[1]]=new TreeNode(x[1]);

            if(x[2])
                mpp[x[0]]->left=mpp[x[1]];
            else
                mpp[x[0]]->right=mpp[x[1]];
            ischild[x[1]]=true;
        }
        for(auto& x:mpp)
        {
            if(!ischild[x.first])
                return x.second;
        }
        return nullptr;
    }
};