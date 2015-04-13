import math


class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        if len(num) < 2 or min(num) == max(num):
            return 0
        a = min(num)
        b = max(num)
        size = max(1, int(math.ceil((b - a) / (len(num)-1))))
        bucket = [[None, None] for i in range((b-a)/size + 1)]
        for n in num:
            bucket_index = (n - a) / size
            if bucket[bucket_index][0] is None:
                bucket[bucket_index][0] = n
                bucket[bucket_index][1] = n
            else:
                bucket[bucket_index][0] = min(bucket[bucket_index][0], n)
                bucket[bucket_index][1] = max(bucket[bucket_index][1], n)
        bucket = [bu for bu in bucket if bu[0] is not None]
        print bucket
        return max(bucket[i][0] - bucket[i-1][1] for i in range(1, len(bucket)))

if __name__ == "__main__":
    s = Solution()
    tests = [(3, 4, 1), (1,1,1,1,1,5,5,5,5,5)]
    for test in tests:
        print s.maximumGap(test)
