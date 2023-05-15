//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void find(int index,int sum , int n, int k, vector<int> &nums, vector<vector<int>> &ans,vector<int> &ds){
        if(index==nums.size()){
            if(sum==n && ds.size()==k){
                ans.emplace_back(ds);
            }
            return;
        }
        ds.emplace_back(nums[index]);
        find(index+1,sum+nums[index],n,k,nums,ans,ds);
        ds.pop_back();
        find(index+1,sum,n,k,nums,ans,ds);
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int> vect{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,0,N,K,vect,ans,ds);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends