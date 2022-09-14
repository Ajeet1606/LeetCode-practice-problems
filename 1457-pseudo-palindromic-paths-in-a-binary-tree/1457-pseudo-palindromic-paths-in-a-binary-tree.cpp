class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        //node, mask
        queue<pair<TreeNode*, int>>q;
        
        q.push({root, 0^(1<<root->val)});
        while(!q.empty()){
            auto [node, mask] = q.front();
            q.pop();
            
            if(node->left == NULL and node->right == NULL){
                //be careful on the paranthesis in below operation
                if((mask & (mask-1)) == 0) ans++;
            }
            if(node->left){
                q.push({node->left, mask^(1<<(node->left->val))});
            }
            if(node->right){
                q.push({node->right, mask^(1<<(node->right->val))});
            }
        }
        return ans;
    }
};