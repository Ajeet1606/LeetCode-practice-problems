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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        bool level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int>curr(size);
            for(int i=0; i<size; i++){
                TreeNode *tmp = q.front();
                q.pop();
                if(level == 0)
                    curr[i] = tmp->val;
                else
                    curr[size-i-1] = tmp->val;
                
                
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            }
            
            res.push_back(curr);
            level = !level;
        }
        return res;
    }
};