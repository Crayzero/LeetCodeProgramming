#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode *prev_tail, *new_head;
        prev_tail = new_head = NULL;
        ListNode *tail = NULL;
        while(head) {
            tail = head;
            for(int i = 1; tail && i < k; i++) {
                tail = tail->next;
            }
            ListNode *next = tail? tail->next: NULL;
            if (tail) {
                reverse(head, tail);
            }
            if (new_head == NULL) {
                new_head = head;
            }
            if (prev_tail) {
                prev_tail -> next = head;
            }
            prev_tail = tail;
            head = next;
        }
        return new_head;
    }
    void reverse(ListNode *&head, ListNode * &tail) {
        ListNode *new_tail = head;
        ListNode *p = head->next;
        head->next = tail ? tail->next: NULL;
        for(;p != tail;) {
            ListNode *next = p->next;
            p->next = head;
            head = p;
            p = next;
        }
        if (tail ) {
            tail->next = head;
            head = tail;
            tail = new_tail;
            tail->next = NULL;
        }
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
    //b->next = c;
    //c->next = d;
    //d->next = e;
    Solution s;
    a = s.reverseKGroup(a, 3);
    for(;a; a = a->next) {
        cout<<a->val<<"->";
    }
    return 0;
}
