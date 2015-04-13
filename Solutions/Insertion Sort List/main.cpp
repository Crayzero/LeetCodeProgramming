#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *ph = head;
        for(;ph->next!= NULL;) {
            ListNode *ph_next = ph->next;
            if (head->val >= ph_next->val) {
                ph->next = ph_next ->next;
                ph_next->next = head;
                head = ph_next;
            }
            else {
                ListNode *t = head;
                for(; t!= ph; t = t->next) {
                    if (t->next->val > ph_next->val) {
                        break;
                    }
                }
                if (t != ph) {
                    ph->next = ph_next->next;
                    ListNode *tmp = t->next;
                    t->next = ph_next;
                    ph_next->next = tmp;
                }
                else {
                    ph = ph->next;
                }
            }
            for(ListNode *t2 = head; t2; t2 = t2->next) {
                cout<<t2->val<<" ";
            }
            cout<<endl;
        }
        return head;
    }
};

int main()
{
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);
    a->next = b;
    //b->next = c;
    Solution s;
    ListNode *head = s.insertionSortList(a);
    for(;head;head = head->next) {
        cout<<head->val<<" ";
    }
    cout<<endl;
    return 0;
}
