class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][i]==0 || arr[i][n-1-i]==0)    return 0;
                if(j!=i && j!=n-1-i && arr[i][j]!=0)    return 0;
            }
        }
        return 1;
    }
};