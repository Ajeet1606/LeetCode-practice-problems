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
private:
    bool isLeft = true;
    int ans = 0;
public:
    
    void findSum(TreeNode* root)
    {
        if(root->left){
            isLeft = true;
            findSum(root->left);
        }
        if(root->right){
            isLeft = false;
            findSum(root->right);
        }
        if(!root->left && !root->right && isLeft){
            ans += root->val;
        }
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return ans;
        if(!root->left && !root->right) return ans;
        findSum(root);
        return ans;
    }
};