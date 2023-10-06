class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> adj[v];
        for(auto it: arr){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i])    indegree[it]++;
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<v;i++)    if(indegree[i]==0)  q.push(i);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it: adj[x]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return cnt==v;
        
    }
};
