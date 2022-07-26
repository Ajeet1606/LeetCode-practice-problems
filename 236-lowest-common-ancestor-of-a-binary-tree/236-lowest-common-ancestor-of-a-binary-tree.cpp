/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        
        deque<TreeNode*>s1, s2;
        generatePath(root, s1, p);
        flag = false;
        generatePath(root, s2, q);
        auto it1 = s1.begin(), it2 = s2.begin();
        while(it1 != s1.end() and it2 != s2.end()){
            if(*it1 == *it2){
                ans = *it1;
            }else{
                break;
            }
            it1++; it2++;
        }
        return ans;
    }
    
    void generatePath(TreeNode* root, deque<TreeNode*>&s, TreeNode* x){
        if(root){
            //cout<<root->val<<" "<<flag<<endl;
            if(flag) return;
            s.push_back(root);
            if(root == x){
                flag = true;
            }
            if(!flag){
                generatePath(root->left, s, x);
                generatePath(root->right, s, x);
                if(!flag) s.pop_back();
            }
        }
    }
};