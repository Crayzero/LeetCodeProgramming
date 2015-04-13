#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head, *prev;
        head = prev = NULL;
        while(p1 && p2) {
            if (p1->val <= p2->val) {
                if (prev) prev->next = p1;
                else head = p1;
                prev = p1;
                p1 = p1->next;
            }
            else {
                if (prev) prev->next = p2;
                else head = p2;
                prev = p2;
                p2 = p2->next;
            }
        }
        if (p1) {
            if (prev) prev->next = p1;
            else head = p1;
        }
        if (p2) {
            if (prev) prev->next = p2;
            else head = p2;
        }
        return head;
    }
};
int main()
{
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(6);
    ListNode *b1 = new ListNode(2);
    ListNode *b2 = new ListNode(4);
    ListNode *b3 = new ListNode(5);
    b1->next = b2;
    b2->next = b3;
    Solution s;
    a1 = s.mergeTwoLists(a1, b1);
    for(;a1; a1 = a1->next) cout<<a1->val<<" ";
    return 0;
}
