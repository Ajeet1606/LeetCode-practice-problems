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
    vector<int>arr;
    void makeArray(TreeNode *root){
        if(root != NULL){
            makeArray(root->left);
            arr.push_back(root->val);
            makeArray(root->right);
        }
    }
    
    bool isSorted(){
        for(int i=1; i<arr.size(); i++){
            if(arr[i] <= arr[i-1])
                return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        makeArray(root);
        return isSorted();
    }
};