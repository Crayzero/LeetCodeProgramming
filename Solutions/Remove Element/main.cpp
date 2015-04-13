#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int left = 0;
        int right = n-1;
        while(left < right) {
            for(;left < n && A[left] != elem; left++);
            for(;right >= 0 && A[right] == elem; right--);
            cout<<left<<" "<<right<<endl;
            if(left < n && right > 0 && left < right) {
                swap(A[left], A[right]);
            }
            left++, right--;
        }
        for(int i = 0; i < n; i++) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        right = n-1;
        for(; right >= 0 && A[right] == elem; right--);
        cout<<right<<endl;
        return right+1;
    }
};

int main()
{
    int A[] = {2,2,3};
    Solution s;
    cout<<s.removeElement(A, sizeof(A)/sizeof(A[0]), 3);
    return 0;
}
