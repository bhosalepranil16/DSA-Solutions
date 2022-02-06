class Solution {
    
    vector<int> parent, rank;
    
public:
    
    void initialize(int n) {
        for(int i=0;i<=n;i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool makeUnion(int x, int y) {
        int x_rep = find(x), y_rep = find(y);
        
        if(x_rep == y_rep) {
            return false;
        }
        
        if(rank[x_rep] < rank[y_rep]) {
            parent[x_rep] = y_rep;
        } else if(rank[x_rep] > rank[y_rep]) {
            parent[y_rep] = x_rep;
        } else {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        initialize(n);
        
        for(vector<int> a : edges) {
            if(!makeUnion(a[0], a[1])) {
                return a;
            }
        }
        return edges[0];
    }
};