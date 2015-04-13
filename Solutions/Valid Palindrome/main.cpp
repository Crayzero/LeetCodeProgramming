#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while(i<j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    string s("1a2");
    Solution so;
    cout<<so.isPalindrome(s)<<endl;
    return 0;
}
