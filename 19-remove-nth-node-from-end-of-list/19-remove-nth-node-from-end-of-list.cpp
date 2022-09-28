/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* front = dummy, *back = dummy;
        while(front != NULL and n--){
            front = front->next;
        }
        
        bool delete_first = true;
        while(front->next != NULL){
            front = front->next;
            back = back->next;
            delete_first = false;
        }
        if(delete_first) return head->next;
        
        back->next = back->next->next;
        return head;
    }
};