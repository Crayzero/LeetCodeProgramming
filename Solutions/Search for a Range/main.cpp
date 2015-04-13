#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) {
                int i,j;
                i = j = mid;
                for(; i >= left && A[i] == target; i--);
                for(; j <= right && A[j] == target; j++);
                res[0] = i+1;
                res[1] = j-1;
                return res;
            }
            if (target > A[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main()
{
    int A[] = {};
    Solution s;
    vector<int> res = s.searchRange(A,sizeof(A)/sizeof(A[0]), 5);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    return 0;
}
