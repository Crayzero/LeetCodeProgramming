#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) {
            return head;
        }
        ListNode *new_head = NULL;
        ListNode *p = head;
        ListNode *left = NULL;
        ListNode *right, *right_tail;
        right= right_tail= NULL;
        for(;p;p = p->next) {
            if (p->val < x) {
                if(left == NULL) {
                    left = p;
                    new_head = left;
                }
                else {
                    left->next = p;
                    left = left->next;
                }
            }
            else {
                if (right == NULL) {
                    right = right_tail = p;
                }
                else {
                    right_tail->next = p;
                    right_tail = right_tail->next;
                }
            }
        }
        if(right_tail) {
            right_tail->next = NULL;
        }
        if (left) {
            left->next = right;
            return new_head;
        }
        return right;
    }
};
int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(2);
    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(2);
    a->next = b;
    //b->next = c;
    //c->next = d;
    //d->next = e;
    //e->next = f;
    a = s.partition(a, 10);
    for(;a;a=a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
