//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int n, int k) {
        // code here
        long long sum=0;
        
        for(int i=0;i<k;i++)    sum+=arr[i];
        long long curr=sum;
        
        for(int i=k-1;i>=0;i--){
            curr-=arr[i];
            curr+=arr[n-k+i];
            sum=max(curr,sum);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends