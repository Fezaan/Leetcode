//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int count(vector<int> & nums, int k){
        if(k<0) return 0;
        int res=0,r=0,l=0,tot=0;
        
        while(r<nums.size()){
            if(nums[r]%2)   tot++;
            while(tot>k){
                if(nums[l]%2)   tot--;
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return count(nums,k)-count(nums,k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends