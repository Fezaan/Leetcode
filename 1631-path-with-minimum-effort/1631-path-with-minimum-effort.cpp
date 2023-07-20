class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)    return d;
            for(int i=0;i<4;i++){
                int r=row+delRow[i];
                int c=col+delCol[i];
                if(r>=0 && r<n && c<m && c>=0){
                    int newEffort= max(abs(heights[r][c]-heights[row][col]), d);
                    if(newEffort<dist[r][c]){
                        dist[r][c]=newEffort;
                        pq.push({newEffort,{r,c}});
                    }
                }
            }
        }
         return -1;   
    }
};