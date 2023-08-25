class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prefix(n),suffix(n);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) prefix[i]=i-st.top();
            else    prefix[i]=i+1;
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) suffix[i]=st.top()-i;
            else suffix[i]=n-i;
            st.push(i);
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            int cost= (suffix[i]+prefix[i]-1)*heights[i];
            mx=max(mx,cost);
        }
        return mx;
    }
};