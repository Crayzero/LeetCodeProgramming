class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1:
            return s
        row = 0
        step = 1
        a = ["" for i in range(nRows)]
        for i in s:
            a[row] += i
            row += step
            if row == nRows-1:
                step = -1
            elif row == 0:
                step = 1
        return "".join(a)

if __name__ == "__main__":
    s = Solution()
    print s.convert("ABC", 1)
    print s.convert("ABC", 2)
    print s.convert("PAYPALISHIRING", 3)
