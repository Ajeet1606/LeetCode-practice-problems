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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //empty tree.
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        //we push every level in this queue, start from root.
        q.push(root);
        //queue will be empty when we finish whole tree.
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            //for every node of current level.
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                //insert all childs of curr node.
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                v.push_back(curr->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};