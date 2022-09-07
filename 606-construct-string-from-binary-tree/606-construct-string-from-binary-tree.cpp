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
    string tree2str(TreeNode* root) {
        stack<TreeNode*>st;
        unordered_set<TreeNode*>set;
        string ans = "";
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(set.count(curr) == 1){
                st.pop();
                ans += ')';
            }
            else{
                set.insert(curr);
                ans += '(';
                if(curr->val < 0) ans += '-';
                ans += to_string(abs(curr->val));
                if(curr->left == NULL and curr->right != NULL)
                    ans += "()";
                
                if(curr->right != NULL){
                    st.push(curr->right);
                }
                if(curr->left != NULL){
                    st.push(curr->left);
                }
            }
        }
        return ans.substr(1, ans.length()-2);
    }
};