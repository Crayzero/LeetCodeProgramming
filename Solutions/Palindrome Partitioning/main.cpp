class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if (isPalindrome(s)) {
            res.push_back(vector<string>(1,s));
        }
        string::size_type size = s.size();
        for(string::size_type i = 1; i < size; i++) {
            string left_str = s.substr(0, i);
            if(isPalindrome(left_str)) {
                vector<vector<string> > rest_res;
                rest_res = partition(s.substr(i));
                if (rest_res.size()) {
                    for(auto beg = rest_res.begin(); beg!=rest_res.end(); beg++) {
                        vector<string> t = *beg;
                        t.insert(t.begin(), left_str);
                        res.push_back(t);
                    }
                }
            }
        }
        return res;
    }
    bool isPalindrome(const string &s) {
        string::size_type size = s.size();
        for(string::size_type i = 0; i < size/2; i++) {
            if (s[i] != s[size-i-1]) {
                return false;
            }
        }
        return true;
    }
};