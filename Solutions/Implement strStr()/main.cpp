#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int h_size = strlen(haystack);
        int n_size = strlen(needle);
        if (n_size == 0 && h_size != 0) {
            return -1;
        }
        int *next = getNext(needle, n_size);
        int i = 0, j = 0;
        while( i < h_size && j < n_size) {
            if(j == -1 || needle[j] == haystack[i]) {
                i++,j++;
            }
            else {
                j = next[j];
            }
        }
        if (j == n_size) {
            return i-j;
        }
        return -1;
    }
    int* getNext(char *needle, int N) {
        int *next = new int [N];
        next[0] = -1;
        int j = 0;
        int k = -1;
        while(j < N-1) {
            if (k== -1 || needle[j] == needle[k]) {
                next[++j] = ++k;
            }
            else {
                k = next[k];
            }
        }
        for(int i = 0; i < N; i++) {
            cout<<next[i]<<" ";
        }
        cout<<endl;
        return next;
    }
};

int main()
{
    Solution s;
    char *s1 = "";
    char *s2 = "";
    cout<<s.strStr(s1,s2);
    return 0;
}
