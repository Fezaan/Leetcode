class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        // vector<vector<int>> dp(n+1, vector<int> (2,0));
        vector<int> next(2,0), curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j)   curr[j]=max(next[0]-prices[i], next[1]);
                else    curr[j]=max(next[1]+prices[i]-fee, next[0]);
            }
            next=curr;
        }

        return next[1];
    }
};