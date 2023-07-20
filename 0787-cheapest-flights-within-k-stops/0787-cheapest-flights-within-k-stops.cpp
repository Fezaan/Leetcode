class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<vector<int>> q;
        q.push({0,src,0});
        while(!q.empty()){
            int stop=q.front()[0];
            int node=q.front()[1];
            int d=q.front()[2];
            q.pop();
            if(stop>k)  continue;
            for(auto it: adj[node]){
                int newNode=it.first;
                int wt=it.second;

                if(d+wt<dist[newNode] && stop<=k){
                    dist[newNode]=d+wt;
                    q.push({stop+1,newNode,d+wt});
                }
            }
        }
        if(dist[dst]==1e9)  return -1;
        return dist[dst];
    }
};