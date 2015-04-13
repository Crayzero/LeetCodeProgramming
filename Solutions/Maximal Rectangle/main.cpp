#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int x_size = matrix.size();
        if (x_size == 0) {
            return 0;
        }
        int y_size = matrix[0].size();
        int max_rec = 0;
        vector<vector<int> > heights(x_size, vector<int>(y_size,0));
        for(int i = 0; i < x_size; i++) {
            for(int j = 0; j < y_size; j++) {
                if(matrix[i][j] == '1') {
                    heights[i][j] = i==0? 1: heights[i-1][j]+1;
                }
            }
        }
        for(int i = 0; i < x_size; i++) {
            max_rec = max(max_rec, largestRectangleArea(heights[i]));
        }
        return max_rec;
    }
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
};

int main()
{
    vector<vector<char> > m = {{},{}};
    Solution s;
    cout<<s.maximalRectangle(m)<<endl;
    return 0;
}
