class Solution(object):
    def specialArray(self, nums):
        n = len(nums)
        for x in range(n, 0,-1):
            count = sum([i>=x for i in nums])
            if count == x:
                return x
        return -1
            