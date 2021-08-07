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
    void reorderList(ListNode* head) {
         if ((!head) || (!head->next) || (!head->next->next)) return;
        
        stack<ListNode*> mystack;
        ListNode* curr = head;
        int size = 0;
        while (curr != NULL) 
        {
            mystack.push(curr);
            size++;
            curr = curr->next;
        }
        
        ListNode* ptr = head;
        for (int j=0; j<size/2; j++) 
        {
            ListNode *element = mystack.top();
            mystack.pop();
            element->next = ptr->next;
            ptr->next = element;
            ptr = ptr->next->next;
        }
        ptr->next = NULL;
    }
    
};