

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp_dict = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in tmp_dict:
                res = i > tmp_dict[m] and [tmp_dict[m], i] or [i, tmp_dict[m]]
                return res
            else:
                tmp_dict[n] = i

if __name__ == "__main__":
    solu = Solution()
    print solu.twoSum([3, 2, 4], 6)
