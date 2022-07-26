/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        solve(root, p, q);
        
        return ans;
    }
    
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return false;
        //check for left subtree
        int left = solve(root->left, p, q)? 1: 0;
        //check for right.
        int right = solve(root->right, p, q)? 1: 0;
        //include current node
        int mid = (root == p or root == q)? 1: 0;
        //if any two are true, we've got ans.
        if(mid + left + right >= 2){
            ans = root;
        }
        
        return (mid+left+right>0);
    }
};