class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times) adj[it[0]].push_back({it[1],it[2]});
        vector<int> dist(n+1,1e9);
        queue<pair<int,int>> q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            int node=q.front().second;
            int d=q.front().first;
            q.pop();

            for(auto it: adj[node]){
                int newNode=it.first;
                int wt=it.second;

                if(wt+d < dist[newNode]){
                    dist[newNode]=d+wt;
                    q.push({d+wt,newNode});
                }
            }
        }
        for(int i=1;i<=n;i++)   if(dist[i]==1e9)    return -1;
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)  mx=max(mx,dist[i]);
        return mx;
    }
};