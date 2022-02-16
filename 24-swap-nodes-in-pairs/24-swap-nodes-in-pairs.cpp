class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = head, *cur = head, *last = NULL;
        while(cur != NULL){
            ListNode *a = cur;
            ListNode *b = cur->next;
            if(b == NULL){
                break;
            }
            ListNode *next = cur->next->next;
            if(last == NULL){
                newHead = b;
            }
            else{
                last->next = b;
            }
            a->next = next;
            b->next = a;
            last = a;
            cur = next;
        }
        return newHead;
    }
};