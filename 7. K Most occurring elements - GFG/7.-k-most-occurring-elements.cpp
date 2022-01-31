// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

struct myCmp {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        return a.second < b.second;
    }
};

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here	
    	unordered_map<int, int> mp;
    	
    	for(int i=0;i<n;i++) {
    	    mp[arr[i]]++;
    	}
    	
    	priority_queue<pair<int, int>, vector<pair<int, int> >, myCmp> pq(mp.begin(), mp.end());
    	
    	int res = 0;
    	for(int i=0;i<k;i++) {
    	    pair<int, int> a = pq.top();
    	    pq.pop();
    	    res += a.second;
    	}
    	return res;
    } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends