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

//-------------------------------------- TWO PASS ------------------------------------------------>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        //calculate length of list
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
      
        //find target node number
        int node_number_from_start = len - n + 1;
        //if it's head, delete this
        if(node_number_from_start == 1){
            return head->next;
        }
        //move to nearest of target node
        curr = head;
        int i=2; 
        while(i< node_number_from_start){
            curr = curr->next;
            i++;
        }
        //update that with next of target
        curr->next = curr->next->next;
        return head;
    }
};




//---------------------------------------ONE PASS----------------------------------------------------->
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //add a dummy node in starting.
        ListNode* dummy = new ListNode(0);
        //connect with head
        dummy->next = head;
        //we start from dummy
        ListNode* front = dummy, *back = dummy;
        //move front pointer n steps
        while(front != NULL and n--){
            front = front->next;
        }
        //now, untill front reaches last node, we move back with it, if it is already reached, means head is to deleted, return head->next.
        bool delete_first = true;   //flag to check if head is deleted
        while(front->next != NULL){
            front = front->next;
            back = back->next;
            delete_first = false;
        }
        //head deleted condition
        if(delete_first) return head->next;
        //remove targeted node
        back->next = back->next->next;
        return head;
    }
};
