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
    vector<int>ans;
    
    void traverse(TreeNode* root){
        if(root != NULL){
            traverse(root->left);
            
            ans.push_back(root->val);
            
            traverse(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }
};