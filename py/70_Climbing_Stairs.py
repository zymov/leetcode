class Solution:
    def climbStairs(self, n: int) -> int:
        step_a, step_b, step_c = 0, 1, 0
        for i in range(n):
            step_c = step_a + step_b
            step_a = step_b
            step_b = step_c
        return step_c
            