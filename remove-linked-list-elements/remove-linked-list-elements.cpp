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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
    ListNode* node = head;
    while(node!=nullptr){
        if(node->val == val){
            if(prev == nullptr){
                head = node->next;
                delete node;
                node = head;
            }else{
                prev->next = node->next;
                
                delete node;
                node = prev->next;
            }
        }else{
            prev = node;
            node = node->next;
        }
    }
    return head;
    }
};