/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>a;
            while(n--){
                Node* node = q.front();
                q.pop();
                int v = node->val;
                vector<Node*>child = node->children;
                a.push_back(v);
                for(auto a: child){
                    q.push(a);
                }
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};