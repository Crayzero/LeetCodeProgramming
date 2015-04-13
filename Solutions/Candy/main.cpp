#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    //time limit exceeded
    int candy(vector<int> &ratings) {
        vector<int> res_v(ratings.size(), 1);
        vector<int>::size_type size = ratings.size();
        for(vector<int>::size_type i = 1; i < size; i++) {
            if(ratings[i] > ratings[i-1]) {
                res_v[i] = res_v[i-1] + 1;
            }
            else {
                res_v[i] = 1;
                for(auto j = i; j>0 && ratings[j-1] > ratings[j] && res_v[j-1] <= res_v[j]; j--) {
                    res_v[j-1] += 1;
                }
            }
        }
        int res = 0;
        return accumulate(res_v.begin(),res_v.end(),res);
    }
    int candy2(vector<int > &ratings) {
        vector<int>::size_type size = ratings.size();
        vector<int> left(size,1), right(size,1);
        int res = 0;
        left[0] = 1;
        right[size-1] = 1;
        for(vector<int>::size_type i = 1; i< size; i++) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
            if (ratings[size-i-1] > ratings[size-i]) {
                right[size-1-i] = right[size-i] + 1;
            }
        }
        for(vector<int>::size_type i = 0; i < size; i++) {
            res += max(left[i], right[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int > ratings = {1,2,2};
    cout<<s.candy(ratings)<<endl;
    cout<<endl;
    cout<<s.candy2(ratings)<<endl;
    return 0;
}
