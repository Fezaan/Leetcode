//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int pre(char ch){
      switch (ch){
          case '^': return 3;
          case '*':
          case '/':
            return 2;
          case '+':
          case '-':
            return 1;
          default:  return -1;
      }
  }
  bool isOperator(char ch){
      if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-')   return 1;
      return 0;
  }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string output="";
        stack<char> st;
        for(auto ch: s){
            if(isOperator(ch)){
                while(!st.empty() && pre(st.top())>=pre(ch)){
                    output+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(st.top()!='('){
                    output+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else    output+=ch;
        }
        while(!st.empty()){
            output+=st.top();
            st.pop();
        }
        return output;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends