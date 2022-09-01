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
    
    int solve(TreeNode *root, int max){
        if(root == NULL) return 0;
        int cnt = 0;
        if(root->val >= max){
            cnt++;
            max = root->val;
        }
        cnt += solve(root->left, max) + solve(root->right, max);
        return cnt;
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 1 + solve(root->left, root->val) + solve(root->right, root->val);
        return ans;
    }
};