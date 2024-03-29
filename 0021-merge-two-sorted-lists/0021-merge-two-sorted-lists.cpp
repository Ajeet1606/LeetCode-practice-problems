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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0), *cur = head;
        
        while(list1 != NULL and list2 != NULL){
            if(list1->val <= list2->val){
                cur->next = new ListNode(list1->val);
                cur = cur->next;
                list1 = list1->next;
            }else{
                cur->next = new ListNode(list2->val);
                cur = cur->next;
                list2 = list2->next;
            }
        }
        
        while(list1 != NULL){
            cur->next = new ListNode(list1->val);
            cur = cur->next;
            list1 = list1->next;
        }
        
        while(list2 != nullptr){
            cur->next = new ListNode(list2->val);
            cur = cur->next;
            list2 = list2->next;
        }
        
        return head->next;
    }
};