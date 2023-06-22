//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n=s.length();
        int l,r,c;
        l=r=c=0;
        unordered_map<char,int> mp;
        
        while(r<n){
            mp[s[r]]++;
            
            while(mp['a'] && mp['b'] && mp['c']){
                c+=n-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends