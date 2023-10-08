class Solution {
public:
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> vis;
    int findbob(int bob, vector<int>& val, int ind=0, int count=1){
        if(ind==bob) {
            if(count==1) val[ind]/=2;
            else val[ind]=0;
            return count;
        }
        vis[ind]=1;
        for(auto &it: map[ind]){
            if(!vis.count(it)){
                int temp=findbob(bob, val, it, count+1);
                if(temp!=-1){
                    if(temp%2){
                        if(count>(temp+1)/2) val[ind]=0;
                        if(count==(temp+1)/2) val[ind]/=2;
                    }
                    else{
                        if(count>temp/2) val[ind]=0;
                    }
                    return temp;
                }
            }
        }
        return -1;
    }
    int bestpath(vector<int>& val, int ind=0){
        int ans=-1e9;
        vis[ind]++;
        for(auto &it:map[ind]){
            if(!vis.count(it)){
                ans=max(ans, bestpath(val, it));
            }
        }
        if(ans==-1e9) ans=0;
        return ans+val[ind];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(int i=0;i<edges.size();i++){
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
        findbob(bob, amount);
        vis.clear();
        int ans=bestpath(amount);
        return ans;
    }
};