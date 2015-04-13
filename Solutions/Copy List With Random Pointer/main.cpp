#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return head;
        }
        unordered_map<RandomListNode *, RandomListNode*> node_map;
        vector<RandomListNode *> s;
        s.push_back(head);
        while(!s.empty()) {
            RandomListNode *cur = s.back();
            s.pop_back();
            if (node_map.find(cur) == node_map.end()) {
                RandomListNode *tmp = new RandomListNode(cur->label);
                node_map[cur] = tmp;
                cout<<cur<<" "<<tmp<<endl;
                cout<<cur->label<<" "<<tmp->label<<endl;
            }
            if (cur->next && node_map.find(cur->next) == node_map.end()) {
                s.push_back(cur->next);
            }
            if (cur->random && node_map.find(cur->random) == node_map.end()) {
                s.push_back(cur->random);
            }
        }
        cout<<endl;
        RandomListNode *tmp = head;
        while(tmp) {
            RandomListNode *n = node_map[tmp];
            cout<<tmp<<" "<<n<<endl;
            cout<<tmp->label<<" "<<n->label<<endl;
            n->next = node_map[tmp->next];
            n->random = node_map[tmp->random];
            tmp = tmp->next;
        }
        return node_map[head];
    }
};

int main()
{
    RandomListNode *a = new RandomListNode(1);
    RandomListNode *b = new RandomListNode(2);
    RandomListNode *c = new RandomListNode(3);
    a->next = b;
    a->random = b;
    b->next = NULL;
    b->random = c;
    Solution s;
    RandomListNode *n = s.copyRandomList(a);
    for(;n;n = n->random) {
        cout<<n->label<<" ";
    }
    cout<<endl;
    return 0;
}
