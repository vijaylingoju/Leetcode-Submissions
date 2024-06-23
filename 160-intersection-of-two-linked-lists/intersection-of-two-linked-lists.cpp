/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int get_diff(ListNode *headA, ListNode *headB){
        int moves = 0;
        while(headA or headB){
            if(headA){
                moves++;
                headA=headA->next;
            }
            // cout<<moves<<endl;
            if(headB){
                moves--;
                headB=headB->next;
            }
            // cout<<moves<<endl;
        }
        return moves;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = get_diff(headA,headB);
        cout<<diff<<endl;
        if(diff<0){
            while(diff!=0){
                diff+=1;
                headB=headB->next;
            }
        }else{
            while(diff!=0){
                diff-=1;
                headA=headA->next;
            }
        }
        cout<<headA->val<<" "<<headB->val;
        while(headA){
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};