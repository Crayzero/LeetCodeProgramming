class Solution:
    # @return an integer
    def reverse(self, x):
        negative = False
        if x < 0:
            negative = True
        x1 = abs(x)
        x1_s = str(x1)
        a = []
        for i in x1_s:
            a.insert(0, i)
        x2_s = "".join(a)
        x2 = int(x2_s)
        if x2 >> 31 != 0:
            return 0
        if negative:
            x2 = -x2
        return x2

if __name__ == "__main__":
    s = Solution()
    print s.reverse(1230)
    print s.reverse(-123)
    print s.reverse(1000000003)
