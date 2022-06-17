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
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *l3 = new ListNode(0);
        ListNode *l4= l3;
        //l4 = l3;
        while(list1 and list2){
            if(list1->val < list2->val){
                l3->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                l3->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            l3 = l3->next;
        }
        
        while(list1){
            l3->next = new ListNode(list1->val);
            list1 = list1->next;
            l3 = l3->next;
        }
        
        while(list2){
            l3->next = new ListNode(list2->val);
            list2 = list2->next;
            l3 = l3->next;
        }
        
        return l4->next;
    }
};