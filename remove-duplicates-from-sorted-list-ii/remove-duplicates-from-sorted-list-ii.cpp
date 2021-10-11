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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* prev = sentinel;
        bool del = false;
        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    ListNode* temp = head;
                    head = head->next;
                    delete(temp);
                }
                del = true;
                prev->next = head->next;
            }
            else{
                prev = prev->next;
            }
            if(del){
                ListNode* temp = head;
                head = head->next;
                delete(temp);
                del = false;
            }
            else
                head = head->next;
        }
        return sentinel->next;
    }
};