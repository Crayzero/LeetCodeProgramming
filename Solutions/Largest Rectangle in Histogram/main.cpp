#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int max_area = 0;
        int h_size = height.size();
        for(int i = 0; i < h_size;) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            }
            else {
                int last = s.top();
                s.pop();
                max_area = max(max_area, height[last]* (s.empty()? i: i-s.top()-1));
            }
        }
        while(!s.empty()) {
            int last = s.top();
            s.pop();
            max_area = max(max_area, height[last]*(s.empty()? h_size: h_size - s.top()-1) );
        }
        return max_area;
    }
    int devide(vector<int> &height) {
        return f(height, 0, height.size());
    }
    int f(vector<int> &height, int start, int end) {
        if (end == start) {
            return 0;
        }
        if (end - start == 1) {
            return height[start];
        }
        int min_index = start;
        for(int i = start; i < end; i++) {
            if (height[i] < height[min_index]) {
                min_index = i;
            }
        }
        cout<<height[min_index] * (end-start)<<endl;
        return max(max(f(height,start,min_index), height[min_index] * (end-start)), f(height, min_index+1, end));
    }
};

int main()
{
    Solution s;
    vector<int> h = {3,3,2,2};
    cout<<s.largestRectangleArea(h)<<endl;
    cout<<s.devide(h);
    return 0;
}
