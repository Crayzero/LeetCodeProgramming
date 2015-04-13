#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return NULL;
        }
        return f(num, 0, num.size());
    }
    TreeNode * f(vector<int> &num, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int mid = (start + end)/2;
        int mid_val = num[mid];
        TreeNode *root = new TreeNode(mid_val);
        cout<<root->val<<endl;
        root->left = f(num, start, mid);
        root->right = f(num, mid+1, end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* slow, *fast;
        slow = head;
        fast = head->next;
        ListNode* prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        if (prev != NULL) {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        return root;
    }
    TreeNode *f(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode *s, *fast;
        s = fast = head;
        while(fast->next != tail && fast->next->next != tail) {
            s = s->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(s->val);
        cout<<root->val<<endl;
        root->left = f(head, s);
        root->right = f(s->next, tail);
        return root;
    }
};

int main()
{
    vector<int> nums = {1,2};
    Solution s;
    //root = s.sortedArrayToBST(nums);
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    //a->next = b;
    //b->next = c;
    //c->next = d;
    //d->next = e;
    s.sortedListToBST(NULL);
    return 0;
}
