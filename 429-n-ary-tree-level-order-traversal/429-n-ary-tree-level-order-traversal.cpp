class Solution {
public:
    unordered_map<int, vector<int>>m;
    
    void dfs(Node* root, int level){
        if(root->children.size() == 0){
            m[level].push_back(root->val);
            return;
        }
        
        vector<Node*>child = root->children;
        for(auto c: child){
            dfs(c, level+1);
        }
        m[level].push_back(root->val);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        dfs(root, 0);
        vector<vector<int>>ans;
        for(int i=0; i<m.size(); i++){
            ans.push_back(m[i]);
        }
        return ans;
    }
};