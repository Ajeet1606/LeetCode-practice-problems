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
        if(!head or !head->next) return head;
        
        ListNode *curr = head;
        vector<int>small, big;
        while(curr){
            if(curr->val >= x){
                big.push_back(curr->val);
            }
            else{
                small.push_back(curr->val);
            }
            curr = curr->next;
        }
        ListNode *ans = new ListNode(0);
        curr = ans;
        for(auto a: small){
            curr->next = new ListNode(a);
            curr = curr->next;
        }
        for(auto a: big){
            curr->next = new ListNode(a);
            curr = curr->next;
        }
        return ans->next;
    }
};