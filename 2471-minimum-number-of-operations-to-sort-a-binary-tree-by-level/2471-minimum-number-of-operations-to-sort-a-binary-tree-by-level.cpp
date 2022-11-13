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
    
    int fun(vector<int>&a){
        int cnt = 0;
        vector<int>b = a;
        map<int, int>m;
        sort(begin(b), end(b));
        
        for(int i=0; i<a.size(); ++i){
            m[a[i]] = i;
        }
        
        for(int i=0; i<a.size(); ++i){
            if(a[i] != b[i]){
                a[m[b[i]]] = a[i];
                m[a[i]] = m[b[i]];
                m[b[i]] = i;
                a[i] = b[i];
                cnt++;
            }
        }
        return cnt;
    }
    
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>a;
            while(n--){
                TreeNode* cur = q.front();
                a.push_back(cur->val);
                q.pop();
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }
            
            ans += fun(a);
        }
        
        return ans;
    }
};