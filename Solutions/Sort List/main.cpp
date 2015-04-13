#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //head = quickSort(head, NULL);
        ListNode *f, *s;
        f = head->next;
        s = head;
        while(f != NULL && f->next != NULL) {
            f = f->next->next;
            s = s->next;
        }
        ListNode *l, *r;
        l = head;
        r = s->next;
        s->next = NULL;
        l = sortList(l);
        r = sortList(r);
        head = mergeTwoList(l,r);
        return head;
    }
    ListNode* quickSort(ListNode *head, ListNode *tail) {
        if (head == tail || head->next == tail) {
            return head;
        }
        ListNode *tmp = head->next;
        ListNode *left_head, *left_tail;
        ListNode *right_tail;
        left_head = left_tail = head;
        right_tail = head;
        for(;tmp != tail;) {
            ListNode *t = tmp->next;
            if (tmp->val <= head->val) {
                tmp->next = left_head;
                left_head = tmp;
            }
            else {
                right_tail->next = tmp;
                right_tail = tmp;
            }
            tmp = t;
        }
        right_tail->next = tail;
        for(tmp = left_head; tmp != NULL; tmp = tmp->next) {
            cout<<tmp->val<<" ";
        }
        cout<<endl;
        left_head = quickSort(left_head,head);
        head->next = quickSort(head->next, NULL);
        return left_head;
    }

    ListNode* mergeTwoList(ListNode *left, ListNode *right) {
        ListNode *h, *tmp;
        h = new ListNode(0);
        tmp = h;
        while(left != NULL && right != NULL) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
            }
            else {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        if (left != NULL) {
            tmp->next = left;
        }
        if (right != NULL) {
            tmp->next = right;
        }
        return h->next;
    }
};

int main()
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(2);
    a->next = b;
    b->next = c;
    Solution s;
    ListNode *new_head = s.sortList(a);
    while(new_head) {
        cout<<new_head->val<<" ";
        new_head = new_head->next;
    }
    cout<<endl;
    return 0;
}
