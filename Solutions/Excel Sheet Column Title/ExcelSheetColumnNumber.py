class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        sum = 0
        for c in s:
            sum = sum * 26 + (ord(c) - ord('A') + 1)
        return sum

    def converToTitle(self, num):
        a = []
        while num:
            num -= 1
            a.append(chr(num % 26 + 65))
            num /= 26
        return "".join(a[::-1])

if __name__ == "__main__":
    s = Solution()
    tests = ["A", "AZ", "AAA", "AB"]
    for test in tests:
        print s.titleToNumber(test)
    tests2 = [1, 2, 3, 26, 27, 704]
    for test in tests2:
        print s.converToTitle(test)
