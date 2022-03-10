// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *, string key);

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *, string key);

// Driver
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();

        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        while (q--) {
            string key;
            cin >> key;
            if (search(root, key))
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++


//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    int n = key.length();
    for(int i=0;i<n;i++) {
        int ind = (int) key[i] - 'a';
        if(root->children[ind] == NULL) {
            root->children[ind] = new TrieNode();
        }
        root = root->children[ind];
    }
    root->isEndOfWord = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    int n = key.length();
    for(int i=0;i<n;i++) {
        int ind = (int) key[i] - 'a';
        if(root->children[ind] == NULL) {
            return false;
        }
        root = root->children[ind];
    }
    return root->isEndOfWord;
}

