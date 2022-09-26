//we'll be grouping the nodes together which are equal first then for unequal nodes, search for contrary condition.

class Solution {
public:
    //array to store parent of every node
    int parent[26];
    
    int findParent(int x){
        //if node is parent of itself, return.
        //else check for the top most parent.
        return parent[x] == x? x: findParent(parent[x]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        //assign parent
        for(int i=0; i<26; i++)
            parent[i] = i;
        //handle equality condition
        for(auto eq: equations){
            if(eq[1] == '='){
                //find parent of both characters.
                //make first as child of second
                parent[findParent(eq[0]-'a')] = findParent(eq[3]-'a');
            }
        }
        //unequal condition, find contradiction.
        for(auto eq: equations){
            //if it's unequal case
            //and parent of both nodes are same, ans is false.
            if(eq[1] == '!' and findParent(eq[0]- 'a') == findParent(eq[3] - 'a')){
                return false;
            }
        }
        //no contradiction found, return true.
        return true;
    }
};