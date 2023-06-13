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
    string preToInfix(string s) {
        // Write your code here
        stack<string> res;
        for(int i=s.length()-1;i>=0;i--){
            if(!isOperator(s[i]))   res.push(string(1,s[i]));
            else{
                char op=s[i];
                string op1=res.top();
                res.pop();
                string op2=res.top();
                res.pop();
                string x='('+op1+op+op2+')';
                res.push(x);
            }
        }
        string ans=res.top();
        res.pop();
        return ans;
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends