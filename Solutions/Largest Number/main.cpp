class Solution {
public:
    static bool comp(const string &l, const string &r) {
        if (l[0] != r[0]) {
            return l < r;
        }
        else {
            if (l.size() == r.size()) {
                return l < r;
            }
            else {
                string new_l = l + r;
                string new_r = r + l;
                return new_l < new_r;
            }
        }
    }
    string largestNumber(vector<int> &num) {
        vector<string> s_num;
        for(auto begin = num.begin(); begin != num.end(); begin++) {
            s_num.push_back(int_to_str(*begin));
        }
        std::sort(s_num.begin(), s_num.end(), comp);
        string res;
        for(auto begin = s_num.begin(); begin != s_num.end(); begin++) {
            res = *begin + res;
        }
        string zero = string(res.size(), '0');
        if (zero == res) {
            return "0";
        }
        return res;
    }
    string int_to_str(int num) {
        string result;
        if (num == 0) {
            return string("0");
        }
        while(num) {
            char t = '0' + num%10;
            result = string(1,t) + result;
            num /= 10;
        }
        return result;
    }
};