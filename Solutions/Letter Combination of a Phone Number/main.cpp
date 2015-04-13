#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char> > v_c(8);
        v_c[0] = vector<char>({'a', 'b', 'c'});
        v_c[1] = vector<char>({'d', 'e', 'f'});
        v_c[2] = vector<char>({'g', 'h', 'i'});
        v_c[3] = vector<char>({'j', 'k', 'l'});
        v_c[4] = vector<char>({'m', 'n', 'o'});
        v_c[5] = vector<char>({'p', 'q', 'r', 's'});
        v_c[6] = vector<char> ({'t','u','v'});
        v_c[7] = vector<char> ({'w','x','y','z'});
        return f(res, digits, v_c);
    }
    vector<string> f(vector<string > &res, string &digits, vector<vector<char> > &dic) {
        if (digits.size() == 0) {
            return res;
        }
        int c = digits[0] - '2';
        digits.erase(digits.begin());
        if (c < 0) {
            return f(res, digits, dic);
        }
        vector<char> v_c = dic[c];
        if (res.size() == 0 ) {
            for(auto iter2 = v_c.begin(); iter2 != v_c.end(); iter2++) {
                res.push_back(string(1, *iter2));
            }
        }
        else {
            vector<string> t;
            for(auto iter = res.begin(); iter != res.end(); iter++) {
                for(auto iter2 = v_c.begin(); iter2 != v_c.end(); iter2++) {
                    t.push_back(*iter + string(1, *iter2));
                }
            }
            res = t;
        }
        return f(res, digits, dic);
    }
};

int main()
{
    Solution s;
    vector<string> res;
    res = s.letterCombinations("1");
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<endl;
    }
    return 0;
}
