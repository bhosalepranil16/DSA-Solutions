class Node {
    public:
    vector<Node*> arr;
    bool isEnd;
    
    Node() {
        arr = vector<Node*>(26, NULL);
        isEnd = false;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *r = root;
        int n = word.length();
        for(int i=0;i<n;i++) {
            int ind =(int) word[i] - 'a';
            if(r->arr[ind] == NULL) {
                r->arr[ind] = new Node();
            }
            r = r->arr[ind];
        }
        r->isEnd = true;
    }
    
    bool search(string word) {
        Node *r = root;
        int n = word.length();
        
        for(int i=0;i<n;i++) {
            int ind =(int) word[i] - 'a';
            if(r->arr[ind] == NULL) {
                return false;
            }
            r = r->arr[ind];
        }
        return r->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *r = root;
        int n = prefix.length();
        
        for(int i=0;i<n;i++) {
            int ind = (int) prefix[i] - 'a';
            if(r->arr[ind] == NULL) {
                return false;
            }
            r = r->arr[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */