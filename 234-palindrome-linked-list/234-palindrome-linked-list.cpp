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
        vector<int>arr;
        while(head != NULL){
            int val = head->val;
            arr.push_back(val);
            head = head->next;
        }        
        return isPalindrome(arr);
    }
    
    //string taken as reference
    bool isPalindrome(vector<int>&arr){
        int l=0, r = arr.size()-1;
        while(l<r){
            if(arr[l] != arr[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};