class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& x, vector<int>& y) {
        vector<vector<int>> res;
        int n=x.size();
        for(int i=0;i<n;i++){
            if(y[1]<x[i][0]){
                res.push_back(y);
                for(int j=i;j<n;j++) res.push_back(x[j]);
                return res;
            }
            else if(y[0]>x[i][1])   res.push_back(x[i]);
            else{
                y[0]=min(y[0],x[i][0]);
                y[1]=max(y[1],x[i][1]);
            }
        }
        res.push_back(y);
        return res;
    }
};