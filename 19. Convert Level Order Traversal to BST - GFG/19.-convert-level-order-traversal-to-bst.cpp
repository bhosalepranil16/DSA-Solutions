// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.

Node* insert(Node *root, int x) {
    if(root == NULL) {
        return new Node(x);
    } else if(root->data > x) {
        root->left = insert(root->left, x);
        return root;
    }  else if(root->data < x) {
        root->right = insert(root->right, x);
        return root;
    } else {
        return root;
    }
}

Node* constructBst(int arr[], int n)
{
    // Code here
    Node *root = NULL;
    for(int i=0;i<n;i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
