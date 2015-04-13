#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (kvs.find(key) == kvs.end()) {
            return -1;
        }
        freshKey(key);
        return kvs[key];
    }

    void set(int key, int value) {
        if (kvs.find(key) != kvs.end()) {
            freshKey(key);
            kvs[key] = value;
            return ;
        }
        else {
            kvs[key] = value;
            if (static_cast<int>(keys.size()) < cap) {
                keys.push_back(key);
                key_its[key] = --keys.end();
            }
            else {

                int tmp_key = keys.front();
                keys.erase(keys.begin());
                keys.push_back(key);
                kvs.erase(kvs.find(tmp_key));
                key_its.erase(key_its.find(tmp_key));
                key_its[key] = --keys.end();
            }
        }
        for(auto beg = keys.begin(); beg != keys.end(); beg++) {
            cout<<*beg<<" ";
        }
        cout<<endl;
    }

    int cap;
    list<int > keys;
    unordered_map<int, int > kvs;
    unordered_map<int, list<int >::iterator> key_its;

    void freshKey(int key) {
        list<int >::iterator key_it = key_its[key];
        keys.erase(key_it);
        keys.push_back(key);
        key_its[key] = --keys.end();
    }
};

int main()
{
    LRUCache lru(1);
    lru.set(2,1);
    cout<<lru.get(1)<<endl;
    lru.set(1,1);
    cout<<lru.get(2)<<endl;
    lru.set(4,1);
    cout<<lru.get(1)<<endl;
    cout<<lru.get(2)<<endl;
    return 0;
}
