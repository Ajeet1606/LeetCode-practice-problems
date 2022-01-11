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
    int ans = 0;
    string b = "";
    int getDecimal(){
        int n = b.length();
        int a = 0, i = n-1, bit = 0;
        while(i>=0){
            a += (b[i] - '0') * (1<<bit++);
            i--;
        }
        return a;
    }
    
    void helper(TreeNode* root){
        b += root->val == 1? '1': '0';
        // leaf node
        if(root->left == NULL and root->right == NULL){
            ans += getDecimal();
            cout<<ans<<" "<<b<<endl;
            b.pop_back();
            return;
        }
        if(root->left != NULL){
            helper(root->left);
        }
        if(root->right != NULL){
            helper(root->right);
        }
        b.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        helper(root);
        return ans;        
    }
};