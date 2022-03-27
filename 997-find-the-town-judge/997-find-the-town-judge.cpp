class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n + 1, 0); // Define an array of length n+1
        
        for(int i = 0; i < trust.size(); i++){ // loop through the 'trust' array
            arr[trust[i][0]]--; // if a given person trust someone then decrement the count of his index
            arr[trust[i][1]]++; // increment the count of the index whom he trusts
            
        }
        // In last, check the 'arr' array that if there is any index having count equals to n-1
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == n - 1) return i; // person doesnt trust anybody but everyone else trust him. Return their index
        }
        return -1;
    }
};