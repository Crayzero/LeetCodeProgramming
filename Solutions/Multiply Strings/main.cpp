#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        bool num1_neg = false, num2_neg = false;
        if (!isdigit(num1[0])) {
            if (num1[0] == '-') {
                num1_neg = true;
            }
            num1.erase(num1.begin());
        }
        if (!isdigit(num2[0])) {
            if (num2[0] == '-') {
                num2_neg = true;
            }
            num2.erase(num2.begin());
        }
        int size1 = num1.size();
        int size2 = num2.size();
        int total_size = size1 + size2;
        string res(total_size, '0');
        for(int i = size1-1; i >= 0; i--) {
            int a1 = num1[i] - '0';
            int c = 0;
            string t(size1-1-i, '0');
            for(int j = size2-1; j >= 0; j--) {
                int a2 = num2[j] - '0';
                int a = a1 * a2 + c;
                t.insert(t.begin(), a%10 + '0');
                c = a/10;
            }
            if (c) {
                t.insert(t.begin(), c + '0');
            }
            cout<<t<<endl;
            add(t, res);
            cout<<res<<endl;
        }
        for(auto iter = res.begin(); iter != res.end() && *iter == '0';) {
            res.erase(iter);
        }
        if (num1_neg ^ num2_neg && res.size()) {
            res.insert(res.begin(), '-');
        }
        if (res.size() == 0) {
            res.push_back('0');
        }
        return res;
    }
    void add(const string &t, string &res) {
        int c = 0;
        for(int i = t.size()-1; i >= 0; i--) {
            int index = res.size()-1 - (t.size()-1-i);
            int t_sum = t[i] - '0' + res[index] - '0' + c;
            res[index] = t_sum % 10 + '0';
            c = t_sum / 10;
        }
        for(int j = res.size()-1-t.size(); j >=0 && c; j--) {
            int t_sum = res[j] - '0' + c;
            res[j] = t_sum % 10 + '0';
            c = t_sum / 10;
        }
    }
};

int main()
{
    string num1 = "999";
    string num2 = "99";
    Solution s;
    cout<<s.multiply(num1, num2);
    return 0;
}
