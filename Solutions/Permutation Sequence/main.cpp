#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> t;
        string res;
        int *perm = new int [n];
        perm[0] = 1;
        for(int i = 1; i < n; i++) {
            perm[i] = perm[i-1] * i;
            t.push_back(i);
        }
        t.push_back(n);
        if (k ==0 || k > perm[n-1] *n) {
            return res;
        }
        k = k-1;
        while(k) {
            int a = k/perm[--n];
            cout<<k<<" "<<perm[n]<<" "<<a<<endl;
            k  = k% perm[n];
            res.push_back('0' + t[a]);
            t.erase(t.begin() + a);
        }
        while (!t.empty()) {
            res.push_back('0' + t.front());
            t.erase(t.begin());
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.getPermutation(3,3);
    return 0;
}
