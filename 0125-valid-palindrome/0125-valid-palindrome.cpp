class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string x="";
        for(auto it: s){
            if(isalpha(it)) x+=tolower(it);
            if(isdigit(it)) x+=to_string(it-'0');
        }
        cout<<x;
        int m=x.size();
        int l=0,r=m-1;
        while(l<=r){
            if(x[l++]!=x[r--])  return 0;
        }
        return 1;
    }
};