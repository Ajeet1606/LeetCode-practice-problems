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
    ListNode* partition(ListNode* head, int x) {
        //if list have 0 or 1 node, we don't have to do anything.
        if(!head or !head->next) return head;
        // we'll make a new list ans, run will create it..
        ListNode *curr = head, *ans = new ListNode(0), *run = ans;
        //first pick smaller elements.
        while(curr){
            if(curr->val < x){
                run->next = new ListNode(curr->val);
                run = run->next;
            }
            curr = curr->next;
        }
        //restart.
        curr = head;
        //new pick greater ones.
        while(curr){
            if(curr->val >= x){
                run->next = new ListNode(curr->val);
                run = run->next;
            }
            curr = curr->next;
        }
        //skip 0 that we made, return rest.
        return ans->next;
    }
    
};