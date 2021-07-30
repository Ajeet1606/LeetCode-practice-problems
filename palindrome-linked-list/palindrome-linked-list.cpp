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
        if (head == NULL || head->next == NULL) return true;
        
        // Find middle & reverse 2nd half of the list
        ListNode* reversed2ndHalf = reverseList(findMiddle(head));
        
        // Verify palindrome property
        while (reversed2ndHalf != NULL && head)
        {
            if (reversed2ndHalf->val != head->val)
                return false;
            
            reversed2ndHalf = reversed2ndHalf->next;
            head = head->next;
        }
        
        return true;
    }
    
private:
    ListNode* findMiddle(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head; ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast != NULL) slow = slow->next;
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        while (head != NULL)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};