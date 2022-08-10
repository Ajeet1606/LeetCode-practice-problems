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
    
    TreeNode* binary_search(vector<int>&arr, int l, int r){
        if(r<l){
            return NULL;
        }
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = binary_search(arr, l, mid-1);
        root->right = binary_search(arr, mid+1, r);
        
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return binary_search(arr, 0, arr.size() - 1);
    }
};