class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        version1 = [int(v) for v in version1.split(".")]
        version2 = [int(v) for v in version2.split(".")]
        len_min = min(len(version1), len(version2))
        for i in range(len_min):
            if (version1[i] < version2[i]):
                return -1
            elif version1[i] > version2[i]:
                return 1
        else:
            if len(version1) > len_min:
                if any(version1[len_min:]):
                    return 1
            if len(version2) > len_min:
                if any(version2[len_min:]):
                    return -1
        return 0

if __name__ == "__main__":
    s = Solution()
    tests = [("1.0", "1"), ("1.2", "13.37"), ("1.2.1", "1.2"), ("1.2", "1.2")]
    for test in tests:
        print s.compareVersion(*test)
