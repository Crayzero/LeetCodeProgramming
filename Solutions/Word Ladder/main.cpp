class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, int> visited;
        unordered_set<string> unvisited(dict);
        q.push(start);
        visited[start] = 1;
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            auto iter = unvisited.begin();
            while(iter != unvisited.end()) {
                string tmp = *iter;
                if (isLadder(word, tmp)) {
                    visited[tmp] = visited[word] + 1;
                    if (tmp == end) {
                        return visited[tmp];
                    }
                    q.push(tmp);
                    iter = unvisited.erase(iter);
                }
                else {
                    iter++;
                }
            }
        }
        return 0;
    }
    bool isLadder(string &left, string &right) {
        int diff = 0;
        for (int i = 0; i < left.size(); ++i)
        {
            if (left[i] != right[i]) ++diff;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};