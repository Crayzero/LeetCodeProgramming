#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res(numCourses, -1);
        unordered_map<int, int> indegree;
        for(auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
            if (indegree.find(iter->first) == indegree.end())
                indegree[iter->first] = 1;
            else
                indegree[iter->first] += 1;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout<<"V = "<<v<<endl;
            res[cnt] = v;
            cnt += 1;
            for(auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
                if (iter->second == v) {
                    indegree[iter->first]--;
                    if (indegree[iter->first] == 0) {
                        cout<<"pushing "<<iter->first<<endl;
                        q.push(iter->first);
                    }
                }
            }
        }
        if (cnt != numCourses)
                return vector<int>();
        return res;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> pre = {};
    vector<int> res = s.findOrder(1, pre);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<(*iter)<<" ";
    }
    return 0;
}
