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
        int len = 0;
        ListNode* curr = head;
        
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
      
        
        int node_number_from_start = len - n + 1;
        if(node_number_from_start == 1){
            return head->next;
        }
        curr = head;
        int i=2; 
        while(i< node_number_from_start){
            curr = curr->next;
            i++;
        }
        
        curr->next = curr->next->next;
        return head;
    }
};