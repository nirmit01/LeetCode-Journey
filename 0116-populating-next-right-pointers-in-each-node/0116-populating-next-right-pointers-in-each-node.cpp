/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            Node* k;
            while(sz--)
            {
                k=q.front();
                q.pop();
                if(sz>0)
                    k->next=q.front();
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
            }
            k->next=nullptr;
        }   
        return root;   
    }
};