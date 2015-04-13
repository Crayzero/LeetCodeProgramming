#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head ->next == NULL) {
            return ;
        }
        ListNode *f, *s;
        f = s = head;
        while(f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        ListNode *right_head = s->next;
        s->next = NULL;
        right_head = reverseList(right_head);
        for(auto t = right_head; t; t = t->next) {
            cout<<t->val<<" ";
        }
        cout<<endl;
        for(;head && right_head;) {
            ListNode *left_next = head->next;
            ListNode *right_next = right_head->next;
            head->next = right_head;
            right_head->next = left_next;
            head = left_next;
            right_head = right_next;
        }
    }
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *t = head->next;
        head->next = NULL;
        while(t) {
            ListNode *next = t->next;
            t->next = head;
            head = t;
            t= next;
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
    ListNode *f = new ListNode(6);
    ListNode *g = new ListNode(7);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    Solution s;
    s.reorderList(a);
    for(auto h = a;h;h = h->next) {
        cout<<h->val<<" ";
    }
    cout<<endl;
    return 0;
}
