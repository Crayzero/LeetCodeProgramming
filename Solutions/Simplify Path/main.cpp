#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string > s;
        string tmp;
        if (path.size() == 0) {
            return tmp;
        }
        if (path[path.size()-1] != '/') {
            path.push_back('/');
        }
        for(auto iter = path.begin(); iter != path.end(); iter++) {
            if (*iter == '/') {
                if (tmp != "." && tmp != ".." && tmp.size()) {
                    s.push(tmp);
                }
                if (tmp == "..") {
                    if(!s.empty()) {
                        s.pop();
                    }
                }
                tmp = "";
            }
            else {
                tmp.push_back(*iter);
            }
        }
        string res;
        while(!s.empty()) {
            tmp = s.top();
            s.pop();
            res.insert(res.begin(), '/');
            res = tmp + res;
        }
        res.insert(res.begin(), '/');
        if (res != "/") {
            res.erase(res.end()-1, res.end());
        }
        return res;
    }
};

int main()
{
    Solution s;
    string path = "/...";
    cout<<s.simplifyPath(path)<<endl;
    return 0;
}
