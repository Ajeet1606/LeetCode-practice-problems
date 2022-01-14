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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
ListNode *l4;
l4=l3;
if(!l1)
return l2;
if(!l2)
return l1;

    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            l3->next =  new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            l3->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        l3=l3->next;
    }
    
    while(l1)
    {
        l3->next = new ListNode(l1->val);
        l1 = l1->next;
        l3=l3->next;

    }
    
    while(l2)
    {
       l3->next = new ListNode(l2->val);
       l2 = l2->next;
       l3=l3->next;

    }
    
    return l4->next;
}
};