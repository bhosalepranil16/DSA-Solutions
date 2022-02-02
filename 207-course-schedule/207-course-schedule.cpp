class Solution {
public:
    
    bool isCycle(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int> > mp;
        vector<bool> visited(numCourses, false), st(numCourses, false);
        
        for(int i=0;i<prerequisites.size();i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++) {
            if(!visited[i]) {
                if(dfs(mp, visited, st, i)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(map<int, vector<int> > &mp, vector<bool> &visited, vector<bool> &st, int u) {
        visited[u] = true;
        st[u] = true;
        
        for(int v : mp[u]) {
            if(!visited[v]) {
                if(dfs(mp, visited, st, v)) {
                    return true;
                }
            } else if(st[v]) {
                return true;
            }
        }
        st[u] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) {
            return true;
        }
        bool res = !isCycle(numCourses, prerequisites);
        return res;
    }
};