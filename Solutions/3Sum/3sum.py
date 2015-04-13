# -*- coding: utf-8 -*-
class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        returnlists = []
        # let num be sorted, ....
        num.sort()
        lasta = None
        # let a = num[i], this solution is to find (b + c) = -a
        for i in range(len(num)):
            # use lasta to avoid redundant a
            if num[i] == lasta:
                continue
            # use lastc to avoid redundant c
            lastc = None
            lasta = num[i]
            # this is -a
            nega = 0 - num[i]
            # make a set to store the b, then to find c
            newSet = set()
            # use range(i,..) to avoid (a, b)/(b, a) redundancies.
            for j in range(i, len(num)):
                # skip self
                if j != i:
                    # check if  -a - c is in set
                    theval = nega - num[j]
                    # not in and no repeating, get (a, b, c).
                    if theval in newSet and lastc != num[j]:
                        thislist = [theval, num[i], num[j]]
                        lastc = num[j]
                        thislist.sort()
                        returnlists.append(thislist)
                    # put b in set
                    else:
                        newSet.add(num[j])
                        print newSet
        return returnlists

    def binary_search(self, num, n):
        start = 0
        end = len(num)-1
        while start <= end:
            middle = (start + end)/2
            if num[middle] == n:
                return middle
            elif num[middle] < n:
                start = middle+1
            elif num[middle] > n:
                end = middle-1
        return -1

if __name__ == "__main__":
    s = Solution()
    print s.threeSum([-1, 0, 1, 2, -1, -4])
    print s.threeSum([])
    # print s.threeSum([-7, -5, 5, -6, -2, 1, 7, 3, -4, -2, -2, -4, -8, -1, 8, 8, -2, -7, 3, 2, -7, 8, -3, -10, 5, 2, 8, 7, 7])
    # print s.threeSum([-1, -1, -1, 0, 0, 0, 2, 2])
