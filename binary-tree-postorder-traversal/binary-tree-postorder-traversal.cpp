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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>a;
        postorder(root, a);
        return a;
    }
 
private:
    void postorder(TreeNode* root, vector<int>&a)
    {
        if(!root){
            return;
        }
        postorder(root->left, a);
        postorder(root->right, a);
        a.push_back(root->val);
    }
};