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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *curr1 = l1, *curr2 = l2, *curr3=l3;
        int carry=0;
        while(curr1 != nullptr || curr2 != nullptr){
        int a = curr1 ? curr1->val : 0;
        int b = curr2 ? curr2->val : 0;
        int sum = a+b+carry;
        carry = sum/10;
        curr3->next = new ListNode(sum%10);
        curr3 = curr3->next;
        if(curr1 != NULL)
            curr1 = curr1->next;
        if(curr2 != NULL)
            curr2 = curr2->next;
        }
        if(carry > 0)
            curr3->next = new ListNode(carry);
        return l3->next;
    }
};