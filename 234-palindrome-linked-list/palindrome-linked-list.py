# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        ls=[]
        while head.next:
            ls.append(head.val)
            head=head.next
        ls.append(head.val)    
        return ls==ls[::-1]