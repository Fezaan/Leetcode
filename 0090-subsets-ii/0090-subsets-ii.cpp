class Solution {
public:
void sub_set(int idx, vector<int> &ds, vector<int> &arr, vector<vector<int> > &res) {
        res.push_back(ds);
    
        for(int i=idx; i<arr.size(); i++) {
    
            if(i>idx && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            sub_set(i+1, ds, arr, res);
            ds.pop_back();
        }
    
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        sub_set(0,ds,nums,res);
        
        return res;
    }
};
