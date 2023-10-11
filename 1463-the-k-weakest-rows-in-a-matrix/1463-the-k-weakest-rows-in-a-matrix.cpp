class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)    cnt++;
                else{
                    break;
                }
            }
            pq.push({cnt,i});
            while(pq.size()>k)  pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};