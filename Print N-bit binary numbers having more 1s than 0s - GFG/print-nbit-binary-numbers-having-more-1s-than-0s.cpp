// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void solve(int ones, int zeroes, int N, string s, vector<string> &res) {
        
        if(N == 0) {
            res.push_back(s);
            return;
        }
        
        solve(ones+1, zeroes, N-1, s+"1", res);
        if(ones > zeroes) {
            solve(ones, zeroes+1, N-1, s+"0", res);
        }
        
    }
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> res;
	    solve(0, 0, N, "", res);
	    return res;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends