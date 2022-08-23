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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        
        //reverse the half of the list
        ListNode *reversedHalfMid = reverseHalf(findMid(head));
        
        //now first half & second half will be equal 
        while(reversedHalfMid != NULL and head){
            cout<<reversedHalfMid->val;
            cout<<head->val;
            if(reversedHalfMid->val != head->val)
                return false;
            reversedHalfMid = reversedHalfMid->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode* findMid(ListNode *head){
        if(!head or !head->next) return head;
        ListNode *slow = head, *fast = head;
        while(fast!=NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL)
            slow = slow->next;
        cout<<"slow"<<slow->val<<" ";
        return slow;
    }
    
    ListNode* reverseHalf(ListNode *head){
        if(!head or !head->next) return head;
        ListNode *prev= NULL, *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        cout<<"prev"<<prev->val<<" ";
        return prev;
    }
};