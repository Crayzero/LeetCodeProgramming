class Solution:
    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        dic = {}
        res = []
        res_first = 0
        prefix = ''
        if numerator * denominator < 0:
            prefix = "-"
        numerator = abs(numerator)
        denominator = abs(denominator)
        if numerator > denominator:
            res_first = numerator / denominator
            numerator %= denominator
        while numerator not in dic.keys() and numerator:
            numerator *= 10
            res.append(numerator / denominator)
            dic[numerator/10] = len(res) - 1
            numerator = numerator % denominator
        res2 = 0
        print res
        if len(res) == 0:
            return prefix + str(res_first)
        if not numerator:
            res2 = "".join(str(c) for c in res[:])
            return prefix + str(res_first) + '.' + res2
        else:
            repeat = dic[numerator]
            res2 = "".join(str(c) for c in res[:repeat])
            res_rest = "".join([str(c) for c in res[repeat:]])
            dot = '.'
            return prefix + str(res_first) + dot + res2 + "(" + res_rest + ")"

if __name__ == "__main__":
    s = Solution()
    tests = [(1, 2), (2, 1), (0, 3), (7, 3), (1, 90), (-22, -2), (-2, 3), (1, 214748364), (-1, -2147483648)]
    for test in tests:
        print s.fractionToDecimal(*test)
