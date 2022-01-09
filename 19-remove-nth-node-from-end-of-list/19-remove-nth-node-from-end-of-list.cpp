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
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        ListNode *slow=head, *fast=head;
        while(n--)
            fast=fast->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        if(fast==NULL){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
        }
        else{
            ListNode *temp = slow->next;
            slow->next = slow->next->next;
            delete(temp);
        }
        return head;
    }
};