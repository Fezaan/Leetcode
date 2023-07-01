//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<int> res;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++)    pq.push({a[i]+b[n-1],{i,n-1}});
        while(!pq.empty() && k--){
            pair<int,pair<int,int>> p=pq.top();
            int val=p.first;
            int x=p.second.first, y=p.second.second;
            pq.pop();
            if(y!=0)    pq.push({a[x]+b[y-1],{x,y-1}});
            res.push_back(val);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends