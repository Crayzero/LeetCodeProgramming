#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int inserted = 0;
        for(auto iter = intervals.begin(); iter != intervals.end(); iter++) {
            cout<<iter->start<<" "<<iter->end<<":"<<newInterval.start<<" "<<newInterval.end<<endl;
            if (isOverlap(*iter, newInterval)) {
                newInterval = combine(*iter, newInterval);
                cout<<newInterval.start<<" "<<newInterval.end<<endl;
            }
            else {
                if (iter->start > newInterval.end && !inserted) {
                    inserted = 1;
                    res.push_back(newInterval);
                }
                res.push_back(*iter);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
        }
        return res;
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
    vector<Interval> intervals = {Interval(1,2),Interval(3,5),Interval(8,10),Interval(12,16)};
    Solution s;
    vector<Interval> res = s.insert(intervals, Interval(16,18));
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<"["<<iter->start<<","<<iter->end<<"]"<<" ";
    }
    cout<<endl;
    return 0;
}
