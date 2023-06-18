class Solution {
public:
vector<int> nextsmaller(vector<int> &v){
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        int curr=v[i];
        while(st.top()!=-1&&v[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    }
    vector<int> prevsmaller(vector<int> &v){
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size());
        for(int i=0;i<v.size();i++){
            int curr=v[i];
            while(st.top()!=-1&&v[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int maxHisto(vector<int>& heights) {
        vector<int> prev=prevsmaller(heights);
        vector<int> next=nextsmaller(heights);
        int size=heights.size();
        int maxlen=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int len=heights[i];
            if(next[i]==-1)
                next[i]=size;
            int width=next[i]-prev[i]-1;
            int area=len*width;
            maxlen=max(maxlen,area);
        }
        return maxlen;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v(matrix.size());
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j]=='0')
  v[i].push_back(0);
  else v[i].push_back(1);
           }
       } 
       int first= maxHisto(v[0]);
     for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]!=0){
                v[i][j]=v[i-1][j]+v[i][j];
            }
            else v[i][j]=0;
        }
        int a=  maxHisto(v[i]);
        first= max(first,a);
     }
    return first;
    }   
};