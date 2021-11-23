class Solution {
public:
    
    int getLength(ListNode* &head){
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int len = getLength(head);
        ListNode *curr = head;
        int i = 1, gp = 1;
        ListNode* prevOfGp = curr;
        while(i <= len){ 
            if(gp&1){ 
                int num = 1;
                while(num<gp && i<=len){ 
                    curr = curr->next;
                    num++;
                    i++;
                }
                prevOfGp = curr; 
                if(i<=len)
                    curr = curr->next;  
            }
            else{
                int totalNodesInGp = gp, cnt = 1;
                ListNode *prev = NULL, *firstOfGp = curr;
                while(curr != NULL && cnt <= totalNodesInGp){
                    ListNode* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    cnt++;
                }
                i += totalNodesInGp-1;
                firstOfGp->next = curr;
                prevOfGp->next = prev;
                prevOfGp = firstOfGp;
            }
            gp++; 
            int remNodes = len - i;  
            if(remNodes < gp){ 
                gp = remNodes;
            }
            i++;
        }
        return head;
    }
};