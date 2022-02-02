class Solution {
public:
    
    bool isCycle(map<int, vector<int> > &mp, int n) {
        vector<bool> visited(n, false), st(n, false);
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                if(dfsCycle(mp, visited, st, i)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfsCycle(map<int, vector<int> > &mp, vector<bool> &visited, vector<bool> &st, int u) {
        visited[u] = true;
        st[u] = true;
        
        for(int v : mp[u]) {
            if(!visited[v]) {
                if(dfsCycle(mp, visited, st, v)) {
                    return true;
                }
            } else if(st[v]) {
                return true;
            }
        }
        st[u] = false;
        return false;
    }
    
    vector<int> topologicalSort(map<int, vector<int> > &mp, int n) {
        vector<bool> visited(n, false);
        stack<int> st;
        vector<int> res;
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfsTopologicalSort(mp, visited, st, i);
            }
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    
    void dfsTopologicalSort(map<int, vector<int> > &mp, vector<bool> &visited, stack<int> &st, int u) {
        visited[u] = true;
        
        for(int v : mp[u]) {
            if(!visited[v]) {
                dfsTopologicalSort(mp, visited, st, v);
            }
        }
        st.push(u);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        map<int, vector<int> > mp;
        
        for(int i=0;i<prerequisites.size();i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        if(isCycle(mp, numCourses)) {
            return res;
        }
        
        return topologicalSort(mp, numCourses);
        
    }
};