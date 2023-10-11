class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int> start,end;
        for(auto it: flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> res;
        for(auto it: people){
            int ub=upper_bound(start.begin(),start.end(),it)-start.begin();
            int lb=lower_bound(end.begin(),end.end(),it)-end.begin();
            res.push_back(ub-lb);
        }
        return res;
    }
};