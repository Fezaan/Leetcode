//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int res=0,maxf=0;
        int r=0;
        unordered_map<char,int> mp;
        
        while(r<S.length()){
            mp[S[r]]++;
            maxf=max(maxf,mp[S[r]]);
            
            if(res-maxf<K) res++;
            else    mp[S[r-res]]--;
            
            r++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends