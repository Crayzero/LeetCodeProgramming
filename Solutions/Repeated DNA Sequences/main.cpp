class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<size_t, pair<int, int>> m;
        hash<string> str_hash;
        if (s.size() <= 10) {
            return result;
        }
        string::size_type len = s.size();
        for(string::size_type start = 0; start <= len-10; start++) {
            string sub_str = s.substr(start, 10);
            size_t h = str_hash(sub_str);
            if (m[h].second == 0) {
                m[h] = make_pair(start, 1);
            }
            else {
                m[h].second++;
            }
        }
        for(auto begin = m.begin(); begin != m.end(); begin++) {
            auto r = begin->second;
            if(r.second > 1) {
                string ss= s.substr(r.first, 10);
                result.push_back(ss);
            }
        }
        return result;
    }
};