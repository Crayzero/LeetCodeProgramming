#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s;
        while(n) {
            s.insert(s.begin(), '0' +n%2);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        for(int n = s.size(); n < 32; n++) {
            s.push_back('0');
        }
        cout<<s.size()<<" "<<s<<endl;
        uint32_t res = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            res += (s[i] - '0') * pow(2, 31-i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(4294967295);
    return 0;
}
