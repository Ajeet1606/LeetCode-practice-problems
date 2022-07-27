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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        //go to the left most subtree
        flatten(root->left);
        //go to it's right.
        flatten(root->right);
        //for any root if left child exists
        if(root->left){
            //store its right somewhere.
            TreeNode *Right = root->right;
            //assign left on right position.
            root->right = root->left;
            //null on left.
            root->left = NULL;
            //now the left we assigned on right, pick it's rightmost node,
            while(root->right){
                root = root->right;
            }
            //attach it to the actual right that we stored earlier.
            root->right = Right;
        }
    }
};