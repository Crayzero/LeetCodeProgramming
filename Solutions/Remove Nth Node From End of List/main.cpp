#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *left, *right;
        left = head;
        right = head->next;
        while(n-- && right) {right = right->next;}
        if (right == NULL ) {
            if (n == 0) {
                head = left->next;
                delete left;
                return head;
            }
            else if (n > 0){
                return head;
            }
        }
        while(right) {
            left = left->next;
            right = right->next;
        }
        ListNode *rm = left->next;
        left->next = rm ? rm->next : NULL;
        if(rm) delete rm;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    a = s.removeNthFromEnd(a,10);
    for(; a; a = a->next) {
        cout<<a->val<<" ";
    }
    return 0;
}
