#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *p = head;
        ListNode *prev = NULL;
        while(p) {
            ListNode *next = p->next;
            ListNode *next_next = NULL;
            if (next) {
                next_next = next->next;
            }
            if (prev) {
                prev->next = next ? next : p;
            }
            if (next) {
                next->next = p;
                head = prev == NULL ? next : head;
            }
            p->next = next_next;
            prev = p;
            p = next_next;
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
    a = s.swapPairs(NULL);
    for(; a != NULL; a = a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
