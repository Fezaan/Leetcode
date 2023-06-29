//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        vector<int> mp(26,0);
        int maxFreq=0,count=0;
        
        for(auto it: tasks){
            mp[it-'A']++;
            if(mp[it-'A']>maxFreq)  maxFreq=mp[it-'A'];
        }
        
        for(int i=0;i<26;i++){
            if(mp[i]==maxFreq)  count++;
        }
        int time=(maxFreq-1)*(k+1)+count;
        return max(time,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends