class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        t = x
        y = 0
        while t:
            y = y*10 + t % 10
            t //= 10
        return x == y
