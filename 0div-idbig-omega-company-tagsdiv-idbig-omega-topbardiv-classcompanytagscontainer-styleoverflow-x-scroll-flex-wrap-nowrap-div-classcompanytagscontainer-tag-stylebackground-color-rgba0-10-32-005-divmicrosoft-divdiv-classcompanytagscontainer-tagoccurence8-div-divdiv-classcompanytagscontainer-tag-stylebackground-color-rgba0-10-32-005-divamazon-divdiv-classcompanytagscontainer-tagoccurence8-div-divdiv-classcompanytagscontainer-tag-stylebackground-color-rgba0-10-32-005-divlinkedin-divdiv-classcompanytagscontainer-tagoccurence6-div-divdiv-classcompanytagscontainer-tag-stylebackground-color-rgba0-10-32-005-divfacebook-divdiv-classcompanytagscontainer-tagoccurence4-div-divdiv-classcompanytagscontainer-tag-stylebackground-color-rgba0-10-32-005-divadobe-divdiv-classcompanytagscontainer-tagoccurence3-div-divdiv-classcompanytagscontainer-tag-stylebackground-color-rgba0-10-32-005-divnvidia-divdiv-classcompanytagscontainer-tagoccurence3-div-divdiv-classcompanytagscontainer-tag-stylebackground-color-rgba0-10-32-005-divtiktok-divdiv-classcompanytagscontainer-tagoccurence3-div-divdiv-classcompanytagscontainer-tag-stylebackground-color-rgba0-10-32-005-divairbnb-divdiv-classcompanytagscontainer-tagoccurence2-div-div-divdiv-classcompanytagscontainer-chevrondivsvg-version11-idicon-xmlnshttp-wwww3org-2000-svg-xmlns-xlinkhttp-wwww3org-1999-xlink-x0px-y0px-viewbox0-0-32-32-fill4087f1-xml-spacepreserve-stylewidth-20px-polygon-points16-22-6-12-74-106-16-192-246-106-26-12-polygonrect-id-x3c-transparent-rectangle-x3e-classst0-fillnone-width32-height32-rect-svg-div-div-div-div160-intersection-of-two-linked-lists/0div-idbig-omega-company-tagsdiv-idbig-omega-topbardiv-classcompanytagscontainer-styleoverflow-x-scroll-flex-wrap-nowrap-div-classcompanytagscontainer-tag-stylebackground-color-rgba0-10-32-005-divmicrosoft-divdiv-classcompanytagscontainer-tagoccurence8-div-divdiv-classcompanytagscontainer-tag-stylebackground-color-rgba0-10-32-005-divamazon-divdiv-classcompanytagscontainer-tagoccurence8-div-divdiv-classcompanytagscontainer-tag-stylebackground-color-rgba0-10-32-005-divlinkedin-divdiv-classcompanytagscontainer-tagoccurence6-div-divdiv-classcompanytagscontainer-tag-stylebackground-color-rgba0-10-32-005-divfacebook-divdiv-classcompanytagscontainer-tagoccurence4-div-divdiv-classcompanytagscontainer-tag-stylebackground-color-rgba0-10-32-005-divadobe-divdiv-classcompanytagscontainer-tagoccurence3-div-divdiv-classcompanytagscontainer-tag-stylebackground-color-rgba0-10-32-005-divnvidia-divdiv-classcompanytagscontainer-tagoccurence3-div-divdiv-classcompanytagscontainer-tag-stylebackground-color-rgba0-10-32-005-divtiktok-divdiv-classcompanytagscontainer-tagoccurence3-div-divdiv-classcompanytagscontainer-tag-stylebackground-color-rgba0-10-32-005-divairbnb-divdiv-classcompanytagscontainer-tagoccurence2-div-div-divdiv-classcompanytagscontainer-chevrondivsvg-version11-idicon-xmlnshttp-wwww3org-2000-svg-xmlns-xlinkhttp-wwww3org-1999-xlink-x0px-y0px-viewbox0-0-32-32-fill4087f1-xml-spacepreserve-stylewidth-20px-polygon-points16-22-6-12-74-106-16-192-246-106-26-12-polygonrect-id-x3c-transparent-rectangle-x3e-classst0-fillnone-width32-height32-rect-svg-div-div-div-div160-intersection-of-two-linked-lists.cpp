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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        ListNode *curA = headA, *curB = headB;
        
        while(curA != curB){
            if(curA != nullptr)
                curA = curA->next;
            else
                curA = headB;
            if(curB != nullptr)
                curB = curB->next;
            else
                curB = headA;
        }
        return curA ? curA: nullptr;
    }
};