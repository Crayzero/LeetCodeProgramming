#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *s, *f;
        s = head->next;
        f = head->next->next;
        while(f && f->next && s && f != s) {
            f = f->next->next;
            s = s->next;
        }
        if (f == s && s != NULL) {
            return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *s, *f;
        s = head->next;
        f = head->next->next;
        while(f && f->next && s && f != s) {
            f = f->next->next;
            s = s->next;
        }
        if (f == NULL || s == NULL || f->next == NULL) {
            return NULL;
        }
        while(s != head) {
            s = s->next;
            head = head->next;
        }
        return s;
        int cur_size = getSize(head, f);
        ListNode *t = f->next;
        for(;t != f; t = t->next) {
            if (getSize(head, t) < cur_size) {
                break;
            }
        }
        return t;
    }
    int getSize(ListNode *head, ListNode *end) {
        int size = 0;
        for(;head != end;head = head->next, size++);
        return size;
    }
};

int main()
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = d;
    Solution s;
    //cout<<s.hasCycle(a)<<endl;
    ListNode *res = s.detectCycle(a);
    if (res) {
        cout<<res->val<<endl;
    }
    else {
        cout<<"No Cycle";
    }
    return 0;
}
