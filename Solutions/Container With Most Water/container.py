class Solution:
    # @return an integer
    def maxArea(self, height):
        start = 0
        end = len(height)-1
        maxArea = 0
        while start <= end:
            height_tmp = min(height[start], height[end])
            area_tmp = height_tmp * (end - start)
            if area_tmp > maxArea:
                maxArea = area_tmp
            if height[start] <= height[end]:
                start += 1
            else:
                end -= 1
        return maxArea

if __name__ == "__main__":
    s = Solution()
    print s.maxArea([1, 2, 1])
    print s.maxArea([2, 1, 3])
    print s.maxArea([2, 3, 2])
    print s.maxArea([2, 3, 1, 2])
