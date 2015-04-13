class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        result = strs[0]
        for i in strs:
            result = self.commonPrefix(result, i)
        return result

    def commonPrefix(self, a, b):
        for i in range(min(len(a), len(b))):
            if a[i] != b[i]:
                return a[:i]
        else:
            if len(a) <= len(b):
                return a
            else:
                return b

if __name__ == "__main__":
    s = Solution()
    print s.longestCommonPrefix(["a", "a", ""])
