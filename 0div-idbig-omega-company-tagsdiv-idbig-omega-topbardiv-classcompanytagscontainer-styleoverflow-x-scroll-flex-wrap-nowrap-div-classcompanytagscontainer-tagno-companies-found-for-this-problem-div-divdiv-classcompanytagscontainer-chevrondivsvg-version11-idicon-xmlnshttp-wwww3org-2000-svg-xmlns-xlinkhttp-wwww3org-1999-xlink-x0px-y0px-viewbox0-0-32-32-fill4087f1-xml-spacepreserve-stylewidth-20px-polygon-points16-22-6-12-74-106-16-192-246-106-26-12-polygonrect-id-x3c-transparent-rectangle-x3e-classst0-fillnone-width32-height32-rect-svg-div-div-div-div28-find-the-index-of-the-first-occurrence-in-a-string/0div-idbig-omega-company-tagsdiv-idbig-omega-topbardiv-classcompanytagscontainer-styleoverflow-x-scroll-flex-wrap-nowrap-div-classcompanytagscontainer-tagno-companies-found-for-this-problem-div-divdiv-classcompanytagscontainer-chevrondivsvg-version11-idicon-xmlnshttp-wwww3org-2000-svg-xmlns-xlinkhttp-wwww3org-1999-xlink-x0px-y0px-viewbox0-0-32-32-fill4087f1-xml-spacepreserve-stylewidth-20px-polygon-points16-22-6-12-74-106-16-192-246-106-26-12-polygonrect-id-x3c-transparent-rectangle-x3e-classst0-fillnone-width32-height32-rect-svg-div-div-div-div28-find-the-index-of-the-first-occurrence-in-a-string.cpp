class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();
        int i=0,j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                j++;
            }
            else{
                i-=j;
                j=0;
            }
            if(j==m)    return i-j+1;
            i++;
        }
        return -1;
    }
};
