
class Solution {
public:
    vector<vector<int>>ans;
    
    void inorder(TreeNode* root, vector<int>&v, int& sum, int& targetSum){
        if(root == NULL) return;
        //operate on root
        sum += root->val;
        v.push_back(root->val);
        if(sum == targetSum and root->left == NULL and root->right == NULL){
            ans.push_back(v);
        }else{
            inorder(root->left, v, sum, targetSum);
            
            inorder(root->right, v, sum, targetSum);
        }
        v.pop_back();
        sum -= root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        int sum = 0;
        inorder(root, v, sum, targetSum);
        return ans;
    }
};