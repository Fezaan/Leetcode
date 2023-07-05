//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        int cnt=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int goal=intervals[0][1];
        for(int i=1;i<n;i++){
            if(goal>intervals[i][0])    cnt++;
            else    goal=intervals[i][1];
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends