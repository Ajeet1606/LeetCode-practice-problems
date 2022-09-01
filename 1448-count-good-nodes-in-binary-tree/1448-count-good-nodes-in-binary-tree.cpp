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
    
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, root->val});
        int ans = 0;
        while(!q.empty()){
            TreeNode *pointer = q.front().first;
            int max = q.front().second;
            q.pop();
            if(max <= pointer->val){
                ans++;
                max = pointer->val;
            }
            if(pointer->left) q.push({pointer->left, max});
            if(pointer->right) q.push({pointer->right, max});
        }
        return ans;
    }
};