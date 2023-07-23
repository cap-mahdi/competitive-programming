#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*

    original problem : https://codeforces.com/contest/1847/problem/C
    statement : given an array of integers, find the maximum xor of a subarray

    Approach :
    1. We will use a TRIE to store the prefix xor of all the elements till that point
    2. We will insert 0 in the trie initially
    3. We will insert the prefix xor of the elements in the trie(so will have all the prefix xor of the elements until that point)
    4. We will query the trie for the maximum xor of the prefix xor of the elements(we will begin from the msb and check if the opposite bit is present in the trie, if yes then we will go to that node, else we will go to the same bit node)
    5. We will update the answer if required

    Time Complexity : O(n*32)
    Space Complexity : O(n*32)



*/
// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
    int value;  // Only used in leaf nodes
    TrieNode* arr[2];
};

// Utility function to create a Trie node
TrieNode* newNode()
{
    TrieNode* temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode* root, int pre_xor)
{
    //O(32)
    TrieNode* temp = root;

    // Start from the msb, insert all bits of
    // pre_xor into Trie
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1 << i);

        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();

        temp = temp->arr[val];
    }

    // Store value at leaf node
    temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode* root, int pre_xor)
{
    //O(32)
    TrieNode* temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1 << i);

        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[1 - val] != NULL)
            temp = temp->arr[1 - val];

        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor ^ (temp->value);
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
    //O(n*32)
    // Create a Trie and insert 0 into it
    TrieNode* root = newNode();
    insert(root, 0);

    // Initialize answer and xor of current prefix
    int result = INT_MIN, pre_xor = 0;

    // Traverse all input array element
    for (int i = 0; i < n; i++)
    {
        // update current prefix xor and insert it into Trie
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);

        // Query for current prefix xor in Trie and update
        // result if required
        result = max(result, query(root, pre_xor));
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSubarrayXOR(a, n) << "\n";

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
