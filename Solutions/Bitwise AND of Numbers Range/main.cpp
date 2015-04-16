class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = n^m;
        int cnt = 0;
        while(res) {
            res = res>>1;
            cnt++;
        }
        return m>>cnt<<cnt;
    }
};