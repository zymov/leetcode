class Solution:
    def isHappy(self, n: int) -> bool:
        slow = self.getSum(n)
        fast = self.getSum(self.getSum(n))
        while slow != fast:
            slow = self.getSum(slow)
            fast = self.getSum(self.getSum(fast))
        return slow == 1

    def getSum(self, n: int) -> int:
        sum = 0
        while n > 0:
            sum += pow(n % 10, 2)
            n //= 10
        return sum
