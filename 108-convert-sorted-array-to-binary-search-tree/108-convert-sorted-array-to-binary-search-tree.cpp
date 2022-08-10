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
    
    void fun(int l, int r, TreeNode* root, vector<int>&arr, bool left){
        if(r<l){
            return;
        }
        int mid = l+(r-l)/2;
        if(left){
            root->left = new TreeNode(arr[mid]);
            root = root->left;
        }else{
            root->right = new TreeNode(arr[mid]);
            root = root->right;
        }
        fun(l, mid-1, root, arr, true);
        fun(mid+1, r, root, arr, false);
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1, mid = n/2;
        
        TreeNode *root = new TreeNode(arr[mid]);
        cout<<root->val;
        fun(l, mid-1, root, arr, true);
        fun(mid+1, r, root, arr, false);
        return root;
    }
};