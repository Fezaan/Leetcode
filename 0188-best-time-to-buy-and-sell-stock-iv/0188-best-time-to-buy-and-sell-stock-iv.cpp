class Solution {
public:
    int maxProfit(int limit, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2, vector<int>(limit+1,0)), curr(2, vector<int>(limit+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=limit;k++){
                    if(j){
                        curr[j][k]=max(prev[0][k]-prices[i], prev[1][k]);
                    }else{
                        curr[j][k]=max(prev[1][k-1]+prices[i], prev[0][k]);
                    }
                }
                prev=curr;
            }
        }
        return prev[1][limit];
    }
};