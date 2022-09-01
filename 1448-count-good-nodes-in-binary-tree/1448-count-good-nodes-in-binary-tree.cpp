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
    int ans = 0;
    void solve(TreeNode *root, int max){
        if(root == NULL) return;
        
        if(root->val >= max){
            ans++;
            max = root->val;
        }
        solve(root->left, max);
        solve(root->right, max);
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};