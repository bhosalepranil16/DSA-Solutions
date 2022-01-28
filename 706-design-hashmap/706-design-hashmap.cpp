class Node {
    public:
    pair<int, int> data;
    Node *left, *right;
    Node() {
        data = make_pair(0, 0);
        left = right = NULL;
    }
    Node(pair<int, int> x) {
        data = x;
        left = right = NULL;
    }
};

class MyHashMap {
public:
    Node *root;
    MyHashMap() {
        root = NULL;
    }
    
    void put(int key, int value) {
        root = insert(root, key, value);
    }
    
    int get(int key) {
        return search(root, key);
    }
    
    void remove(int key) {
        root = deleteNode(root, key);
    }
    
    Node* insert(Node *root, int key, int value) {
        if(root == NULL) {
            return new Node(make_pair(key, value));
        } else if(key < root->data.first) {
            root->left = insert(root->left, key, value);
            return root;
        } else if(key > root->data.first) {
            root->right = insert(root->right, key, value);
            return root;
        } else {
            root->data.second = value;
            return root;
        }
    }
    
    int search(Node *root, int key) {
        if(root == NULL) {
            return -1;
        } else if(key < root->data.first) {
            return search(root->left, key);
        } else if(key > root->data.first) {
            return search(root->right, key);
        } else {
            return root->data.second;
        }
    }
    
    Node* deleteNode(Node *root, int key) {
        if(root == NULL) {
            return NULL;
        } else if(key < root->data.first) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if(key > root->data.first) {
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
                root->right = deleteNode(root->right, q->data.first);
                return root;
            }
        }
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */