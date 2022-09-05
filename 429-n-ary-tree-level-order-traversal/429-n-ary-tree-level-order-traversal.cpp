class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(Node* root, int level){
        if(root == NULL){
            return;
        }
        if(level == ans.size())
            ans.emplace_back();
        
        ans[level].push_back(root->val);
        vector<Node*>child = root->children;
        for(auto c: child){
            dfs(c, level+1);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        dfs(root, 0);
        
        return ans;
    }
};