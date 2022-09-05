/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        
        if(root == nullptr) {
            return res;
        }
        
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()) {
            int x = que.size();
            vector<int> temp;
            for(int i=0;i<x;i++) {
                Node *p = que.front();
                que.pop();
                temp.push_back(p->val);
                for(Node *q: p->children) {
                    que.push(q);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};