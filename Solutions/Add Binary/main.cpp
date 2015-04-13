#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        for(auto iter = a.begin(); *iter == '0' && iter != a.end()-1;) {
            a.erase(iter);
        }
        for(auto iter = b.begin(); *iter == '0' && iter != b.end()-1;) {
            b.erase(iter);
        }
        if (a.size() < b.size()) {
            swap(a, b);
        }
        cout<<a<<" "<<b<<endl;
        int i = a.size();
        int j = b.size();
        int add = 0;
        for(; i && j; i--, j--) {
            int a_tmp = a[i-1] - '0';
            int b_tmp = b[j-1] - '0';
            if (res.size() == 0) {
                res.push_back((a_tmp + b_tmp + add) % 2 + '0');
            }
            else {
                res.insert(res.begin(), (a_tmp + b_tmp + add) % 2 + '0');
            }
            if (a_tmp + b_tmp + add >= 2) {
                add = 1;
            }
            else {
                add = 0;
            }
        }
        cout<<res<<endl;
        for(; i; i--) {
            if (a[i-1] == '1' && add == 1) {
                res.insert(res.begin(), '0');
            }
            else if (a[i-1] == '1' || add == 1){
                res.insert(res.begin(), '1');
                add = 0;
            }
            else {
                res.insert(res.begin(), a[i-1]);
            }
        }
        if (add) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};

int main()
{
    string a = "1010";
    string b = "1011";
    Solution s;
    cout<<s.addBinary(a,b)<<endl;
    return 0;
}
