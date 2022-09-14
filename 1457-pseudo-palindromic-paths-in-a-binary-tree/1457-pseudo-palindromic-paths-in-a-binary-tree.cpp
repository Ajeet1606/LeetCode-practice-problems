
class Solution {
public:
    vector<int>arr;
    int ans = 0;
    
    void inorder(TreeNode* root){
        arr[root->val]++;
        if(root->left == NULL and root->right == NULL){
            //check permutation
            int ones = 0;
            bool flag = true;
            for(int i=1; i<10 and ones < 2; i++){
                if(arr[i] % 2 != 0){
                    ones++;
                }
            }
            if(ones < 2) ans++;
        }else{
            if(root->left)
                inorder(root->left);
            if(root->right)
                inorder(root->right);
        }
        arr[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return ans;
        arr.resize(10, 0);
        inorder(root);
        return ans;
    }
};