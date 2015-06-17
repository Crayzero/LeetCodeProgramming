#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left_area = abs((C-A)*(D-B));
        int right_area = abs((G-E)*(H-F));
        int left_x = max(A, E);
        int left_y = max(B, F);
        int right_x = max(C, G);
        int right_y = max(D,H);
        int area3 = 0;
        if (right_x > left_x && right_y > left_y)
            area3 = (right_x - left_x)*(right_y - left_y);
        return left_area + right_area - area3;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
