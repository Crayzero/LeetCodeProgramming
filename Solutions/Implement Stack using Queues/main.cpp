#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int q_size = q.size();
        for(int i = 0; i < q_size-1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        int q_size = q.size();
        int top = q.front();
        for(int i = 0; i < q_size; i++) {
            top = q.front();
            q.pop();
            q.push(top);
        }
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

int main()
{
    Stack s;
    s.push(1);
    //s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}
