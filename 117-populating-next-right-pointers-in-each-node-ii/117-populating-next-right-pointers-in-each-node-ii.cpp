/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*> > arr;
        if(root == NULL) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()) {
            vector<Node*> temp;
            int x = que.size();
            for(int i=0;i<x;i++) {
                Node *curr = que.front();
                que.pop();
                temp.push_back(curr);
                if(curr->left != NULL) {
                    que.push(curr->left);
                }
                if(curr->right != NULL) {
                    que.push(curr->right);
                }
            }
            arr.push_back(temp);
        }
        for(int i=1;i<arr.size();i++) {
            for(int j=0;j<arr[i].size()-1;j++) {
                arr[i][j]->next = arr[i][j+1];
            }
        }
        return root;
    }
};