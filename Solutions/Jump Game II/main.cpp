#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1) return 0;
        int step = 1;
        for(int i = 0; i + A[i] < n-1; ) {
            int index_max = i+1;
            for(int j = 1; j <= A[i]; j++) {
                index_max = (i+j + A[i+j]) > (index_max + A[index_max]) ? (i+j) : index_max;
            }
            cout<<index_max<<endl;
            i = index_max;
            step++;
        }
        return step;
    }
};

int main()
{
    int A[] = {2,0,2,4,6,0,0,3};
    Solution s;
    cout<<s.jump(A, sizeof(A)/sizeof(A[0]))<<endl;
    return 0;
}
