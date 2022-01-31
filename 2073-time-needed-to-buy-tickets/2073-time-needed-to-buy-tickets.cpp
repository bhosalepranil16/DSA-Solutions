class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int> > q;
        int n = tickets.size();
        int res = 0;
        
        for(int i=0;i<n;i++) {
            q.push(make_pair(tickets[i], i));
        }
        
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            curr.first--;
            res++;
            if(curr.first == 0 && curr.second == k) {
                break;
            }
            if(curr.first > 0) {
                q.push(curr);
            }
        }
        
        return res;
    }
};