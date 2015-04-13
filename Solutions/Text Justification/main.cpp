#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int w_size = words.size();
        int i = 0;
        while(i < w_size) {
            string tmp;
            int j = i;
            int row_len = 0;
            for(j = i;j < w_size && row_len + words[j].size() + j-i <= L; j++) {
                row_len += words[j].size();
            }
            cout<<i<<" "<<j<<" "<<row_len<<endl;
            if (j == i+1) {
                tmp = words[i];
                for(int i = 0; i < L-row_len; i++) {
                    tmp.push_back(' ');
                }
                res.push_back(tmp);
            }
            else {
                int even_space = j == w_size? 0: (L - row_len) / (j-i-1);
                int rest_space = j == w_size? (L - row_len) : (L-row_len)%(j-i-1);
                cout<<even_space<<" "<<rest_space<<endl;
                for(int k = i; k < j-1; k++) {
                    tmp += words[k];
                    for(int t = 0; t < even_space; t++) {
                        tmp.push_back(' ');
                    }
                    if (rest_space) {
                        tmp.push_back(' ');
                        rest_space--;
                    }
                }
                tmp += words[j-1];
                for(int k =0; k < rest_space; k++) {
                    tmp.push_back(' ');
                }
                res.push_back(tmp);
                cout<<tmp<<" "<<tmp.size()<<endl;
            }
            i = j;
        }
        return res;
    }
};

int main()
{
    vector<string> words = {"this","is","an", "example", "of", "text", "justification."};
    vector<string> words2 = {"What","must","be","shall","be."};
    Solution s;
    //vector<string> res = s.fullJustify(words,16);
    vector<string> res2 = s.fullJustify(words2, 12);
    for(auto iter = res2.begin(); iter != res2.end(); iter++) {
        cout<<*iter<<iter->size()<<endl;
    }
    return 0;
}
