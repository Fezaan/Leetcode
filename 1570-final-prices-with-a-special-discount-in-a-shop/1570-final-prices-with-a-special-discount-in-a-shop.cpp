class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices);
        stack<int> st;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(st.empty() || prices[st.top()]<prices[i]) st.push(i);
            else{
                while(!st.empty() && prices[st.top()]>=prices[i]){
                    res[st.top()]-=prices[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};