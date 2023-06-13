class Solution {
public:
    string mapping(vector<int> row){
        string res="";
        for(auto it: row){
            res+=to_string(it)+"#";
        }
        return res;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        map<string,int> mp;
        for(int i=0;i<grid.size();i++){
            mp[mapping(grid[i])]++;
        }
        for(int i=0;i<grid.size();i++){
            string res="";
            for(int j=0;j<grid.size();j++){
                res+=to_string(grid[j][i])+"#";
            }
            count+=mp[res];
        }
        return count;
    }
};