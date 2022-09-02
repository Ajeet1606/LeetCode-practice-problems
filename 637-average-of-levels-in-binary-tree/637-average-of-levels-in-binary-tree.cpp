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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int>count;
        vector<double>sum;
        solve(root, 0, count, sum);
        
        for(int i=0; i<sum.size(); i++){
            sum[i] = sum[i]/count[i];
        }
        
        return sum;
    }
    
    void solve(TreeNode*root, int i, vector<int>&count, vector<double>&sum){
        if(root == NULL) return;
        
        if(i < sum.size()){
            sum[i] += root->val;
            count[i]++;
        }else{
            sum.push_back(root->val);
            count.push_back(1);
        }
        
        solve(root->left, i+1, count, sum);
        solve(root->right, i+1, count, sum);
    }
};