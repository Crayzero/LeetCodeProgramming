class Solution:
    # @return an integer
    def atoi(self, str):
        INT_MAX = 2147483647
        int_MIN = 2147483648
        s = str.strip()
        if not s:
            return 0
        first_char = s[0]
        positive = True
        if first_char == '+':
            s = s[1:]
        elif first_char == "-":
            s = s[1:]
            positive = False
        elif first_char < "0" and first_char > "9":
            return 0
        res = self.process(s)
        if res > INT_MAX and positive:
            res = INT_MAX
        elif not positive and res > int_MIN:
            res = int_MIN
        if positive:
            return res
        else:
            return -res

    def process(self, s):
        value = 0
        for i in s:
            pro_value = ord(i)
            if pro_value >= 48 and pro_value <= 57:
                value = 10*value + (pro_value-48)
            else:
                return value
        return value
