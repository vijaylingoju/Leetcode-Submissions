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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*a=head,*b=head;
        int rem = n;
        while(n--){
            b=b->next;
        }
        if (b == NULL) {
            return head->next;
        }
        while(b->next!=NULL){
            a=a->next;
            b=b->next;
        }
        ListNode* temp = a->next;
        a->next = a->next->next;
        return head;
    }
};