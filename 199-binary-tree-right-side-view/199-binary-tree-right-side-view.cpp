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
    vector<int> rightSideView(TreeNode* root) {
        //DFS approach.
        vector<int>ans;
        fun(root, ans, 0);
        return ans;
    }
    
    //basically for every level we're traversing right child first and we push an element in array at every level.
    //so right is called first, which is pushed and array size increases, later for same level when left child comes, array size is different so we skip that.
    void fun(TreeNode* root, vector<int>&ans, int level){
        if(!root) return;
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        
        fun(root->right, ans, level+1);
        fun(root->left, ans, level+1);
    }
};