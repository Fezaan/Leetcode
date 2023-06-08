//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int check(int a){
        int b=a%4;
        if(b==0)    return a;
        else if(b==1)   return 1;
        else if(b==2)   return a+1;
        else    return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return (check(l-1)^check(r));
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends