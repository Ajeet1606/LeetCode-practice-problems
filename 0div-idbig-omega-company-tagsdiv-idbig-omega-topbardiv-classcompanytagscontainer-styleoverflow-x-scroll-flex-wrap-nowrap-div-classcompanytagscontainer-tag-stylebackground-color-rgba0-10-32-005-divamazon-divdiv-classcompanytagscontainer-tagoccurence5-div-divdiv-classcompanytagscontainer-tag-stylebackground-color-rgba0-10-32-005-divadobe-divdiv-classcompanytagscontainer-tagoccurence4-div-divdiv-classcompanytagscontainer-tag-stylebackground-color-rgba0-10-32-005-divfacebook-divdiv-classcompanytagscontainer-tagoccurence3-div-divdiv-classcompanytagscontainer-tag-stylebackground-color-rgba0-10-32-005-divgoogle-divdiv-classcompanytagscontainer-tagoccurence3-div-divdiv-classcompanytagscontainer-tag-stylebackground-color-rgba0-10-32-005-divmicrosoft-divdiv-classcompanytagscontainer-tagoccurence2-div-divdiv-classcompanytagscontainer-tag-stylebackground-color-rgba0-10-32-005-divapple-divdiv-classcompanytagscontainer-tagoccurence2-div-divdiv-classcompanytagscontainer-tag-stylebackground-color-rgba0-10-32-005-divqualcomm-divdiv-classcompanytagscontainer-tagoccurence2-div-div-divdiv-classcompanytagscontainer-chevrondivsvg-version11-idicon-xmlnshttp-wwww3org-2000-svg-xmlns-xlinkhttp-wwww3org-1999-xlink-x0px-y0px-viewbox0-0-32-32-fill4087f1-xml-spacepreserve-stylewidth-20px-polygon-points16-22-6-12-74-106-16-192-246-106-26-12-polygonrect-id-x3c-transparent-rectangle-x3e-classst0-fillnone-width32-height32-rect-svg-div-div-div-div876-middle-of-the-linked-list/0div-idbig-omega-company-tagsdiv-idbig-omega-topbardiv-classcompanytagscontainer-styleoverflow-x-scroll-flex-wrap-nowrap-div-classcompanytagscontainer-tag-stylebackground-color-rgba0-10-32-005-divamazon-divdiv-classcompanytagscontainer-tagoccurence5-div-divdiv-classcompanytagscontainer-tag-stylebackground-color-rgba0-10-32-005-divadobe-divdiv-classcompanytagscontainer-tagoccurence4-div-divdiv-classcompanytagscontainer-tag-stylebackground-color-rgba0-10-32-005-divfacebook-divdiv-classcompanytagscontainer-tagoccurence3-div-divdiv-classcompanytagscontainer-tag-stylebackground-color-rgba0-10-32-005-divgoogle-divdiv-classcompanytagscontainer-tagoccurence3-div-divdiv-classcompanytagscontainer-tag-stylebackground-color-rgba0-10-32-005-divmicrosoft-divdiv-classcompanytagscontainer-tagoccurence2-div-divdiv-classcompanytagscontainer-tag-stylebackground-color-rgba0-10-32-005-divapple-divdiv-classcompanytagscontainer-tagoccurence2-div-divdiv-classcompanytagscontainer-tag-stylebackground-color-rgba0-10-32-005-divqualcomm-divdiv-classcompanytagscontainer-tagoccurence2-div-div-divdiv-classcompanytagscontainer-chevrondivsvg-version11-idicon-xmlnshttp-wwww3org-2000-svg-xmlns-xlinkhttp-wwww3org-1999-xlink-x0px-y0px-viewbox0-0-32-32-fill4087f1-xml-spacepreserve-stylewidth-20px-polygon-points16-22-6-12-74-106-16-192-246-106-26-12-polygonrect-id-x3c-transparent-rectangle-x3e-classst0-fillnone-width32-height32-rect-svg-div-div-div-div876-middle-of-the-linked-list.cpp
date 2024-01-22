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
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        int cnt = 0;
        ListNode *itr = head;
        while(itr != NULL){
            itr = itr->next;
            cnt++;
        }
        
        int mid = 1;
        itr = head;
        
        while(itr != NULL and mid <= cnt/2){
            mid++;
            itr = itr->next;
        }
        return itr;
    }
};