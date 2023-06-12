class Solution {
public:
    bool isValid(string x) {
        stack<char> st;
        for(auto ch: x){
            if(ch=='{' ||ch =='[' ||ch=='(' ||st.empty())   st.push(ch);
            else if((ch==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))    st.pop();
            else    return 0;
        }
        return st.empty();
    }
};