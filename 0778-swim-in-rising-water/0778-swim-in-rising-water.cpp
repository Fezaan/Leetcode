class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            if(r==n-1 && c==n-1)    return d;
            
            for(int i=0;i<4;i++){
                int row=r+delRow[i],col=c+delCol[i];
                if(row<n && col<n && row>=0 && col>=0 && vis[row][col]!=1){
                    vis[row][col]=1;
                    pq.push({max(d,grid[row][col]),{row,col}});
                }
            }
            
        }
        return -1;
    }
};
