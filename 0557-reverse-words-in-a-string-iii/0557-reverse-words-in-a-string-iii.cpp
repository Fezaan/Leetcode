class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.size(),i=0;
        string x="";
        while(i<n){
            if(s[i]==' '){
                reverse(x.begin(),x.end());
                res+=(x);
                res+=s[i];
                x="";
            }
            else{
                x+=s[i];
            }
            i++;
        }
        reverse(x.begin(),x.end());
        res+=x;
        return res;
    }
};