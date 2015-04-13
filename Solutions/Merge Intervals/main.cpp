#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), less_func);
        for(auto iter = intervals.begin(); iter != intervals.end(); iter++) {
            if (res.size() == 0) {
                res.push_back(*iter);
            }
            else {
                Interval last = res.back();
                if (isOverlap(*iter, last)) {
                    res.pop_back();
                    res.push_back(combine(*iter, last));
                }
                else {
                    res.push_back(*iter);
                }
            }
        }
        return res;
    }
    static bool less_func (const Interval &left, const Interval &right) {
        return left.start < right.start;
    }
    bool isOverlap(const Interval &left, const Interval &right) {
        if (right.end < left.start || right.start > left.end) {
            return false;
        }
        return true;
    }
    Interval combine(const Interval &left, const Interval &right) {
        int min_start = min(left.start, right.start);
        int max_end = max(left.end, right.end);
        return Interval(min_start, max_end);
    }
};

int main()
{
    vector<Interval> intervals = {Interval(2,3),Interval(4,6),Interval(8,10),Interval(4,16)};
    Solution s;
    vector<Interval> res = s.merge(intervals);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<"["<<iter->start<<","<<iter->end<<"]"<<" ";
    }
    cout<<endl;
    return 0;
}
