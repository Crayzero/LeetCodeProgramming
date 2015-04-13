#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) {
            return ;
        }
        stringstream ss(s);
        string s2;
        vector<string > vs;
        while(ss>>s2) {
            vs.push_back(s2);
        }
        s = "";
        vector<string>::size_type size = vs.size();
        if (size == 0) {
            return ;
        }
        vector<string>::size_type i = 0;
        vector<string>::const_reverse_iterator rbeg;
        for(rbeg = vs.rbegin(); i< size-1; rbeg++, i++) {
            s += (*rbeg + " ");
        }
        s += *rbeg;
    }
};

int main()
{
    Solution s;
    string str = " ";
    s.reverseWords(str);
    return 0;
}
