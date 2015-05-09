#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char > m;
        unordered_set<char> mt;
        for(size_t i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                if (mt.find(t[i]) == mt.end())
                    m[s[i]] = t[i];
                else {
                    return false;
                }
            }
            else {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            }
            mt.insert(t[i]);
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isIsomorphic("123", "424");
    return 0;
}
