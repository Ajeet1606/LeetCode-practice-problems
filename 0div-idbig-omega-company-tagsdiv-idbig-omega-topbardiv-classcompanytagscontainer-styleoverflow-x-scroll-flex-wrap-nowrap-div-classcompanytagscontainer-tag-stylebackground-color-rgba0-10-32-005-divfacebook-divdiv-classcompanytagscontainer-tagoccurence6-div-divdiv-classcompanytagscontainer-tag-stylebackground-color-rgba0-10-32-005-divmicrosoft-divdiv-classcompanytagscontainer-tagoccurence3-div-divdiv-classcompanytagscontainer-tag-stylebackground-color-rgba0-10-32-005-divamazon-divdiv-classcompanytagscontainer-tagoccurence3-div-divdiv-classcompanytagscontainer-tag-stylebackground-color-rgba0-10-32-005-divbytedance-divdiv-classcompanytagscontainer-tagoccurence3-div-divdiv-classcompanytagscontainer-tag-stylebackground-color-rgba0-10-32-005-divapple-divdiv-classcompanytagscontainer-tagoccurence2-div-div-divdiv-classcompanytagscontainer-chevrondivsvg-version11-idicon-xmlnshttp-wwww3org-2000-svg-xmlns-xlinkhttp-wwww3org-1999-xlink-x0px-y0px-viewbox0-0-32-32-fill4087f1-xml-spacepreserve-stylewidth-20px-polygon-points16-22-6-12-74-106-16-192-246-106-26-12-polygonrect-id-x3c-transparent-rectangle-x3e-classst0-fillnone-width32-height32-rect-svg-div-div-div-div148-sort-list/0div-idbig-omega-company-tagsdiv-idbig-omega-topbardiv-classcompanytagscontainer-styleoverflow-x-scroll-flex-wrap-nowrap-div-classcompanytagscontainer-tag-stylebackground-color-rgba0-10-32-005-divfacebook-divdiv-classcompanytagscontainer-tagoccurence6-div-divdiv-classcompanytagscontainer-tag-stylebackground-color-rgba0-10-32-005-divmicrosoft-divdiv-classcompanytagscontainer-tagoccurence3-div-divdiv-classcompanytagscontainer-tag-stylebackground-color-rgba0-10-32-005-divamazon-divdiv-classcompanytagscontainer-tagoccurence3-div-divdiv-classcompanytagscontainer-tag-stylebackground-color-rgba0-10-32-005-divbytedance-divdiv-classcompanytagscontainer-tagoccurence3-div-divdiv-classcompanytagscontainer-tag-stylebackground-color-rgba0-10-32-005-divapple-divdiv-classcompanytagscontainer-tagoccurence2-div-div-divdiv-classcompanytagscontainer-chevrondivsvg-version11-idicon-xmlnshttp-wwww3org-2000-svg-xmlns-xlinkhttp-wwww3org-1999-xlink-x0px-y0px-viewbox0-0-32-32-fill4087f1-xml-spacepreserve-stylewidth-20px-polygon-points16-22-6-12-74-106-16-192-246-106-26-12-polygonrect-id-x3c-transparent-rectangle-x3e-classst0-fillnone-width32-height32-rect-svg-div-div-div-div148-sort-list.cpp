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
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head, *fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *merge(ListNode *leftHead, ListNode *rightHead){
        ListNode *resultHead = new ListNode(0), *cur = resultHead;
        ListNode *curLeft = leftHead, *curRight = rightHead;
        
        while(curLeft && curRight){
            if(curLeft->val <= curRight->val){
                cur->next = curLeft;
                curLeft= curLeft->next;
            }else{
                cur->next = curRight;
                curRight = curRight->next;
            }
            cur = cur->next;
        }
        if(curLeft) cur->next = curLeft;
        else cur->next = curRight;
        
        return resultHead->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head or head->next == NULL) return head;
        
        ListNode *mid = findMiddle(head);
        ListNode *left = head, *right = mid->next;
        mid->next = nullptr;
        
        left = sortList(left);
        right = sortList(right);
        
        return merge(left, right);
    }
};