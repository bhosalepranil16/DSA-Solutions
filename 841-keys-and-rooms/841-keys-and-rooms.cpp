class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n ,false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            
            for(int v : rooms[u]) {
                if(!visited[v]) {
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};