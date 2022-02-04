// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	vector<int> topologicalSort(int V, vector<int> adj[]) {
	    vector<bool> visited(V, false);
	    stack<int> st;
	    vector<int> res;
	    
	    for(int i=0;i<V;i++) {
	        if(!visited[i]) {
	            dfsTopologicalSort(adj, visited, st, i);
	        }
	    }
	    
	    while(!st.empty()) {
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	    
	}
	
	void dfsTopologicalSort(vector<int> adj[], vector<bool> &visited, stack<int> &st, int u) {
	    
	    visited[u] = true;
	    
	    for(int v : adj[u]) {
	        if(!visited[v]) {
	            dfsTopologicalSort(adj, visited, st, v);
	        }
	    }
	    
	    st.push(u);
	}
	
    
    void dfs(map<int, vector<int> > &mp, vector<bool> &visited, int u) {
        
        visited[u] = true;
        
        for(int v: mp[u]) {
            if(!visited[v]) {
                dfs(mp, visited, v);
            }
        }
    }
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> arr = topologicalSort(V, adj);
        
        map<int, vector<int> > mp;
        for(int i=0;i<V;i++) {
            for(int a : adj[i]) {
                mp[a].push_back(i);
            }
        }
        
        int res = 0;
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++) {
            if(!visited[arr[i]]) {
                dfs(mp, visited, arr[i]);
                res++;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends