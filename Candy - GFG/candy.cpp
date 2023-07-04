//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &arr) {
        // code here
        vector<int> res(N,1);
        for(int i=1;i<N;i++){
            if(arr[i]>arr[i-1]) res[i]=res[i-1]+1;
        }
        for(int i=N-2;i>=0;i--){
            if(arr[i]>arr[i+1] && res[i]<=res[i+1]) res[i]=res[i+1]+1;
        }
        int sum=0;
        return accumulate(res.begin(),res.end(),sum);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends