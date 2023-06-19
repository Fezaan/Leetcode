class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }
        if(st.empty()){
            st.push({ind,price});
            return ind+1;
        }
        int result=st.top().first;
        st.push({ind,price});
        return ind-result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */