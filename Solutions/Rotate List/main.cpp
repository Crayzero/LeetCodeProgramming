#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *p_end = p;
        int cnt = 0;
        while(k--) {
            p_end = p_end->next;
            cnt++;
            if (p_end == NULL) {
                p_end = head;
                k = k % cnt;
            }
        }
        if (p_end == p) {
            return head;
        }
        while(p_end->next != NULL) {
            p = p->next;
            p_end = p_end->next;
        }
        p_end->next = head;
        ListNode *new_head = p->next;
        p->next = NULL;
        return new_head;
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
    a = s.rotateRight(a, 12);
    for(;a; a=a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
