#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        c = 0;
        word = false;
    }
    TrieNode(char ct):c(ct), word(false) {}

    char getc() {return c;}
    TrieNode *insert(char pc) {
        TrieNode *t = get(pc);
        if (t != NULL) return t;
        TrieNode *p = new TrieNode(pc);
        cout<<c<<" push "<<pc<<endl;
        child.push_back(p);
        return p;
    }
    bool search(char pc) {
        if (get(pc) == NULL) return false;
        return true;
    }
    TrieNode *get(char pc) {
        for(auto iter = child.begin(); iter != child.end(); iter++) {
            if ((*iter)->getc() == pc)
                return *iter;
        }
        return NULL;
    }
    bool isWord() {
        return word;
    }
    void setWord() {
        word = true;
    }
private:
    char c;
    bool word;
    vector<TrieNode *> child;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            p = p->insert(*iter);
        }
        p->setWord();
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        for(auto iter = key.begin(); iter != key.end(); iter++) {
            if (p->search(*iter)) {
                p = p->get(*iter);
            }
            else
                return false;
        }
        return p->isWord();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(auto iter = prefix.begin(); iter != prefix.end(); iter++) {
            if (p->search(*iter))
                p = p->get(*iter);
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie trie;
    trie.insert("A");
    trie.insert("to");
    trie.insert("tea");
    trie.insert("ted");
    trie.insert("ten");
    trie.insert("i");
    trie.insert("in");
    trie.insert("inn");
    cout<<trie.search("A")<<endl;
    cout<<trie.startsWith("inna")<<endl;
    return 0;
}
