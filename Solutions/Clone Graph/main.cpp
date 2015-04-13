#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        vector<UndirectedGraphNode *> s;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        s.push_back(node);
        while(!s.empty()) {
            UndirectedGraphNode *old_node = s.back();
            s.pop_back();
            if (m.find(old_node) == m.end()) {
                UndirectedGraphNode *t = new UndirectedGraphNode(old_node->label);
                m[old_node] = t;
                cout<<old_node->label<<" "<<t->label<<" "<<old_node<<" "<<t<<endl;
                for(auto beg = old_node->neighbors.begin(); beg != old_node->neighbors.end(); beg++) {
                    s.push_back(*beg);
                }
            }
        }
        cout<<endl;
        s.push_back(node);
        unordered_set<UndirectedGraphNode *> visited;
        while(!s.empty()) {
            UndirectedGraphNode *old_node = s.back();
            s.pop_back();
            if (visited.find(old_node) == visited.end()) {
                UndirectedGraphNode *new_node = m[old_node];
                cout<<old_node->label<<" "<<new_node->label<<" "<<old_node<<" "<<new_node<<endl;
                visited.insert(old_node);
                for(auto beg = old_node->neighbors.begin(); beg!= old_node->neighbors.end(); beg++) {
                    new_node->neighbors.push_back(m[*beg]);
                    s.push_back(*beg);
                }
            }
        }
        return m[node];
    }
};

int main()
{
    UndirectedGraphNode *a = new UndirectedGraphNode(0);
    UndirectedGraphNode *b = new UndirectedGraphNode(1);
    UndirectedGraphNode *c = new UndirectedGraphNode(2);
    a->neighbors.push_back(b);
    a->neighbors.push_back(c);
    b->neighbors.push_back(c);
    c->neighbors.push_back(c);
    Solution s;
    UndirectedGraphNode *n = s.cloneGraph(a);
    return 0;
}
