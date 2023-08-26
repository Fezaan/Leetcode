class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int mx=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()])){
                int h=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())  width=i;
                else width=i-st.top()-1;
                int area=width*h;
                mx=max(mx,area);
            }
            st.push(i);
        }
        return mx;
    }
};