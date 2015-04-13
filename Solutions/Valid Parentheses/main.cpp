#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char > st;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == '(' || *iter == '{' || *iter == '[') {
                    st.push(*iter);
            }
            else {
                switch(*iter) {
                case ')':
                    if (st.empty() || st.top() != '(') {
                        return false;
                    }
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') {
                        return false;
                    }
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') {
                        return false;
                    }
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isValid("]");
    return 0;
}
