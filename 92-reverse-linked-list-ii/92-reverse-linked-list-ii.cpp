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
    ListNode*end;
    
    ListNode* reverse(ListNode* head, int left, int right){
        //prev pointer to store previous data.
        ListNode* prev = NULL;
        //we'll reverse until we reach end or null first.
        while(head and left <= right){
            cout<<head->val;
            ListNode *next = head->next;
            //next stores the addres of head next cz head next is changing so that we don't lose the connection of further list.
            head->next = prev;
            //prev comes to head.
            prev = head;
            //head goes to next.
            head = next;
            left++;
        }
        end = head;
        cout<<prev->val;
        //at last head becomes end and prev becomes head of reversed list..
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //if list have single node.
        if(left == right) return head;
        //we've to reverse a part of list so, something may be left before and after that part. we add a dummy node to have something before in case reverse part starts from head.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        //curr will traverse the list.
        ListNode *curr = dummy;
        //we've to reach the last node of starting part.
        int cnt = 0;
        while(curr and cnt < left-1){
            curr = curr->next;
            cnt++;
        }
        //start is the last node.
        ListNode* start = curr;
        //tail is the first node of reversible part, which later becomes last.
        ListNode *tail = curr->next;
        //so after start node, we need to reverse nodes upto right position starting from left.
        start->next = reverse(tail, left, right);
        //now tail is last, it'll connect the remaining part of list with itself.
        tail->next = end;
        return dummy->next;
    }
};