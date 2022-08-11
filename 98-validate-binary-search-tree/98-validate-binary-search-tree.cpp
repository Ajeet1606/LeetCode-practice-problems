class Solution {
public:
        
    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN;
        stack<TreeNode*>s;
        while(root or !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            if(root->val <= min){
                return false;
            }
            
            min = root->val;
            root= root->right;
        }
        return true;
    }
};