//slow and fast pointer
//old version of site
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy, *fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;
    }
};