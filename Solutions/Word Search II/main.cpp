#include <iostream>
#include <vector>
#include <unordered_set>
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

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto iter = words.begin(); iter != words.end(); iter++) {
            t.insert(*iter);
        }
        return findWords(board, t);
    }
    vector<string> findWords(vector<vector<char >> &board, Trie &t) {
        unordered_set<string> res;
        size_t x_size = board.size();
        size_t y_size = board[0].size();
        for(size_t i = 0; i < x_size; i++) {
            for(size_t j = 0; j < y_size; j++) {
                vector<string> tmp = search(board, i, j, "", t);
                for(auto iter = tmp.begin(); iter != tmp.end(); iter++)
                    res.insert(*iter);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    vector<string> search(vector<vector<char >> &board, int x, int y, string s, Trie &t) {
        unordered_set<string > res;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '*')
            return vector<string>();
        s.push_back(board[x][y]);
        cout<<s<<endl;
        if (!t.startsWith(s))
            return vector<string>();
        else {
            if (t.search(s))
                res.insert(s);
            char c = board[x][y];
            board[x][y] = '*';
            vector<string> t_res = search(board, x+1, y, s, t);
            for(auto iter = t_res.begin(); iter != t_res.end(); iter++)
                res.insert(*iter);
            t_res = search(board, x-1, y, s, t);
            for(auto iter = t_res.begin(); iter != t_res.end(); iter++)
                res.insert(*iter);
            t_res = search(board, x, y+1, s, t);
            for(auto iter = t_res.begin(); iter != t_res.end(); iter++)
                res.insert(*iter);
            t_res = search(board, x, y-1, s, t);
            for(auto iter = t_res.begin(); iter != t_res.end(); iter++)
                res.insert(*iter);
            board[x][y] = c;
        }
        return vector<string>(res.begin(), res.end());
    }
};

int main()
{
    vector<vector<char >> board = {{'a','b'}, {'a','a'}};
    vector<string> words = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    Solution s;
    vector<string> res = s.findWords(board, words);
    cout<<"result is:"<<endl;
    for(auto iter = res.begin(); iter != res.end(); iter++)
        cout<<*iter<<endl;
    return 0;
}
