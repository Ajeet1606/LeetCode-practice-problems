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
    ListNode* sortList(ListNode* head) {
        ListNode *cur = head;
        vector<int>a;
        while(cur != NULL){
            a.push_back(cur->val);
            cur = cur->next;
        }
        sort(a.begin(), a.end());
        cur = head;
        for(auto i: a){
            cur->val = i;
            cur = cur->next;
        }
        
        return head;
    }
};