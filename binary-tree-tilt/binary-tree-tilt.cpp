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
    int ans = 0;
public:
    
    int helper(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int tilt = abs(left - right);
        ans += tilt;
        return root->val + left + right;
    }
    
    int findTilt(TreeNode* root) { 
        int sum = helper(root);
        return ans;
    }
};