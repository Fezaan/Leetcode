class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        vector<int> res;
        res.push_back(arr[0]);
        int n=arr.size();
        for(int i=1; i<n; i++){
            res.push_back(arr[i-1]^arr[i]);
        }
        return res;
    }
};