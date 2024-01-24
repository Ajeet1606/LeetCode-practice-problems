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
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *slow = newHead, *fast = newHead;
        int count = 0;
        while(fast != NULL && count < n){
            fast = fast->next;
            count++;
        }
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};