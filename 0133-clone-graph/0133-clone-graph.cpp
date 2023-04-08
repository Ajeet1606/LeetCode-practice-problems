

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>mp;
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, mp);
    }
    
    Node* dfs(Node* cur, unordered_map<Node*, Node*>&mp){
        vector<Node*>neighbor;
        Node *clone = new Node(cur->val);
        
        mp[cur] = clone;
        for(auto it: cur->neighbors){
            if(mp.find(it) != mp.end()){
                neighbor.push_back(mp[it]);
            }else{
                neighbor.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }
};