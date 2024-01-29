
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return head;
        ListNode *evenHead = head->next, *slow = head, *fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow->next = slow->next->next;
            slow = slow->next;
            if(fast->next->next != NULL){
                fast->next = fast->next->next;
                fast = fast->next;
            }else{
                fast->next = NULL;
            }
        }
       
        slow->next= evenHead;
        return head;
    }
};