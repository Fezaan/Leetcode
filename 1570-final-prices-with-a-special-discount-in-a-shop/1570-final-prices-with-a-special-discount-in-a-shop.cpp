class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        int n=prices.size();
        for(int i=0;i<n;i++){
                bool f=0;
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    res.push_back(prices[i]-prices[j]);
                    f=1;
                    break;
                }
            }
                if(f==0)    res.push_back(prices[i]);
        }
        return res;
    }
};