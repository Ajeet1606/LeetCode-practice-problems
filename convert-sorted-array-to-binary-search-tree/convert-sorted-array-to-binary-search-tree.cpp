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
    TreeNode* sortedArrayToBST(vector<int>& num) {
        int n = num.size();
        if(n==0)
            return NULL;
        if(n==1)
            return new TreeNode(num[0]);
        int mid = n/2;
        TreeNode* root = new TreeNode(num[mid]);
        vector<int>leftArr(num.begin(), num.begin()+mid);
        vector<int>rightArr(num.begin()+mid+1, num.end());
        root->left = sortedArrayToBST(leftArr);
        root->right = sortedArrayToBST(rightArr);
        return root;
    }
};