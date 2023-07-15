class Solution {
public:
    int findCircleNum(vector<vector<int>>& con) {
        int n=con.size();
        vector<int> vis(n,0);
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                while(!q.empty()){
                    int tmp=q.front();
                    q.pop();
                    vis[tmp]=1;
                    for(int j=0;j<n;j++){
                        if(con[tmp][j]==1 && !vis[j])   q.push(j);
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }
};