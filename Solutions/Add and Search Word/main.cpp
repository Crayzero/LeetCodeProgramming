#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Trie;

class TrieNode {
friend class Trie;
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
        //cout<<c<<" push "<<pc<<endl;
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

    bool match(string word) {
        return match(word, 0, root);
    }
    bool match(string word, size_t i, TrieNode *p) {
        if (i == word.size() && p->isWord())
            return true;
        if (word[i] != '.') {
            p = p->get(word[i]);
            if (p == NULL)
                return false;
            else
                return match(word, i + 1, p);
        }
        else {
            for(auto iter = p->child.begin(); iter != p->child.end(); iter++) {
                if (match(word, i+1, *iter))
                    return true;
            }
        }
        return false;
    }

private:
    TrieNode* root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.match(word);
    }
private:
    Trie trie;
};

int main()
{
    WordDictionary w;
    w.addWord("at");
    w.addWord("and");
    w.addWord("an");
    w.addWord("add");
    w.addWord("bat");
    cout<<w.search("a")<<endl;
    cout<<w.search(".at")<<endl;
    cout<<w.search("b.")<<endl;
    return 0;
}
