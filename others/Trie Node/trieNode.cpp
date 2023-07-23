#include <bits/stdc++.h>
#define int long long int
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* root, string key) {
    //O(key.size())
    TrieNode* temp = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (temp->children[index] == NULL) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEnd = true;
}

bool search(TrieNode* root, string key) {
    //O(key.size())
    TrieNode* temp = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (temp->children[index] == NULL) {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp->isEnd);
}


void solve() {
    TrieNode* root = getNode();
    insert(root, "hello");
    insert(root, "world");
    cout << search(root, "hello") << endl;
    cout << search(root, "hell") << endl;
    cout << search(root, "world") << endl;
    cout << search(root, "wor") << endl;

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}