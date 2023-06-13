//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      bool isOperator(char ch){
          if(ch=='/' || ch=='^' || ch=='*' || ch=='+' || ch=='-')   return 1;
          return 0;
      }
    string preToPost(string s) {
        stack<string> st;
        for(int i=s.length()-1;i>=0;i--){
            if(!isOperator(s[i]))   st.push(string(1,s[i]));
            else{
                string op1=st.top();  st.pop();
                string op2=st.top();  st.pop();
                string x=op1+op2+s[i];
                st.push(x);
            }
        }
        return st.top();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends