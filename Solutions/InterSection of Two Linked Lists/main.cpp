class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        int size_A = getSize(headA);
        int size_B = getSize(headB);
        if (size_A > size_B) {
            for(int i = size_A - size_B; i>0; i--) {
                pa = pa->next;
            }
        }
        else{
            for(int j = size_B - size_A; j > 0; j--) {
                pb = pb->next;
            }
        }
        while(pa&&pa!=pb) {
            pa = pa->next;
            pb = pb->next;
        }
        if (pa) {
            return pa;
        }
        else {
            return NULL;
        }
    }
    int getSize(ListNode *A) {
        ListNode *p = A;
        int size = 0;
        for(;p;size++,p=p->next);
        return size;
    }
};