// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class Triplet {
    public:
    int val, arrIndex, eleIndex;
    Triplet(int v, int a, int e) {
        val = v;
        arrIndex = a;
        eleIndex = e;
    }
};

struct myCmp {
    bool operator()(Triplet const& t1, Triplet const& t2) {
        return t1.val > t2.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<Triplet, vector<Triplet>, myCmp> pq;
        
        for(int i=0;i<K;i++) {
            pq.push(Triplet(arr[i][0], i, 0));
        }
        
        // for(int i=0;i<K;i++) {
        //     Triplet curr = pq.top();
        //     pq.pop();
        //     cout << curr.val << " " << curr.arrIndex << " " << curr.eleIndex << endl;
        // }
        
        while(!pq.empty()) {
            Triplet curr = pq.top();
            pq.pop();
            // cout << curr.val << " " << curr.arrIndex << " " << curr.eleIndex << endl;
            res.push_back(curr.val);
            
            int ai = curr.arrIndex, ei = curr.eleIndex;
            if(ei + 1 < K) {
                Triplet t(arr[ai][ei+1], ai, ei+1);
                pq.push(t);
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends