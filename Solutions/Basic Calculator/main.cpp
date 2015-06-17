#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s.push_back('\0');
        stack<int> nums;
        stack<char> op;
        int prev = 0;
        int flag = 0;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == ' ')
                continue;
            if (*iter >= '0' && *iter <= '9') {
                prev = prev * 10 + (*iter - '0');
                flag = 1;
            }
            else {
                if (flag) {
                    nums.push(prev);
                    cout<<"nums push "<<prev<<endl;
                }
                if (op.empty() || *iter == '(') {
                    op.push(*iter);
                    cout<<"op push "<<*iter<<endl;
                }
                else {
                    while(!op.empty()) {
                        if (op.top() == '(') {
                            if (*iter == ')') {
                                *iter = '\0';
                                op.pop();
                                continue;
                            }
                            break;
                        }
                        else {
                            int second = nums.top();
                            nums.pop();
                            int first = nums.top();
                            nums.pop();
                            cout<<first<<op.top()<<second<<endl;
                            switch(op.top()) {
                                case '+':
                                    nums.push(first + second);
                                    cout<<"nums push "<<first+second<<endl;
                                    op.pop();
                                    break;
                                case '-':
                                    nums.push(first - second);
                                    cout<<"nums push "<<first-second<<endl;
                                    op.pop();
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    if (*iter != '\0' && *iter != ')') {
                        op.push(*iter);
                        cout<<"op push "<<*iter<<endl;
                    }
                }
                prev = 0;
                flag = 0;
            }
        }
        return nums.top();
    }
};

int main()
{
    string s1 = "2-1 + 2";
    string s2 = "(1+(4+5+2)-3)+(6+8)";
    Solution s;
    cout<<s.calculate(s1)<<endl;
    cout<<s.calculate(s2)<<endl;
    return 0;
}
