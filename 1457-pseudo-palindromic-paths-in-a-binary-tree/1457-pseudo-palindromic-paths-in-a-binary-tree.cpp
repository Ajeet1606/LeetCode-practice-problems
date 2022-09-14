
class Solution {
public:
    int ans = 0, mask = 0;
    
    void preorder(TreeNode* root){
        //update current number in mask
        mask = mask^(1<<root->val);
        //check leaf node
        if(root->left == NULL and root->right == NULL){
            if((mask & (mask-1)) == 0) ans++;
        }else{
            if(root->left)  //go to left child
                preorder(root->left);
            if(root->right) // go to right child
                preorder(root->right);
        }
        //remove current number from mask
        mask = mask^(1<<root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return ans;
        preorder(root);
        return ans;
    }
};