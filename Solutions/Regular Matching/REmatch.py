class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        print s, p
        if len(p) == 0:
            if len(s) == 0:
                return True
            else:
                return False
        if len(s) != 0:
            last_p = p[-1]
            last_s = s[-1]
            if last_p != "." and last_p != "*" and last_p != last_s:
                return False
        if len(p) == 1 or p[1] != "*":
            if len(s) == 0 or (p[0] != "." and s[0] != p[0]):
                return False
            return self.isMatch(s[1:], p[1:])
        else:
            i = 0
            for i in range(len(s)+1):
                if p[0] == "." or i == 0 or p[0] == s[i-1]:
                    if self.isMatch(s[i:], p[2:]):
                        return True
                else:
                    return False
        return False

if __name__ == "__main__":
    s = Solution()
    print s.isMatch("ab", ".*c")
    print s.isMatch("a", "ab*")
    print s.isMatch("aaa", "a.*")
    print s.isMatch("aaa", "aa*")
    print s.isMatch("aaab", "a.*")
    print s.isMatch("aab", "a*a*c")
