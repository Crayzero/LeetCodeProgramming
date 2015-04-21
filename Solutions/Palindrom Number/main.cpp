#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return f(x, x);
    }
    bool f(int x, int &y) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (f(x/10, y) && x%10 == y%10) {
            y /= 10;
            return true;
        }
        else {
            return false;
        }
    }
    bool isPalindrome2(int x) {
        int div = 1;
        if (x < 0) {
            return false;
        }
        while(x / div >= 10) {
            div *= 10;
        }
        while(x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) {return false;}
            x = (x % div ) /10;
            div /= 100;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(121);
    return 0;
}
