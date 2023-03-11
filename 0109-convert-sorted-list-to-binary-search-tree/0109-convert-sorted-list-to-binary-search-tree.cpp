class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        return dfs(head, NULL);
    }
    
    TreeNode *dfs(ListNode *left, ListNode *right){
        if(left == right) return NULL;
        
        ListNode *slow = left, *fast = left;
        
        while(fast != right and fast->next != right){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        root->left = dfs(left, slow);
        root->right = dfs(slow->next, right);
        
        return root;
    }
};