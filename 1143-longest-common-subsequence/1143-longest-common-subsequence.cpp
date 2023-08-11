class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(), m=t2.size();
        // vector<vector<long>> dp(n+1,vector<long> (m+1,-1));
        vector<long> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++)    prev[j]=0;
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
};