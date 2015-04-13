#include <iostream>
#include <hashtable.h>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 2) {
            return points.size();
        }
        int res = 0;
        for(auto first = points.begin(); first != points.end(); first++) {
            unorder_m.clear();
            int same_point = 0;
            int tmp_max = 1;
            for(auto second = first+1; second != points.end(); second++) {
                double slope = numeric_limits<double >::infinity();
                if (second->x != first->x) {
                    slope = (1.0)*(second->y - first->y)/(second->x - first->x);
                }
                else if (second->y == first->y) {
                    same_point++;
                    continue;
                }
                int tmp = 0;
                if (unorder_m.find(slope) != unorder_m.end()) {
                    unorder_m[slope]++;
                }
                else {
                    unorder_m[slope] = 2;
                }
                tmp = unorder_m[slope];
                if (tmp_max < tmp) {
                    tmp_max = tmp;
                }
            }
            res = res < same_point+tmp_max? same_point+tmp_max: res;
        }
        return res;
    }
    unordered_map<double, int> unorder_m;
};
int main()
{
    Point a(1,1);
    Point b(1,1);
    Point c(3,3);
    Point d(3,4);
    vector<Point > v_p = {a};
    Solution s;
    cout<<s.maxPoints(v_p)<<endl;
    return 0;
}
