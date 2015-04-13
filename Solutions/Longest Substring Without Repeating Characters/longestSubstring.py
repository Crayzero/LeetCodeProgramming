class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        s = s.strip()
        if not s:
            return 0
        else:
            a = []
            max = 0
            for i in s:
                if i not in a:
                    a.append(i)
                else:
                    if len(a) > max:
                        max = len(a)
                    a = a[a.index(i)+1:]
                    a.append(i)
            if len(a) > max:
                max = len(a)
            return max


if __name__ == "__main__":
    s = Solution()
    print s.lengthOfLongestSubstring("")
    print s.lengthOfLongestSubstring("p")
    print s.lengthOfLongestSubstring("abcabcbb")
    print s.lengthOfLongestSubstring("abc")
    print s.lengthOfLongestSubstring("bbbb")
    print s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco")