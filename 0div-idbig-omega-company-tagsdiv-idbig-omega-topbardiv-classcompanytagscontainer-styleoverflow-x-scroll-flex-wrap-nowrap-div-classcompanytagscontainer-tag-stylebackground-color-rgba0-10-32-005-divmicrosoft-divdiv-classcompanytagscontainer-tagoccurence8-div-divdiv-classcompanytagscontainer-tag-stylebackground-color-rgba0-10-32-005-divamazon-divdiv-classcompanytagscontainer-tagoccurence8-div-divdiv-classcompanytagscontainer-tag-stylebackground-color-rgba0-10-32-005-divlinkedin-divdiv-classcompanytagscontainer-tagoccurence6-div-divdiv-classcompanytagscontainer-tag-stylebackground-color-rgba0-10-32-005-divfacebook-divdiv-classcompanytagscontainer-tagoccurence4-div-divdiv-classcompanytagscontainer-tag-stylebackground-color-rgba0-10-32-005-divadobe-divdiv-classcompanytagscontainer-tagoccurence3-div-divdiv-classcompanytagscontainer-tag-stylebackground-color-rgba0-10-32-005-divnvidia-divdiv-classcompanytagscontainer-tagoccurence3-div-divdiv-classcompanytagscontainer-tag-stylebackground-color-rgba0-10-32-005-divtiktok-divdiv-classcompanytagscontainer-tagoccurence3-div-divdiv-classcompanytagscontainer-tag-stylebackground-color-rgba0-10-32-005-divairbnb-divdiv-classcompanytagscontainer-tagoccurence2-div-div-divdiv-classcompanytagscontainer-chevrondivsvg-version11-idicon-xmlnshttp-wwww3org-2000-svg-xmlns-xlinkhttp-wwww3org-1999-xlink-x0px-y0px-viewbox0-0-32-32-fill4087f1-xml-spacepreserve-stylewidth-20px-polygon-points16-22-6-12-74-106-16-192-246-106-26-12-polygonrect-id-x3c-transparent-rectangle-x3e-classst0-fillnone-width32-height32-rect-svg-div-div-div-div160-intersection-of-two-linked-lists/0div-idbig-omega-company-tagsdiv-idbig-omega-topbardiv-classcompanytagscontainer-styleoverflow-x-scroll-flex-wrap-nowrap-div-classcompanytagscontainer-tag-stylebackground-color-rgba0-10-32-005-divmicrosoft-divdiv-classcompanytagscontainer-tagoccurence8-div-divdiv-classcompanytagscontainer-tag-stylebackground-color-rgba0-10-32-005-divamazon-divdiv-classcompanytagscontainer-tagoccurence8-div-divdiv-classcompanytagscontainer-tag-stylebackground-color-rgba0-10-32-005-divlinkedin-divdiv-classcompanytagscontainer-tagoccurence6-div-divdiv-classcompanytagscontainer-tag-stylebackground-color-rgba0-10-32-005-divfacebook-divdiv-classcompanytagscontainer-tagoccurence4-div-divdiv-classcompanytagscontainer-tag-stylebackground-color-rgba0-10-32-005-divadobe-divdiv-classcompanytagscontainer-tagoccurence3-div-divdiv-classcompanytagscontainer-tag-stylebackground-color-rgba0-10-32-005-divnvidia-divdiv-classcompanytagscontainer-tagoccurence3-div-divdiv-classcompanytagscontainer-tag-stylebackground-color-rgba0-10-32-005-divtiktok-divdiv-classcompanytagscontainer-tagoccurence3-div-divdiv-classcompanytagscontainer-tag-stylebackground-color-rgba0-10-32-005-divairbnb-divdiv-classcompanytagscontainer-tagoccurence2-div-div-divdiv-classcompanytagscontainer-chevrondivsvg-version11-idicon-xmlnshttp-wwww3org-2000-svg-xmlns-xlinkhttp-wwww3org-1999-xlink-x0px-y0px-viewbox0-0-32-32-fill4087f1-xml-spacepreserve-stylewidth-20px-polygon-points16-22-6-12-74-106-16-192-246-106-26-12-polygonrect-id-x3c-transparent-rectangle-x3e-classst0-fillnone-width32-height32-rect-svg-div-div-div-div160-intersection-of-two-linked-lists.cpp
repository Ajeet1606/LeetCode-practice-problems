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
        unordered_set<ListNode*>s;
        
        ListNode *cur = headA;
        while(cur != NULL){
            s.insert(cur);
            cur = cur->next;
        }
        
        cur = headB;
        while(cur != NULL){
            if(s.count(cur) == 1) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};