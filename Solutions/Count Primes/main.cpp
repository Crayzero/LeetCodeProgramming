#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int *m = new int[n];
        for(int i = 0; i < n; i++) m[i] = 0;
        int res = 0;
        int i = 2;
        while(1) {
            for(; m[i] == 1 && i < n; i++);
            cout<<i<<endl;
            if (i >= n) break;
            res += 1;
            for(int k = 1; i * k < n; k++) {
                m[i * k] = 1;
            }
        }
        delete [] m;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.countPrimes(4);
    return 0;
}
