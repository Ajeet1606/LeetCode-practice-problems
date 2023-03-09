/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //if there is no node or 1 node, no loop is possible.
        if(!head or !head->next) return NULL;
        
        ListNode *slow = head, *fast = head, *entry = head;
        
        while(fast-> next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(entry != slow){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }
};