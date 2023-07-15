class Solution {
public:
    void dfs(int node,vector<vector<int>>& con, vector<int>& vis){
        vis[node]=1;
        for(int i=0;i<con.size();i++){
            if(con[node][i]==1 && !vis[i]){
                dfs(i,con,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& con) {
        int n=con.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,con,vis);
                cnt++;
            }
        }
        return cnt;
    }
};