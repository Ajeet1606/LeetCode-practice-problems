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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *currA = list1, *currB = list2, *tailA = list1, *tailB = list2;
        b++;
        while(tailB->next != NULL)
            tailB = tailB->next;
        while(b--)
            tailA = tailA->next;
        while(--a)
            currA = currA->next;
        currA->next = currB;
        tailB->next = tailA;
        return list1;
    }
};