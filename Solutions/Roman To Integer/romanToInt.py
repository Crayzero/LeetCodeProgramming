class Solution:
    # @return an integer
    def romanToInt(self, s):
        roman_int_dic = {"M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1}
        result = roman_int_dic[s[len(s)-1]]
        for i in range(len(s)-2, -1, -1):
            if roman_int_dic[s[i+1]] <= roman_int_dic[s[i]]:
                result += roman_int_dic[s[i]]
            else:
                result -= roman_int_dic[s[i]]
        return result

if __name__ == "__main__":
    s = Solution()
    print s.romanToInt("III")
    print s.romanToInt("IX")
