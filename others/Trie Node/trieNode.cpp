#include <bits/stdc++.h>
#define int long long int
using namespace std;

//example of a trie structure
class TrieNode {
public:
    char s;
    unordered_map<char, TrieNode*> children;
    string word;
    bool isTerminal;

    TrieNode(char s) {
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void addWord(string word) {
        //O(word.size())
        TrieNode* temp = root;
        for (auto ch : word) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        //last node
        temp->isTerminal = true;
        temp->word = word;
    }
    bool searchWord(string word) {
        //O(word.size())
        TrieNode* temp = root;
        for (auto ch : word) {
            if (temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->isTerminal;
    }
};

void solve() {
    Trie t;
    t.addWord("hello");
    t.addWord("hell");
    cout << t.searchWord("hello") << endl;
    cout << t.searchWord("hell") << endl;
    cout << t.searchWord("hel") << endl;

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}