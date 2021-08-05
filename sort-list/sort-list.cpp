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
        if(!head || head->next == NULL) return head;
        vector<int> arr;
        ListNode *curr = head;
        while(curr!=nullptr){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        sort(arr.begin(), arr.end());
        curr = head;
        for(int i = 0; i<arr.size(); i++){
            curr->val = arr[i];
            curr = curr->next;
        }
        return head;
    }
};