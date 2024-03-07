# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        c=0
        temp=head;
        while temp:
            c+=1
            temp=temp.next
        x=0
        while x!=c//2:
            head=head.next
            x+=1
        return head