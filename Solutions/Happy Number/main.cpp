#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(n != 1) {
            cout<<n<<endl;
            if (m.find(n) != m.end()) {
                return false;
            }
            m[n] = 1;
            n = f(n);
        }
        return true;
    }
    int f(int n) {
        int res = 0;
        while(n) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.isHappy(11);
    return 0;
}
