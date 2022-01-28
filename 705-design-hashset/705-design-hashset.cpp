class Node {
    public:
    int data;
    Node *left, *right;
    Node() {
        data = 0;
        left = right = NULL;
    }
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class MyHashSet {
public:
    Node *root;
    MyHashSet() {
        root = NULL;
    }
    
    void add(int key) {
        root = insert(root, key);
    }
    
    void remove(int key) {
        root = deleteNode(root, key);
    }
    
    bool contains(int key) {
        return search(root, key);
    }
    
    Node* insert(Node *root, int key) {
        if(root == NULL) {
            return new Node(key);
        } else if(key < root->data) {
            root->left = insert(root->left, key);
            return root;
        } else if(key > root->data) {
            root->right = insert(root->right, key);
            return root;
        } else {
            return root;
        }
    }
    
    bool search(Node *root, int key) {
        if(root == NULL) {
            return false;
        } else if(key < root->data) {
            return search(root->left, key);
        } else if(key > root->data) {
            return search(root->right, key);
        } else {
            return true;
        }
    }
    
    Node* deleteNode(Node *root, int key) {
        if(root == NULL) {
            return NULL;
        } else if(key < root->data) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if(key > root->data) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if(root->left == NULL) {
                Node *q = root->right;
                delete root;
                return q;
            } else if(root->right == NULL) {
                Node *q = root->left;
                delete root;
                return q;
            } else {
                Node *q = root->right;
                while(q != NULL && q->left != NULL) {
                    q = q->left;
                }
                root->data = q->data;
                root->right = deleteNode(root->right, q->data);
                return root;
            }
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */