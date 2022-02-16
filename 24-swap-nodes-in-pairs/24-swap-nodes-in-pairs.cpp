class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(head->next == NULL) return head;
        ListNode *cur = head;
        while(cur!= NULL and cur->next!= NULL){
            swap(cur->val, cur->next->val);
            cur = cur->next->next;
        }
        return  head;
    }
};