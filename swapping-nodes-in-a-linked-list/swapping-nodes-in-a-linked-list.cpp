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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || head->next == NULL) return head;
        ListNode *start = head, *end = head;
        int i = 1, n = 1;
        while(end->next){
            if(n < k)
                start = start->next;
            end = end->next; 
            n++;
        }
        end = head;
        while(i <= n - k){
            end = end->next;
            i++;
        }
        swap(start->val, end->val);
        return head;
    }
};