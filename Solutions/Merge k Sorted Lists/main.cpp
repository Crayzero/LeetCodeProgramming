#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        return sortList(lists, 0, lists.size());
    }
    ListNode* sortList(vector<ListNode *> &lists, int start, int end) {
        if (end - start <= 1) {
            return lists[start];
        }
        ListNode *left = sortList(lists, start, (start+ end)/2);
        ListNode *right = sortList(lists, (start+end)/2, end);
        return mergeList(left, right);
    }
    ListNode* mergeList(ListNode *left, ListNode *right) {
        ListNode *head = NULL,*p = NULL;
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        head = left->val <= right->val ? left: right;
        while(left && right) {
            if (left->val <= right->val) {
                if (p) {
                    p->next = left;
                }
                p = left;
                left = left->next;
            }
            else {
                if (p) {
                    p->next = right;
                }
                p = right;
                right = right->next;
            }
        }
        ListNode *tail = head;
        for(;tail->next; tail = tail->next);
        if (left) {
            tail->next = left;
        }
        if (right) {
            tail->next = right;
        }
        return head;
    }
};

int main()
{
    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(7);
    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(2);
    ListNode *f = new ListNode(5);
    ListNode *g = new ListNode(6);
    a->next = b;
    //b->next = c;
    d->next = e;
    //e->next = f;
    f->next = g;
    g->next = c;
    vector<ListNode *> lists = {
    };
    Solution s;
    a = s.mergeKLists(lists);
    for(;a; a = a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
