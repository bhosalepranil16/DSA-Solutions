// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string S, int l, int r, vector<string> &res) {
	        if(l == r) {
	            res.push_back(S);
	            return;
	        }
	        for(int i=l;i<=r;i++) {
	            swap(S[i], S[l]);
	            solve(S, l+1, r, res);
	            swap(S[i], S[l]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    solve(S, 0, S.length()-1, res);
		    sort(res.begin(), res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends