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
    int preOrderIdx = 0;
    unordered_map<int, int>map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(auto i = 0; i<inorder.size(); i++)
            map[inorder[i]] = i;
        return arrToTree(preorder, 0, preorder.size()-1);
    }
    
    private: TreeNode* arrToTree(vector<int>& preorder, int left, int right){
        if(left>right) return NULL;
        int rootV = preorder[preOrderIdx++];
        TreeNode *root = new TreeNode(rootV);
        
        root->left = arrToTree(preorder, left, map[rootV]-1);
        
        root->right = arrToTree(preorder, map[rootV]+1, right);
        
        return root;
    }
};