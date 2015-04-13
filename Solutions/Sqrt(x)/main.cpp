#include <iostream>

using namespace std;

class ListNode {
public:
    ListNode(void *start, size_t size): start((int *)start), size(size),next(NULL) {}
    ~ListNode() {}
    ListNode *next;
    int *start;
    size_t size;
};

class FreeList {
public:
    FreeList(size_t size): used(0), cap(size), n(NULL) {
        start = (int *)new int (size);
    }
    void *alloc(size_t size) {
        if (used + size > cap) {
            get_more(cap*2);
            return alloc(size);
        }
        used += size;
        ListNode *p = n;
        while(p->next) {
            size_t c = p->next->start - p->start - p->size;
            if (c > size) {
                ListNode *t = new ListNode(p->start + p->size, size);
                ListNode *next = p->next;
                p->next = t;
                t->next = next;
                return t->start;
            }
        }
        ListNode *t = new ListNode(p->start + p->size, size);
        p->next = t;
        return t->start;
    }
    int free(void * p) {
        ListNode *p2 = n;
        if (p2->start == p) {
            n = p2->next;
            delete p2->start;
            p2->start = NULL;
            p2->size = 0;
        }
        while(p2->next) {
            if (p2->next->start == p) {
                ListNode *t = p2->next;
                used -= t->size;
                p2->next = p2->next->next;
                delete t->start;
                t->start = NULL;
                t->size = 0;
            }
        }
    }
    ~FreeList();
private:
    void *get_more(size_t size);
    void *start;
    ListNode *n;
    size_t used;
    size_t cap;
};

class Solution {
public:
    int sqrt(int x) {
        int left = 0;
        int right = x > 65536? 65536 : x;
        while(left < right) {
            int mid = (left + right)/2;
            cout<<mid<<endl;
            if (mid * mid <= x && mid*mid > 0) {
                if (((mid+1) * (mid+1)) > x || ((mid+1) * (mid+1)) < 0)
                return mid;
            }
            if (mid*mid > 0 && mid * mid < x) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    cout<<s.sqrt(2147395600);
    return 0;
}
