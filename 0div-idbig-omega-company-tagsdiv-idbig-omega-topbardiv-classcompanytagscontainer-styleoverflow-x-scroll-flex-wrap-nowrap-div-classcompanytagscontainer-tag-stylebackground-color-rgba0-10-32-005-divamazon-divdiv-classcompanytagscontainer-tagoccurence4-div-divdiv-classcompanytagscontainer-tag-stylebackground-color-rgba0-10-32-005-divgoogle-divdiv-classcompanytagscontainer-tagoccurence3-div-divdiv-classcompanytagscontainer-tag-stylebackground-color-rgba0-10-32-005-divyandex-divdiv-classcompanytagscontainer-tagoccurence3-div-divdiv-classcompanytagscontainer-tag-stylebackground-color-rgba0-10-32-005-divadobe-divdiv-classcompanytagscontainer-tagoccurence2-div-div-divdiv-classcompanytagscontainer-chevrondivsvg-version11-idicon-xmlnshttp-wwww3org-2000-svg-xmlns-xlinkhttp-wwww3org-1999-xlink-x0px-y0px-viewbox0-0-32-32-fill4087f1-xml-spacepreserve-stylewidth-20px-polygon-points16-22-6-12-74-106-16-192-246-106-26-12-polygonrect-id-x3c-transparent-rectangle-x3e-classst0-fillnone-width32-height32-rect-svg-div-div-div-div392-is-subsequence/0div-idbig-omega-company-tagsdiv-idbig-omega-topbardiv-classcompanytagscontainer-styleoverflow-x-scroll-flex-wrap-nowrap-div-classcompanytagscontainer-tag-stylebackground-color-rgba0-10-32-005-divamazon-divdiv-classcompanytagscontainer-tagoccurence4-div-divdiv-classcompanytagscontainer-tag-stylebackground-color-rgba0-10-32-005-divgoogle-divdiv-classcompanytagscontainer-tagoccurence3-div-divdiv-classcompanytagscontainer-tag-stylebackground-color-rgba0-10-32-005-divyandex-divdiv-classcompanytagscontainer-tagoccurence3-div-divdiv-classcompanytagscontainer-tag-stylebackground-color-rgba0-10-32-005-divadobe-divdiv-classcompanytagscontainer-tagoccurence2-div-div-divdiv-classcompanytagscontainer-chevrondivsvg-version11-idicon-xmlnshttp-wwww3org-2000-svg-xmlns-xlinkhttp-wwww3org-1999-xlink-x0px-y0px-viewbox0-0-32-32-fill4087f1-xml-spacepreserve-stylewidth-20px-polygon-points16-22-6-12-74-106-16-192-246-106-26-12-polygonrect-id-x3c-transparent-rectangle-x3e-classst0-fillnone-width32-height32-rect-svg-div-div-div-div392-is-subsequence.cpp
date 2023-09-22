class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        if(n==0)    return 1;
        int i=0,j=0;
        while(j<m){
            if(s[i]==t[j]){
                i++;
                j++;
                if(i==n)    return 1;
            }
            else    j++;
        }
        return 0;
    }
};