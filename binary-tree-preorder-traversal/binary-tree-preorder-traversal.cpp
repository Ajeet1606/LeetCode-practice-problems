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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>a;
        if(root == NULL) return a;
        stack<TreeNode*>s;
        s.push(root);
        while(s.empty()==false){
            TreeNode* curr = s.top();
            a.push_back(curr->val);
            s.pop();
            if(curr->right != NULL)
                s.push(curr->right);
            if(curr->left != NULL)
                s.push(curr->left);
        }
        return a;
    }
};