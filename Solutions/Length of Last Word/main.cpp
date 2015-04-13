#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string ss(s);
        for(int i = ss.size()-1; i >= 0 && ss[i] == ' '; i--) {
            ss.erase(i,1);
        }
        size_t index_of_space = ss.find_last_of(' ');
        if (index_of_space == string::npos) {
            return ss.size();
        }
        return ss.size() - index_of_space -1;
    }
};

int main()
{
    char s[] = "   ";
    Solution so;
    cout<<so.lengthOfLastWord(s);
    return 0;
}
