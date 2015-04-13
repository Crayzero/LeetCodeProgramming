#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 1) {
            return 1;
        }
        if (x < 0) {
            return (n%2? -1 : 1) * pow(-x, n);
        }
        if (n < 0) {
            return 1.0/pow(x, -n);
        }
        double t = pow(x, n/2);
        if (n % 2) {
            return t*t*x;
        }
        else {
            return t*t;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.pow(-0.99999,221620);
    return 0;
}
