class Solution {
    int timer=1;
public:
    void dfs(int node,int parent,vector<int>& vis,vector<int> adj[], vector<int>& t, vector<int>& low,
            vector<vector<int>>& res){
        vis[node]=1;
        t[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent)  continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,t,low,res);
                low[node]=min(low[node],low[it]);
                if(low[it]>t[node]){
                    res.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0),t(n),low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,t,low,bridges);
        return bridges;
    }
};