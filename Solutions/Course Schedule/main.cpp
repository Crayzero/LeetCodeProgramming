#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int *indegree = new int[numCourses];
        for(int i = 0; i < numCourses; i++) indegree[i] = 0;
        for(auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
            indegree[(*iter)[1]] += 1;
        }
        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int i = q.front();
            cout<<i<<endl;
            q.pop();
            cnt++;
            for(auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++) {
                if ((*iter)[0] == i) {
                    if (--indegree[(*iter)[1]] == 0) {
                        q.push((*iter)[1]);
                    }
                }
            }
        }
        if (cnt == numCourses)
            return true;
        return false;
    }
};

int main()
{

    Solution s;
    vector<vector<int> > p = {};
    cout<<s.canFinish(5, p);
    return 0;
}
