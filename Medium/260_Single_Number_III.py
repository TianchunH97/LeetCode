# LeetCode 260: Single Number III

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        dic = {}
        for num in nums:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1
        for i in dic:
            if dic[i] == 1:
                ret.append(i)
        return ret