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
    void flatten(TreeNode* root) {
        if(!root) return;
        //stack to store nodes
        stack<TreeNode*>s;
        //add the root node first.
        s.push(root);
        
        while(!s.empty()){
            //pick the top node.
            TreeNode *curr = s.top();
            s.pop();
            //if it has right, push in stack.
            if(curr->right)
                s.push(curr->right);
            //left also, if exist.
            if(curr->left)
                s.push(curr->left);
            //if any exists in above condition, we assign in right of curr, we pushed left later so that it stays on top.
            if(!s.empty())
                curr->right = s.top();
            //make left null.
            curr->left = NULL;
        }
    }
};