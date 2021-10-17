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
private:
    int ans;
    unordered_set<int>set;
public:
    
    int getMax(){
        int ans = 0;
        for(auto x: set){
            ans = max(ans, x);
        }
        return ans;
    }
    
    void parseValues(int x, int k){
        if(set.size() < k) set.insert(x);
        else{
            int max = getMax();
            if(x < max){
                set.insert(x);
                set.erase(max);
            }
        }
    }
    
    void traverse(TreeNode* root, int k){
        if(root == NULL) return;
        parseValues(root->val, k);
        traverse(root->left, k);
        traverse(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);   
        int res = INT_MIN;
        for(auto x: set)
            res = max(res, x);
        return res;
    }
};