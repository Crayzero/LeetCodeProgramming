#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int *seen = new int [n];
        for(int i = 0; i < n; i++) {
            seen[i] = -1;
        }
        vector<vector<string> > res = f(n, 0, seen);
        cout<<"results:-------------------------------"<<endl;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<"[ ";
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<endl;
            }
            cout<<" ]";
            cout<<endl;
        }
        return res;
    }
    vector<vector<string> > f(int n, int step, int seen[]) {
        vector<vector<string> > res;
        if (step == n) {
            return res;
        }
        for(int i = 0; i < n; i++) {
            if (check(seen, step, i)) {
                string tmp_str(n, '.');
                tmp_str[i] = 'Q';
                seen[step] = i;
                auto rest_res = f(n, step+1, seen);
                for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                    for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                        cout<<*iter2<<" ";
                    }
                    cout<<endl;
                }
                if (rest_res.size() > 0 ) {
                    for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                        iter->insert(iter->begin(), tmp_str);
                        res.push_back(*iter);
                    }
                }
                else {
                    if (step == n-1) {
                        res.push_back(vector<string>(1,tmp_str));
                    }
                }
                seen[step] = -1;
            }
        }
        return res;
    }
    bool check(int seen[], int row, int col) {
        for(int i = 0; i < row; i++) {
            if (seen[i] == col || abs(i- row) == abs(seen[i] - col)) {
                return false;
            }
        }
        return true;
    }
    int totalNQueens(int n) {
        int *seen = new int [n];
        for(int i = 0; i < n; i++) {
            seen[i] = -1;
        }
        return f2(n, 0, seen);
    }
    int f2(int n, int step, int seen[]) {
        int cnt = 0;
        if (n == 0) {
            return cnt;
        }
        if(step == n) {
            return 1;
        }
        for(int i = 0; i < n; i++) {
            if (check(seen, step, i)) {
                seen[step] = i;
                int nex_res = f2(n, step+1, seen);
                if (nex_res) {
                    cnt+= nex_res;
                }
                seen[step] = -1;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    s.solveNQueens(5);
    cout<<s.totalNQueens(5);
    return 0;
}
