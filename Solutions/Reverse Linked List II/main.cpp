#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *prev = head;
        for(int i = 1; i< m-1; i++) {
            prev = prev->next;
        }
        if (m == 1) {
            prev = new ListNode(-1);
            prev->next = head;
        }
        ListNode *p = prev->next;
        prev->next = NULL;
        ListNode *tail = p;
        for(int j = 0; j <= n - m; j++) {
            ListNode *next = p->next;
            p->next = prev->next;
            prev->next = p;
            p = next;
        }
        tail->next = p;
        if (m == 1) {
            head = prev->next;
            delete prev;
            return head;
        }
        return head;
    }
};

int main()
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Solution s;
    a = s.reverseBetween(a, 1, 2);
    while(a) {
        cout<<a->val<<" ";
        a = a->next;
    }
    return 0;
}
