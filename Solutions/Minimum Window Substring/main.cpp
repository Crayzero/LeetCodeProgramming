#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> target(256, 0);
        vector<int> v;
        int start = 0;
        int end = S.size();
        vector<int> showed(256, 0);
        for(int i = 0; i < T.size(); i++) {
            target[T[i]]++;
        }
        for(int i = 0; i < S.size(); i++) {
            char c = S[i];
            if (target[c] != 0) {
                cout<<c<<" "<<i<<endl;
                if (showed[c] == 0 || showed[c] < target[c]) {
                    v.push_back(i);
                    showed[c]++;
                    if (v.size() == T.size()) {
                        cout<<c<<" "<<i<<" "<<v.front()<<endl;
                        if (i - v.front() < end - start) {
                            start = v.front();
                            end = i;
                        }
                        showed[S[v.front()]] -= 1;
                        v.erase(v.begin(),v.begin()+1);
                    }
                }
                else {
                    auto iter = v.begin();
                    for(; iter != v.end() && S[*iter] != c; iter++);
                    v.erase(iter, iter+1);
                    v.push_back(i);
                }
            }
        }
        if (end != S.size()) {
            return S.substr(start, end-start+1);
        }
        return "";
    }
    string minWindow2(string S, string T) {
        string result;
        if(S.empty() || T.empty()){
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < T.length(); i++){
            map[T[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for(int slow = 0, fast = 0; fast < S.length(); fast++){
            char c = S[fast];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c]){
                    letterCounter++;
                }
                if(letterCounter >= T.length()){
                    while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]){
                        window[S[slow]]--;
                        slow++;
                    }

                    if(fast - slow + 1 < minLength){
                        minLength = fast - slow + 1;
                        result = S.substr(slow, minLength);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    string S = "adobecodebancbbcaa";
    string T = "abc";
    Solution s;
    cout<<s.minWindow2(S,T);
    return 0;
}
