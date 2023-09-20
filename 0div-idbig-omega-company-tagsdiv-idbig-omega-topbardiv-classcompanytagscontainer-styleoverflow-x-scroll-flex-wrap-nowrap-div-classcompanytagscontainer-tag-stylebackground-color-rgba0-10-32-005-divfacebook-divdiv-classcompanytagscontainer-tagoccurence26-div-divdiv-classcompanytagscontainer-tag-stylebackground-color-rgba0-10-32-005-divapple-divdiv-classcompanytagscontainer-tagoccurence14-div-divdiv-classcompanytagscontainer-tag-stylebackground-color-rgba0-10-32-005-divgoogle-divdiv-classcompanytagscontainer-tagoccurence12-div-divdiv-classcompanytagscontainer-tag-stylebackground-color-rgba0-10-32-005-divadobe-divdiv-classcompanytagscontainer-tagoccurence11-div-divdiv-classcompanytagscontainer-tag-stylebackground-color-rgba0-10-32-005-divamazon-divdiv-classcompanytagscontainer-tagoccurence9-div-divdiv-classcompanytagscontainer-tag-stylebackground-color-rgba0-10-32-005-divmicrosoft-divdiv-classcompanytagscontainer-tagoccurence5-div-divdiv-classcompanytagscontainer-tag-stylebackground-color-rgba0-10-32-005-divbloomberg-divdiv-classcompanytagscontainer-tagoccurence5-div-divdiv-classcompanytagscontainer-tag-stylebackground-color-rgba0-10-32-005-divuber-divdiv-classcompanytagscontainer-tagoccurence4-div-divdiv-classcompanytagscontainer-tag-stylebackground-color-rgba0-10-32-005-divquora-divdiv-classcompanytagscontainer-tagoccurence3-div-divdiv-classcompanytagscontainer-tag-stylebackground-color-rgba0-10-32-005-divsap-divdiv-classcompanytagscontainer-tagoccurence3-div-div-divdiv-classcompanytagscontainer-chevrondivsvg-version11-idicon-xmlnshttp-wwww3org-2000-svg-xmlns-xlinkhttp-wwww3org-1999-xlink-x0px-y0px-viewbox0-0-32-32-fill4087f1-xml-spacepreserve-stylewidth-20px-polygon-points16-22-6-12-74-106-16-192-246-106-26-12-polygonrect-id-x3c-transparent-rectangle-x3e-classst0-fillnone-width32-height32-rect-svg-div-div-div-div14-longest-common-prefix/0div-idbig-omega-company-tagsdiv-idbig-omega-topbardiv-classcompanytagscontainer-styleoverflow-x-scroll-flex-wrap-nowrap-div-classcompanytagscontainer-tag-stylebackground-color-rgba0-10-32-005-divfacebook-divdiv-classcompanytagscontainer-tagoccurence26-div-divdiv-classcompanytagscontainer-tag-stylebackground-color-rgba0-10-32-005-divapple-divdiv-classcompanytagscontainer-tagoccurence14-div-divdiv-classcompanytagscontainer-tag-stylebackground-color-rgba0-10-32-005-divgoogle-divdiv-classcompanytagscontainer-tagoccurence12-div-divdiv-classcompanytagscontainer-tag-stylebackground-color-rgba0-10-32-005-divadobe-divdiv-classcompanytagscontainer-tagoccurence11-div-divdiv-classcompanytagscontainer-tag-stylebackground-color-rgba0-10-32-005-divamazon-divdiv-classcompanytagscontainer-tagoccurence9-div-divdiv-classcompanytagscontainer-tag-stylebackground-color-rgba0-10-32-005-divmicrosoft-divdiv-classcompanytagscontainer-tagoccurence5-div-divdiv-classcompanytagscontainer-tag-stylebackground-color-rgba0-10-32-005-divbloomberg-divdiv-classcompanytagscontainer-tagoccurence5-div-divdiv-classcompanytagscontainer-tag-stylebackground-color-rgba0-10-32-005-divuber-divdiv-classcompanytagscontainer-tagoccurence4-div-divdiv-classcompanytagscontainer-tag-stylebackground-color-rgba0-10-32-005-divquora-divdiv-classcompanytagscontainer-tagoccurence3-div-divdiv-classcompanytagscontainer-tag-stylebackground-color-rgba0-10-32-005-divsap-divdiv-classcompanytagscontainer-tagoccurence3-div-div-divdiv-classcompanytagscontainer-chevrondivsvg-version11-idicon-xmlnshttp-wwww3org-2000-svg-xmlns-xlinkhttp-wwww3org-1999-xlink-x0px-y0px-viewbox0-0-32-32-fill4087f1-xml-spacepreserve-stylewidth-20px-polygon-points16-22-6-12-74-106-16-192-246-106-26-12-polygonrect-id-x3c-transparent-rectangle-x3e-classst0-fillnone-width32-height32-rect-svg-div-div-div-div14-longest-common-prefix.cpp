class Solution {
public:
    string common(string a, string b){
        int n=a.size(),m=b.size();
        int i=0;
        string x="";
        while(i<min(n,m)){
            if(a[i]==b[i])  x+=a[i];
            else    break;
            i++;
        }
        return x;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        sort(strs.begin(),strs.end());
        res=common(strs[0],strs[strs.size()-1]);
        return res;
    }
};