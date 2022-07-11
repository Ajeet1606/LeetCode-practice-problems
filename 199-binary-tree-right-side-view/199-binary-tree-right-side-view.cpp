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
    vector<int> rightSideView(TreeNode* root) {
        //BFS with queues.
        if(!root) return {};
        //ans array to store result.
        vector<int>ans;
        //queue to store all nodes of a particular level.
        queue<TreeNode*>q;
        //we start from level 1, root of tree.
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            // n tells the number of nodes in current level.
            // for every level
            for(int i=0; i<n; i++){
                TreeNode* curr= q.front();
                //get the node and pop from queue 
                q.pop();
                // if it's last node in the queue, means it's the right most of that level, it's our resultant node.
                if(i == n-1){
                    ans.push_back(curr->val);
                }
                // for this node if any child exists, push that too in queue. Notice that we don't change 'n' as size changes so we have track of curr level.
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                // when we re-enter in while loop now n changes and next level comes in charge. 
            }
        }
        return ans;
    }
};