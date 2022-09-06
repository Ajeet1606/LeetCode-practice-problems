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
    
    bool containsOne(TreeNode* root){
        if(root == NULL) return false;
        
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        
        if(root->val == 1 or left or right)
            return true;
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root: NULL;
    }
};