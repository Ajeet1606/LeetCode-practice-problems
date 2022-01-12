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
    
    void helper(TreeNode* root, int x){
        if(root->val < x){
            if((root->right == NULL)){
                root->right = new TreeNode(x);
            }
            else{
                helper(root->right, x);
            }
        }
        else{
            if((root->left == NULL)){
                root->left = new TreeNode(x);
            }
            else{
                helper(root->left, x);
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root == NULL)
            return new TreeNode(x);
        helper(root, x);
        return root;
    }
};