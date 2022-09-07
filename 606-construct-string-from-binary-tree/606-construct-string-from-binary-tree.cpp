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
    
    void preorder(TreeNode* root, string &ans){
        if(root->val < 0){
            ans += '-';
        }
        ans += to_string(abs(root->val));
        
        if(root->left != NULL){
            ans += '(';
            preorder(root->left, ans);
            ans += ')';
        }else{
            if(root->right != NULL){
                ans += '(';
                ans += ')';
            }
        }
        
        if(root->right != NULL){
            ans += '(';
            preorder(root->right, ans);
            ans += ')';
        }
    }
    
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }
};