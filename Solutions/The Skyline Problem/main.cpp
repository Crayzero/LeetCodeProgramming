#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        for(auto iter = buildings.begin(); iter != buildings.end(); iter++) {
            vector<pair<int, int>> tmp;
            tmp.push_back(make_pair((*iter)[0], (*iter)[2]));
            tmp.push_back(make_pair((*iter)[1], 0));
            union_pair(res, tmp);
            for(int i = 0; i < res.size(); i++) {
                cout<<res[i].first<<" "<<res[i].second<<endl;
            }
            cout<<endl;
        }
        return res;
    }
    void union_pair(vector<pair<int, int>> &res, vector<pair<int, int>> &new_pair) {
        int x1_left = new_pair[0].first;
        int x2_left = new_pair[1].first;
        int y = new_pair[0].second;
        int last_y = 0;
        int last_2y = 0;
        int x1_insert = 0;
        int x2_insert = 0;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            if (iter->first == x1_left) {
                if (iter->second < y) {
                    if (y == last_y) {
                        res.erase(iter);
                        iter--;
                    }
                    else
                        iter->second = y;
                }
                x1_insert = 1;
            }
            if (iter->first > x1_left) {
                if (!x1_insert) {
                    if (y > last_y) {
                        iter = res.insert(iter, new_pair[0]);
                    }
                    else
                        iter--;
                    x1_insert = 1;
                    last_2y = last_y;
                    last_y = iter->second;
                    continue;
                }
                if (iter->first < x2_left && iter->second < y ) {
                    last_2y = iter->second;
                    iter->second = y;
                    if (y != last_y)
                        iter->second = y;
                    else
                        res.erase(iter--);
                }
            }
            if (iter->first == x2_left) {
                x2_insert = 1;
            }
            if (iter->first > x2_left) {
                if (!x2_insert) {
                    if (y == last_y && last_2y != last_y)
                        iter = res.insert(iter, make_pair(x2_left, last_2y));
                    x2_insert = 1;
                    continue;
                }
            }
            last_y = iter->second;
        }
        if (!x1_insert) {
            res.insert(res.end(), new_pair[0]);
        }
        if (!x2_insert) {
            res.insert(res.end(), new_pair[1]);
        }
    }
};

int main()
{
    vector<vector<int>> buildings = {{6,100,41},{7,15,70},{10,30,102},{15,25,76},{60,80,91},{70,90,72},{85,120,59}};
    Solution s;
    vector<pair<int, int>> res = s.getSkyline(buildings);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    return 0;
}
