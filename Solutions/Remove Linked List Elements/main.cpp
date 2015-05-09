#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) {
            ListNode *p = head->next;
            delete head;
            head = p;
        }
        ListNode *p = head;
        while(p && p->next) {
            if (p->next->val == val) {
                ListNode *t = p->next;
                p->next = t->next;
                delete t;
            }
            else
                p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(4);
    ListNode *f = new ListNode(5);
    ListNode *g = new ListNode(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    a = s.removeElements(a, 2);
    for(; a; a = a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
