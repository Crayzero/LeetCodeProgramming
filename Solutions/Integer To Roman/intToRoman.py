class Solution:
    # @return a string
    def intToRoman(self, num):
        int_array = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman_array = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        if num < 1 or num > 3999:
            return "-1"
        rnumber = ""
        for i in range(len(int_array)):
            while num >= int_array[i]:
                rnumber += roman_array[i]
                num -= int_array[i]
        return rnumber


if __name__ == "__main__":
    s = Solution()
    print s.intToRoman(3)
    print s.intToRoman(99)
