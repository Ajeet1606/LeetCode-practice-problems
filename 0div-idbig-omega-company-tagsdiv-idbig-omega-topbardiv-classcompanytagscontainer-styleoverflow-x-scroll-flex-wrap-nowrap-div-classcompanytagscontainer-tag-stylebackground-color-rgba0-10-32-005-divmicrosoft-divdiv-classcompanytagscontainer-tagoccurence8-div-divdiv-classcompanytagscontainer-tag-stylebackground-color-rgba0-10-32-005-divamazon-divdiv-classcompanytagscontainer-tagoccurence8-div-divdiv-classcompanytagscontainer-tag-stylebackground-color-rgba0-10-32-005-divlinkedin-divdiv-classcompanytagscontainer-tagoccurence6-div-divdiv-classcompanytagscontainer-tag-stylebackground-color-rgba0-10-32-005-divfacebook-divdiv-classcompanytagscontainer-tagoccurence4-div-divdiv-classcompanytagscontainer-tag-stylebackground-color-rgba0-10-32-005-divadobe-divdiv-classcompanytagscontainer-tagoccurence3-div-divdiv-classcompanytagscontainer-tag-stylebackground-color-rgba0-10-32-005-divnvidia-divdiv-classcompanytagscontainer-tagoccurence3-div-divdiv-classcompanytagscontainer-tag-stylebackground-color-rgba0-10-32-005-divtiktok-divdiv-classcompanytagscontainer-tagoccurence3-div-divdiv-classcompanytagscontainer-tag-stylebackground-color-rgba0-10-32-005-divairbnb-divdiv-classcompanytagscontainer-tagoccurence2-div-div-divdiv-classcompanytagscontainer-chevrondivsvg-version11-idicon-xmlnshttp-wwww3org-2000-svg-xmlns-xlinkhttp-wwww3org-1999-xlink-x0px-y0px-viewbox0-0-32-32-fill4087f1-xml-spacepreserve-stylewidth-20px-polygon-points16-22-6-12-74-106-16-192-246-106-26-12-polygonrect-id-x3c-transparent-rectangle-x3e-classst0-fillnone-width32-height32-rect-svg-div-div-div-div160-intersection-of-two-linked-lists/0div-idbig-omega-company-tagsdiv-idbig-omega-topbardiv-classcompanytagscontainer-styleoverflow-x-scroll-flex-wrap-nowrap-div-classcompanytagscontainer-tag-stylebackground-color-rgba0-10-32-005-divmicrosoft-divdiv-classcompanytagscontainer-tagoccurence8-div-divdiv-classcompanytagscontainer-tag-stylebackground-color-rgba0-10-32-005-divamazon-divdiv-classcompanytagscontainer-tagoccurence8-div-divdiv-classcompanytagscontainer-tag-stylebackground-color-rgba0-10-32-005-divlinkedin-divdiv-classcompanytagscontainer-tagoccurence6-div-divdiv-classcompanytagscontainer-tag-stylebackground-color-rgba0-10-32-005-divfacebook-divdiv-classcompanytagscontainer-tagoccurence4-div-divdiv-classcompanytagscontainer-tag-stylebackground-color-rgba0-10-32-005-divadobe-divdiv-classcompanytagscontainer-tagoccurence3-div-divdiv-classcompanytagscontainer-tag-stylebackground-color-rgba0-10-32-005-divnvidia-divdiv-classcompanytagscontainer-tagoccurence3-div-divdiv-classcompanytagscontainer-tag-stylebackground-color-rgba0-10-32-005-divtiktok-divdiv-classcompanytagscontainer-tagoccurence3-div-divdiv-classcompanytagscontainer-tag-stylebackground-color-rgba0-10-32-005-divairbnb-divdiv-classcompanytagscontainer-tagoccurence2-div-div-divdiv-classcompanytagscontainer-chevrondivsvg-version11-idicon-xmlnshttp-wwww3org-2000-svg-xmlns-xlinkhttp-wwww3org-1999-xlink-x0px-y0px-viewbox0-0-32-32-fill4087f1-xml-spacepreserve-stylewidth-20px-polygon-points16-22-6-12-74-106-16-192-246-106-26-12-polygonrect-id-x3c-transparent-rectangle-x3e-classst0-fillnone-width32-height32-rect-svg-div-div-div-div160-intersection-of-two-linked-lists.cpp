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
        int len1 = 0, len2 = 0;
        
        ListNode *cur = headA;
        while(cur != NULL){
            len1++;
            cur = cur->next;
        }
        
        cur = headB;
        while(cur != NULL){
            len2++;
            cur = cur->next;
        }
        
        if(len1 < len2){
            swap(headA, headB);
            swap(len1, len2);
        }
        int diff = len1 - len2;
        
        ListNode *curA = headA, *curB = headB;
        while(diff--){
            curA = curA->next;
        }
        
        while(curA != nullptr and curB != nullptr){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};