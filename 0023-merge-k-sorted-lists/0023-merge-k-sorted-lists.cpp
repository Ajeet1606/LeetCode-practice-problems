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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        
        for(auto list: lists){
            while(list != NULL){
                arr.push_back(list->val);
                list = list->next;
            }
        }
        int n = arr.size();
        if(n == 0) return NULL;
        sort(arr.begin(), arr.end());
        
        ListNode *head = new ListNode(arr[0]), *cur = head;
        for(int i=1; i < n; i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        
        return head;
    }
};