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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode*newhead = reverseList(slow);
        // cout<<newhead->val<<endl;
        fast = head;
        while(fast and newhead){

            if(fast->val != newhead->val){
                return false;
            }
            fast=fast->next;
            newhead = newhead->next;
        }
        return true;
    }
};