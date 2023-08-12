class Solution {
public:
    string lcs(string t1, string t2)
    {
        //Write your code here
        int n=t1.size(), m=t2.size();
        vector<vector<long>> dp(n+1, vector<long> (m+1,0));
        for(int i=0;i<=n;i++)   dp[i][0]=0;
        for(int j=0;j<=m;j++)   dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])    dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string x="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(t1[i-1]==t2[j-1]){
                x+=t1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]> dp[i][j-1]){
                x+=t1[i-1];
                i--;
            }
            else{
                x+=t2[j-1];
                j--;
            }
        }
        while(i>0){
            x+=t1[i-1];
            i--;
        }
        while(j>0){
            x+=t2[j-1];
            j--;
        }
        reverse(x.begin(),x.end());
        return x;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs(str1,str2);
    }
};