#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool  dividend_neg = false, divisor_neg = false;
        if (dividend < 0) {
            dividend_neg = true;
            dividend = - dividend;
        }
        if (divisor < 0) {
            divisor_neg = true;
            divisor = -divisor;
        }
        int res = 0;
        if (dividend == INT_MIN) {
            res+=1;
            dividend = -(dividend + divisor);
        }
        if ((dividend != INT_MIN && dividend < divisor) || divisor == INT_MIN) {
            if (dividend_neg ^ divisor_neg) res = -res;
            return res;
        }
        if (divisor == 0) {
            return INT_MAX;
        }
        int a = divisor;
        int i = 0;
        for(; a > 0 && a < dividend; a = a<< 1, i++);
        a = i >0 ? divisor<< (i-1) : divisor;
        int left = 0;
        int right = i-1;
        res += right > 0? 1<<right : 1;
        int cnt = 0;
        while(left <= right) {
            int mid = (left + right)/2;
            cout<<a + (divisor<<mid)<<endl;
            if ((a + (divisor<<(mid))) == dividend) {
                a += (divisor << mid);
                res += 1<<mid;
                break;
            }
            if ((a + (divisor<<mid)) >0 && (a + (divisor<<mid)) < dividend) {
                if (left == right ) {
                    res += 1<<mid;
                    a += divisor<<mid;
                    left = 0;
                    cnt = 0;
                }
                else {
                    left = mid+1;
                    cnt += 1;
                }
            }
            else {
                if (mid == 0) {
                    break;
                }
                if (cnt > 0) {
                    res += 1<<(left-1);
                    a += divisor<<(left-1);
                }
                cnt = 0;
                left = 0;
                right = mid-1;
            }
        }
        if (dividend_neg ^ divisor_neg) {
            if (res < 0) return res;
            res = -res;
        }
        else {
            if (res < 0) return INT_MAX;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.divide(-2147483648,1262480350);
    return 0;
}
