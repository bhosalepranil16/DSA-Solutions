// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &st, int src) {
        
        visited[src] = true;
        st[src] = true;
        
        for(int u : adj[src]) {
            if(!visited[u]) {
                if(dfs(adj, visited, st, u)) {
                    return true;
                }
            } else if(st[u]) {
                return true;
            }
        }
        st[src] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false), st(V, false);
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(adj, visited, st, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends