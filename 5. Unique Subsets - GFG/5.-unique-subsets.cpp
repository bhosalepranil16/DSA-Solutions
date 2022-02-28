// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    void dfs(vector<int> arr, int n, int i, vector<int> nums, set<vector<int> > &s) {
        
        if(i == n) {
            s.insert(nums);
            return;
        }
        
        dfs(arr, n, i+1, nums, s);
        nums.push_back(arr[i]);
        dfs(arr, n, i+1, nums, s);
        
        
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        set<vector<int> > s;
        vector<int> nums;
        vector<vector<int> > res;
        sort(arr.begin(), arr.end());
        dfs(arr, n, 0, nums, s);
        
        for(vector<int> a : s) {
            res.push_back(a);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends