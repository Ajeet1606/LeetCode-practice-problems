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
    ListNode* partition(ListNode* head, int x) {
        //if list have 0 or 1 node, we don't have to do anything.
        if(!head or !head->next) return head;
        //small will be a list of smaller nodes and big for bigger nodes
        ListNode *small = new ListNode(0), *big = new ListNode(0);
        //small_runner will create small list and big_runner will big.
        ListNode *small_runner = small, *big_runner = big;
        //traverse given list.
        while(head){
            //smaller nodes will go in small list.
            if(head->val < x){
                small_runner->next = head;
                small_runner = small_runner->next;
            }
            //bigger ones to big list.
            else{
                big_runner->next = head;
                big_runner = big_runner->next;
            }
            //go to next.
            head = head->next;
        }
        //big will be added in the end part so it's last node will go for NULL. 
        big_runner->next = NULL;
        //small list is added first so it's last is connected to big and skip 0 that we created in beginning. 
        small_runner->next = big->next;
        //return small and skip 0 that we created in beginning. 
        return small->next;
    }
    
};