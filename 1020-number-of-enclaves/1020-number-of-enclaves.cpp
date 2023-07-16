class Solution {
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& board){
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int r=i+delRow[k];
            int c=j+delCol[k];
            if(r<n && r>=0 && c<m && c>=0 && !vis[r][c] && board[r][c]==1){
                dfs(r,c,vis,board);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]==1 && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,board);
            }
            if(board[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,vis,board);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]==1)    cnt++;
            }
        }
        return cnt;
    }
};