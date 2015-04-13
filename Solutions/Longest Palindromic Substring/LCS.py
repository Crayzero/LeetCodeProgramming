# coding= utf-8
class Solution:
    # @return a string
    def longestPalindrome(self, s):
        return self.LCS2(s, s[::-1])

#   最长公共子序列
    def LCS(self, s, t):
        dp = [[0 for j in range(len(t)+1)] for i in range(len(s)+1)]
        for i in range(len(s)):
            for j in range(len(t)):
                if s[i] == t[j]:
                    dp[i+1][j+1] = dp[i][j]+1
                else:
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
        return dp[len(s)][len(t)]

#   最长公共子串
    def LCS2(self, s, t):
        dp = [[0 for j in range(len(t)+1)] for i in range(len(s)+1)]
        for i in xrange(len(s)):
            for j in xrange(len(t)):
                if s[i] == t[j]:
                    dp[i+1][j+1] = dp[i][j]+1
                else:
                    dp[i+1][j+1] = 0
        return max([max(i) for i in dp])

#   Manacher’s Algorithm
    def LCS3(self, s):
        s2 = self.preprocess(s)
        P = [0 for i in range(len(s2))]
        C = 0
        R = 0
        for i in xrange(1, len(s2)-1):
            mirror = 2*C - i
            if R > i:
                P[i] = min(R-i, P[mirror])
            else:
                P[i] = 0
            while s2[i+P[i]+1] == s2[i-P[i]-1]:
                P[i] += 1
            if i+P[i] > R:
                C = i
                R = i + P[i]

        max_len = max(P)
        center_index = P.index(max_len)
        return s[(center_index-max_len)/2: (center_index+max_len)/2]

#   preprocess the string before Manacher’s Algorithm
    def preprocess(self, s):
        a = [i for i in s]
        s2 = "#".join(a)
        s3 = "$#" + s2 + "#^"
        return s3

if __name__ == "__main__":
    s = Solution()
    print s.LCS("abcd", "becd")
    print s.longestPalindrome("acav")
    print s.LCS3("a")
    print s.LCS3("acav")
    a ="cyyoacmjwjubfkzrrbvquqkwhsxvmytmjvbborrtoiyotobzjmohpadfrvmxuagbdczsjuekjrmcwyaovpiogspbslcppxojgbfxhtsxmecgqjfuvahzpgprscjwwutwoiksegfreortttdotgxbfkisyakejihfjnrdngkwjxeituomuhmeiesctywhryqtjimwjadhhymydlsmcpycfdzrjhstxddvoqprrjufvihjcsoseltpyuaywgiocfodtylluuikkqkbrdxgjhrqiselmwnpdzdmpsvbfimnoulayqgdiavdgeiilayrafxlgxxtoqskmtixhbyjikfmsmxwribfzeffccczwdwukubopsoxliagenzwkbiveiajfirzvngverrbcwqmryvckvhpiioccmaqoxgmbwenyeyhzhliusupmrgmrcvwmdnniipvztmtklihobbekkgeopgwipihadswbqhzyxqsdgekazdtnamwzbitwfwezhhqznipalmomanbyezapgpxtjhudlcsfqondoiojkqadacnhcgwkhaxmttfebqelkjfigglxjfqegxpcawhpihrxydprdgavxjygfhgpcylpvsfcizkfbqzdnmxdgsjcekvrhesykldgptbeasktkasyuevtxrcrxmiylrlclocldmiwhuizhuaiophykxskufgjbmcmzpogpmyerzovzhqusxzrjcwgsdpcienkizutedcwrmowwolekockvyukyvmeidhjvbkoortjbemevrsquwnjoaikhbkycvvcscyamffbjyvkqkyeavtlkxyrrnsmqohyyqxzgtjdavgwpsgpjhqzttukynonbnnkuqfxgaatpilrrxhcqhfyyextrvqzktcrtrsbimuokxqtsbfkrgoiznhiysfhzspkpvrhtewthpbafmzgchqpgfsuiddjkhnwchpleibavgmuivfiorpteflholmnxdwewj"
    print s.LCS3(a)
