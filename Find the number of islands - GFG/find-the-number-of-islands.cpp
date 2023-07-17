//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,-1,0,1,1,1,0,-1};
        int delCol[]={0,1,1,1,0,-1,-1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int r=row+delRow[i];
                int c=col+delCol[i];
                
                if(r>=0 && r<n && c<m && c>=0 && !vis[r][c] && grid[r][c]=='1'){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends