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
        
        TreeNode* curr= root, *pre = NULL;
        //for every node
        while (curr){
            //if left subtree exists,
            if(curr->left){
                pre = curr->left;
                //we pick it's right most node 
                while(pre->right)
                    pre = pre->right;
                //and attach curr->right to it.
                pre->right = curr->right;
                //and left of curr, becomes right
                curr->right = curr->left;
                //left becomes null.
                curr->left = NULL;
            }
            //go to it's right node.
            curr = curr->right;
        }
    }
};