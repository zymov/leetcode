class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0 if n == 0 else nums[0]
        return max(self.robber(nums, 0, n - 2), self.robber(nums, 1, n - 1))

    def robber(self, nums: List[int], start: int, end: int) -> int:
        tmp = pre = s = 0
        for i in range(start, end + 1):
            tmp = s
            if pre + nums[i] > s:
                s = pre + nums[i]
            pre = tmp
        return s
