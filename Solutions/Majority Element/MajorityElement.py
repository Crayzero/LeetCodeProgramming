class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        result = num[0]
        count = 0
        for i in num:
            if count == 0 or i == result:
                count += 1
                result = i
            else:
                count -= 1
        return result

if __name__ == "__main__":
    s = Solution()
    num = [1, 0, 1]
    print s.majorityElement(num)
