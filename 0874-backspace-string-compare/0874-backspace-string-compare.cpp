class Solution {
public:
    void f(string & a, string s){
        for(auto it: s){
            if(isalpha(it)) a.push_back(it);
            else{
                if(a.empty())   continue;
                a.pop_back();
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        string a,b;
        f(a,s);
        f(b,t);
        return a==b;
    }
};