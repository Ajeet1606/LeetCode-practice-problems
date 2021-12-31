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
    int result = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        result  = 0;
        helper(root, root->val, root->val);
        return result;
    }
    
    
    void helper(TreeNode *node, int curMax, int curMin){
        if(node == NULL)
            return;
        result = max(result, max(abs(curMax-node->val), abs(curMin-node->val)));
        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);
        helper(node->left, curMax, curMin);
        helper(node->right, curMax, curMin);
        
    }
};