#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) {
            return 0;
        }
        vector<int > res;
        for(auto beg = tokens.begin(); beg != tokens.end(); beg++) {
            if (*beg != "+" && *beg !="-" && *beg!="*" && *beg!="/") {
                int b;
                stringstream sstream(*beg);
                sstream>>b;
                res.push_back(b);
            }
            else {
                int last = res.back();
                res.pop_back();
                int first = 0;
                if (res.size()) {
                    first = res.back();
                    res.pop_back();
                }
                int tmp_res;
                if(*beg == "+") {
                    tmp_res = first + last;
                }
                else if(*beg == "-") {
                    tmp_res = first - last;
                }
                else if(*beg == "*") {
                    tmp_res = first * last;
                }
                else if(*beg == "/") {
                    tmp_res = first / last;
                }
                res.push_back(tmp_res);
            }
        }
        return res.back();
    }
};

int main()
{
    Solution s;
    vector<string> tokens = {"2"};
    vector<string > tokens2 = {"4", "13", "5", "/", "+"};
    cout<<s.evalRPN(tokens)<<endl;
    cout<<s.evalRPN(tokens2)<<endl;
    return 0;
}
