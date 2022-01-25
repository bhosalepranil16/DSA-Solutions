// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends



//Function to check if any pair exists in BST whose sum is equal to given value.

void inorder(Node *root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool findPair(Node* root, int X) 
{
    // Your code here
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    int low = 0, high = n-1;
    
    while(low < high) {
        int sum = arr[low] + arr[high];
        if(sum == X) {
            return true;
        } else if(sum < X) {
            low++;
        } else {
            high--;
        }
    }
    
    return false;
}



