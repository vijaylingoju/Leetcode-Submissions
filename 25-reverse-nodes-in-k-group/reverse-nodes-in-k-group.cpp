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
    void reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }
        head = dummy;
    }
    ListNode* findKthNode(ListNode* node, int k){
        k-=1;
        while(k>0 and node){
            node=node->next;
            k-=1;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL, *temp = head;
        while(temp!=NULL){
            ListNode* kthNode = findKthNode(temp,k);
            if(kthNode==NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head = kthNode;
            }else{
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};