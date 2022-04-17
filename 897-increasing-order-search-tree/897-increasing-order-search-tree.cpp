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
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>arr;
        inorder(root, arr);
        TreeNode *ans = new TreeNode(0), *cur = ans;
        for(int a: arr){
            cur->right = new TreeNode(a);
            cur = cur->right;
        }
        return ans->right;
    }
    
    void inorder(TreeNode *root, vector<int>&arr){
        if(root == NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};