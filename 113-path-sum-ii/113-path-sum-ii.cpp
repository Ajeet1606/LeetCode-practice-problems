//DFS approach

class Solution {
public:
    vector<vector<int>>ans;
    
    void BFS(TreeNode* root, int& targetSum){
                //Current node,   sum,  path
        queue<pair<TreeNode*, pair<int, vector<int>>>>q;
        q.push({root, {root->val, {root->val}}});
        
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int sum = q.front().second.first;
            vector<int>path = q.front().second.second;
            q.pop();
            
            if(!curr->left and !curr->right and sum == targetSum){
                ans.push_back(path);
            }
            
            if(curr->left){
                vector<int>left = path;
                left.push_back(curr->left->val);
                q.push({curr->left, {sum+curr->left->val, left}});
            }
                       
            if(curr->right){
                vector<int>right = path;
                right.push_back(curr->right->val);
                q.push({curr->right, {sum + curr->right->val, right}});
            }
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        BFS(root, targetSum);
        
        return ans;
    }
};



//BFS approach


class Solution {
public:
    vector<vector<int>>ans;
    
    void BFS(TreeNode* root, int& targetSum){
                //Current node,   sum,  path
        queue<pair<TreeNode*, pair<int, vector<int>>>>q;
        q.push({root, {root->val, {root->val}}});
        
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int sum = q.front().second.first;
            vector<int>path = q.front().second.second;
            q.pop();
            
            if(!curr->left and !curr->right and sum == targetSum){
                ans.push_back(path);
            }
            
            if(curr->left){
                vector<int>left = path;
                left.push_back(curr->left->val);
                q.push({curr->left, {sum+curr->left->val, left}});
            }
                       
            if(curr->right){
                vector<int>right = path;
                right.push_back(curr->right->val);
                q.push({curr->right, {sum + curr->right->val, right}});
            }
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        BFS(root, targetSum);
        
        return ans;
    }
};
