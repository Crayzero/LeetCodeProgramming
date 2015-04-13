#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *p = head;
        while(p) {
            ListNode *next = p->next;
            if (prev == NULL || prev->val != p->val) {
                prev = p;
            }
            else {
                delete p;
                prev->next = next;
            }
            p = next;
        }
        return head;
    }
    ListNode *deleteDuplicates2(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *p = head;
        int flag = 0;
        while(p) {
            ListNode *next = p->next;
            if (next && next->val == p->val) {
                flag = 1;
            }
            while(next && next->val == p->val) {
                p->next = next->next;
                delete next;
                next = p->next;
            }
            if (flag) {
                if (prev && prev != p) {
                    prev->next = next;
                }
                else {
                    head = prev = next;
                }
                delete p;
                flag = 0;
            }
            else {
                prev = p;
            }
            p = next;
        }
        return head;
    }
};
int main()
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(3);
    Solution s;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    //a = s.deleteDuplicates(a);
    a = s.deleteDuplicates2(a);
    for(;a; a = a->next) {
        cout<<a->val<<" ";
    }
    cout<<endl;
    return 0;
}
