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
        vector<int>arr;
        ListNode *cur = head;
        while(cur != nullptr){
            arr.push_back(cur->val);
            cur = cur->next;
        }
        
        sort(arr.begin(), arr.end());
        cur = head;
        
        for(int i=0; i<arr.size(); i++){
            cur->val = arr[i];
            cur = cur->next;
        }
        return head;
    }
};