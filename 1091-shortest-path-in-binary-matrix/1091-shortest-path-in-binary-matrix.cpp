class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)   return -1;
        
        int n=grid.size();
        if(n==1 && grid[0][0]==0)   return 1;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[0][0]=1;
        int delRow[]={-1,-1,0,1,1,1,0,-1};
        int delCol[]={0,1,1,1,0,-1,-1,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<8;i++){
                int r=row+delRow[i];
                int c=delCol[i]+col;
                
                if(r<n && c<n && r>=0 && c>=0 && grid[r][c]==0 && dist[r][c]>d+1){
                    dist[r][c]=d+1;
                    if(r==n-1 && c==n-1)    return d+1;
                    q.push({d+1,{r,c}});
                }
            }
        }
        return -1;
    }
};