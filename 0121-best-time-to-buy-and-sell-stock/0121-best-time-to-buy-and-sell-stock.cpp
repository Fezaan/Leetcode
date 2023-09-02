class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx=0,l=0,r=0;
        while(r<n){
            if(prices[r]>prices[l])
                mx=max(mx,prices[r]-prices[l]);
            else l=r;
            r++;
        }
        return mx;
    }
};