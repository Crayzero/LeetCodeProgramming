#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //return f1(head);
        return f2(head, head ? head->next : NULL, head);
    }
    ListNode* f1(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *new_head = head;
        ListNode *p = head->next;
        while(p) {
            ListNode *next = p->next;
            p->next = new_head;
            new_head = p;
            head->next = next;
            p = next;
            for(ListNode *t = new_head; t; t = t ->next)
                cout<<t->val<<" ";
            cout<<endl;
        }
        return new_head;
    }
    ListNode* f2(ListNode *head, ListNode *p, ListNode *tail) {
        if (head == NULL || p == NULL) {
            return head;
        }
        ListNode *next = p->next;
        p->next = head;
        tail->next = next;
        head = p;
        for(ListNode *t = head; t; t = t ->next)
            cout<<t->val<<" ";
        cout<<endl;
        return f2(head, next, tail);
    }
};

int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    //a->next = b;
    //b->next = c;
    //c->next = d;
    a =s.reverseList(NULL);
    for(; a; a = a->next)
        cout<<a->val<<" ";
    return 0;
}
