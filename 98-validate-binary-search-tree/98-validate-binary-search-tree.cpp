class Solution {
public:
    bool ans = true;
    TreeNode *min;
    
    void validate(TreeNode *root){
        if(root == NULL) return;
        validate(root->left);
        
        if(min != NULL and min->val >= root->val){
            ans = false;
            return;
        }
        
        min = root;
        validate(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        validate(root);
        return ans;
    }
};