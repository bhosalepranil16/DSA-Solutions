/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        map<int, Employee*> mp;
        map<int, bool> visited;
        queue<int> q;
        
        for(Employee *e : employees) {
            mp[e->id] = e;
            visited[e->id] = false;
        }
        
        int res = 0;
        
        q.push(id);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            visited[u] = true;
            Employee *e = mp[u];
            res += e->importance;
            
            for(int v : e->subordinates) {
                if(!visited[v]) {
                    q.push(v);
                }
            }
        }
        
        return res;
    }
};