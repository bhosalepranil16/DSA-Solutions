// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
    	// Your code here
    	vector<int> hash(26, 0);
    	int n = str.length();
    	int maxIndex = 0;
    	
    	for(int i=0;i<n;i++) {
    	    int ind = (int) str[i] - 'a';
    	    hash[ind]++;
    	    if(hash[ind] > hash[maxIndex]) {
    	        maxIndex = ind;
    	    }
    	}
    	
    	if(2 * hash[maxIndex] - 1 > n) {
    	    return "";
    	}
    	
    	string res(n, 'a');
    	int i = 0;
    	
    	while(hash[maxIndex] > 0) {
    	    res[i] = (char) maxIndex + 'a';
    	    i += 2;
    	    hash[maxIndex]--;
    	}
    	
    	for(int j=0;j<26;j++) {
    	    while(hash[j] > 0) {
    	        if(i >= n) {
    	            i = 1;
    	        }
    	        res[i] = (char) j + 'a';
    	        hash[j]--;
    	        i += 2;
    	    }
    	}
     	
     	return res;
    }
};

// { Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}  // } Driver Code Ends