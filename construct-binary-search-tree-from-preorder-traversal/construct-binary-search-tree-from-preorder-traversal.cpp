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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1);
        
    }
    
    // i, j is the index of subtree
    TreeNode* buildTree(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        if (i == j) return new TreeNode(nums[i]);
        
        int left_start = i + 1;
        
        // the first element greater than nums[i]
        int right_start = i; 
        while (right_start < nums.size() && nums[right_start] <= nums[i]) {
            right_start++;
        }
        
        int left_end = right_start - 1;
        int right_end = j;
        
        TreeNode* root = new TreeNode(nums[i]);
        root->left = buildTree(nums, left_start, left_end);
        root->right = buildTree(nums, right_start, right_end);
        
        return root;
    }
};