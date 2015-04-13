class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        size = len(num) - 1
        if size == 0:
            return 0
        if num[0] > num[1]:
            return 0
        if num[size] > num[size-1]:
            return size
        return self.findPeak(num, 0, len(num)-1)

    def findPeak(self, num, left, right):
        print num[left: right+1]
        if right-left < 2:
            return -1
        center = (left + right) / 2
        if num[center] > num[center-1] and num[center] > num[center+1]:
            return center
        r_left = self.findPeak(num, left, center)
        if r_left >= 0:
            return r_left
        r_right = self.findPeak(num, center, right)
        if r_right >= 0:
            return r_right
        return -1


if __name__ == "__main__":
    s = Solution()
    tests = [(1,), (1, 2, 3, 1, 4), (1, 2, 3)]
    for test in tests:
        print s.findPeakElement(test)
