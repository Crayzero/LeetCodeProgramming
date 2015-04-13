#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    void push(int x) {
        v.push_back(x);
        if (v_min_index.size() == 0) {
            v_min_index.push_back(0);
        }
        else {
            int min_index = v_min_index.back();
            int &min = v.at(min_index);
            if(x < min) {
                v_min_index.push_back(v_min_index.size());
            }
            else {
                v_min_index.push_back(min_index);
            }
        }
    }

    void pop() {
        v.pop_back();
        v_min_index.pop_back();
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return v.at(v_min_index.back());
    }
private:
    vector<int > v;
    vector<int > v_min_index;
};

int main()
{
    MinStack s;
    s.push(3);
    s.push(4);
    cout<<s.getMin()<<endl;
    s.push(1);
    cout<<s.getMin()<<endl;
    s.push(2);
    cout<<s.getMin()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.getMin()<<" "<<s.top()<<endl;
    return 0;
}
