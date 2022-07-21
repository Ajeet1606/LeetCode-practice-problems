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
        //at last head becomes end and prev becomes head of reversed list..
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //if list have single node.
        if(left == right) return head;
        ListNode *curr = head;
        ListNode *tail;
        
        if(left == 1){
            tail = curr;
            head = reverse(tail, left, right);
        }else{
            int cnt = 1;
            while(curr and cnt < left-1){
                curr = curr->next;
                cnt++;
            }
            ListNode* start = curr;
            tail = curr->next;
            start->next = reverse(tail, left, right);
        }
        tail->next = end;
        
        return head;
    }
};