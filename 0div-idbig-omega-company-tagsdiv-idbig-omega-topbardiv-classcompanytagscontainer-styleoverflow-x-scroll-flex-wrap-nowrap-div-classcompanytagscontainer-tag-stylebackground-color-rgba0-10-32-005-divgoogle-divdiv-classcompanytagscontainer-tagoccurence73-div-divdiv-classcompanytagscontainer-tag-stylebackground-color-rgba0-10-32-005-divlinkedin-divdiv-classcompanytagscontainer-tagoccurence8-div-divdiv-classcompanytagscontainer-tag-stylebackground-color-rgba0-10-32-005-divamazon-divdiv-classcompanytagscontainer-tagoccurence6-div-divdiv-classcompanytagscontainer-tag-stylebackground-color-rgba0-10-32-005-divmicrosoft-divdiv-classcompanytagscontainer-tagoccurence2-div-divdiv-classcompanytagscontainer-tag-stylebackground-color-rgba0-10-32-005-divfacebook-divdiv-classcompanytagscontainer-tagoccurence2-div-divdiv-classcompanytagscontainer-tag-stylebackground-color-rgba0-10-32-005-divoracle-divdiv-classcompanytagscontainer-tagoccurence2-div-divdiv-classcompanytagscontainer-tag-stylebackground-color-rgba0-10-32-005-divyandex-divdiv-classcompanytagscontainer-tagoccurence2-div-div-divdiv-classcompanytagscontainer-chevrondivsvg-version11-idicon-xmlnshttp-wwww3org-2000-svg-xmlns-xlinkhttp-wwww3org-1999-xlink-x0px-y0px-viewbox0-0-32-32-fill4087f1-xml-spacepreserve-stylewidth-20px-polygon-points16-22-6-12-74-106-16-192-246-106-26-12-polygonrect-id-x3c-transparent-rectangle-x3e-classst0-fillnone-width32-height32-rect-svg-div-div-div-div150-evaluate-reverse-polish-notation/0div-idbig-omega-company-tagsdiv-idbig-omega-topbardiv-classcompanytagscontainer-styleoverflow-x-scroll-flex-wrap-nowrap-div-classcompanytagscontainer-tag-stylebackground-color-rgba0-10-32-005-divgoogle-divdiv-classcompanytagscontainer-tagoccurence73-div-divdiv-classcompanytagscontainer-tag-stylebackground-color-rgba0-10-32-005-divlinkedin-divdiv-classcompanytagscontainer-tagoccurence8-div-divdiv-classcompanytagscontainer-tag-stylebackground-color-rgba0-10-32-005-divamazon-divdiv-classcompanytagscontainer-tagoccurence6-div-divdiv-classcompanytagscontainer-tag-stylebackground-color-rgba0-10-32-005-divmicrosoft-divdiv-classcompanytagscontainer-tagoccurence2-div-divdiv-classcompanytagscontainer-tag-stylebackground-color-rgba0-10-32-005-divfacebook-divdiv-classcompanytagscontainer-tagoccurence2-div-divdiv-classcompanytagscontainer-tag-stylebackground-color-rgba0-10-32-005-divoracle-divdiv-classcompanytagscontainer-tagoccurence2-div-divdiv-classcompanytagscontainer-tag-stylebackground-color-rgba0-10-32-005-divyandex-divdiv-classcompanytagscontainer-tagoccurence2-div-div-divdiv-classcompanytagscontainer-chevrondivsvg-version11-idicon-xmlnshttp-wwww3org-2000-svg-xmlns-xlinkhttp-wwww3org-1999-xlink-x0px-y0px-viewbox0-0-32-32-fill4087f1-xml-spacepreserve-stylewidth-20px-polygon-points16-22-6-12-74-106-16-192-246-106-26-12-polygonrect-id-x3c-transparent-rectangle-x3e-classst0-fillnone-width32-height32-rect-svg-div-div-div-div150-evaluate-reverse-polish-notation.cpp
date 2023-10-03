class Solution {
public:
    int f(int a, int b, string x){
        if(x=="+")  return a+b;
        else if(x=="-") return a-b;
        else if(x=="/") return a/b;
        else    return a*b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it=="+" || it=="-" || it=="/" || it=="*"){
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(f(op2,op1,it));
            }
            else    st.push(stoi(it));
        }
        int x=st.top();
        return x;
    }
};