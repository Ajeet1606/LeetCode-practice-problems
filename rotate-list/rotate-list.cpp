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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(head->next == NULL) return head;
        int len=0;
        ListNode *cur = head;
        while(cur){
            len++;
            cur= cur->next;
        }
        k = k%len;
        while(k--){
            ListNode *curr = head;
            while(curr->next->next != NULL)
                curr = curr->next;
            ListNode *temp = curr->next;
            curr->next = NULL;
            
            temp->next = head;
            head = temp;
        }
        return head;
    }
};