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
        string s = "";
        while(head != NULL){
            int val = head->val;
            char c = val+ '0';
            s.push_back(c);
            head = head->next;
        }        
        return isPalindrome(s);
    }
    
    //string taken as reference
    bool isPalindrome(string& s){
        int l=0, r = s.length()-1;
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};