class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)    cost[i][i]=0;
        for(auto it: edges){
            int u=it[0],v=it[1],wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(cost[j][i]==1e9 || cost[i][k]==1e9)  continue;
                    cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
                }
            }
        }
        int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (cost[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};