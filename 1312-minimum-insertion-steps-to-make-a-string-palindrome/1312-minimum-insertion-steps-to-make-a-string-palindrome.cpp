class Solution {
public:
    int lcs(string t1, string t2)
    {
        //Write your code here
        int n=t1.size(), m=t2.size();
        vector<long> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++)   prev[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])    curr[j]=1+prev[j-1];
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    int minInsertions(string s) {
        int n=s.size();
        string rev=s;
        reverse(s.begin(),s.end());
        return n-lcs(rev,s);
    }
};