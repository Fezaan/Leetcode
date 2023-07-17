class Solution {
    bool dfs(int node, int color, vector<int>& vis, vector<vector<int>> &graph){
        vis[node]=color;
        for(auto it: graph[node]){
            if(vis[it]==-1){
                if(!dfs(it,!color,vis,graph))   return false;
            }
            else if(vis[it]==color) return false;
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph))   return 0;
            }
        }
        return 1;
    }
};