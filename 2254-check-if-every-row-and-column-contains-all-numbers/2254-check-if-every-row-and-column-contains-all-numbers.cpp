class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            for(int j=0;j<n;j++){
                vis[matrix[i][j]-1]=1;
            }
            for(auto it: vis)   if(it==0)   return 0;
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            for(int j=0;j<n;j++){
                vis[matrix[j][i]-1]=1;
            }
            for(auto it: vis)   if(it==0)   return 0;
        }

        return 1;
    }
};