class Solution {
public:
    int histo(vector<int>& heights){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')   heights[j]++;
                else heights[j]=0;
            }
            int area=histo(heights);
            mx=max(area,mx);
        }
        return mx;
    }
};