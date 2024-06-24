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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        ListNode*temp = head;
        int n = 0;
        while(temp->next){
            n+=1;
            temp=temp->next;
        }
        n+=1;

        k = k % n;
        if(k==0)return head;
        k = n - k;
        
        ListNode*move = head;
        k-=1;
        while(k!=0){
            move=move->next;
            k-=1;
        }
        ListNode*x = move->next;
        move->next = NULL;
        temp->next = head;
        head = x;
        return head;
    }
};