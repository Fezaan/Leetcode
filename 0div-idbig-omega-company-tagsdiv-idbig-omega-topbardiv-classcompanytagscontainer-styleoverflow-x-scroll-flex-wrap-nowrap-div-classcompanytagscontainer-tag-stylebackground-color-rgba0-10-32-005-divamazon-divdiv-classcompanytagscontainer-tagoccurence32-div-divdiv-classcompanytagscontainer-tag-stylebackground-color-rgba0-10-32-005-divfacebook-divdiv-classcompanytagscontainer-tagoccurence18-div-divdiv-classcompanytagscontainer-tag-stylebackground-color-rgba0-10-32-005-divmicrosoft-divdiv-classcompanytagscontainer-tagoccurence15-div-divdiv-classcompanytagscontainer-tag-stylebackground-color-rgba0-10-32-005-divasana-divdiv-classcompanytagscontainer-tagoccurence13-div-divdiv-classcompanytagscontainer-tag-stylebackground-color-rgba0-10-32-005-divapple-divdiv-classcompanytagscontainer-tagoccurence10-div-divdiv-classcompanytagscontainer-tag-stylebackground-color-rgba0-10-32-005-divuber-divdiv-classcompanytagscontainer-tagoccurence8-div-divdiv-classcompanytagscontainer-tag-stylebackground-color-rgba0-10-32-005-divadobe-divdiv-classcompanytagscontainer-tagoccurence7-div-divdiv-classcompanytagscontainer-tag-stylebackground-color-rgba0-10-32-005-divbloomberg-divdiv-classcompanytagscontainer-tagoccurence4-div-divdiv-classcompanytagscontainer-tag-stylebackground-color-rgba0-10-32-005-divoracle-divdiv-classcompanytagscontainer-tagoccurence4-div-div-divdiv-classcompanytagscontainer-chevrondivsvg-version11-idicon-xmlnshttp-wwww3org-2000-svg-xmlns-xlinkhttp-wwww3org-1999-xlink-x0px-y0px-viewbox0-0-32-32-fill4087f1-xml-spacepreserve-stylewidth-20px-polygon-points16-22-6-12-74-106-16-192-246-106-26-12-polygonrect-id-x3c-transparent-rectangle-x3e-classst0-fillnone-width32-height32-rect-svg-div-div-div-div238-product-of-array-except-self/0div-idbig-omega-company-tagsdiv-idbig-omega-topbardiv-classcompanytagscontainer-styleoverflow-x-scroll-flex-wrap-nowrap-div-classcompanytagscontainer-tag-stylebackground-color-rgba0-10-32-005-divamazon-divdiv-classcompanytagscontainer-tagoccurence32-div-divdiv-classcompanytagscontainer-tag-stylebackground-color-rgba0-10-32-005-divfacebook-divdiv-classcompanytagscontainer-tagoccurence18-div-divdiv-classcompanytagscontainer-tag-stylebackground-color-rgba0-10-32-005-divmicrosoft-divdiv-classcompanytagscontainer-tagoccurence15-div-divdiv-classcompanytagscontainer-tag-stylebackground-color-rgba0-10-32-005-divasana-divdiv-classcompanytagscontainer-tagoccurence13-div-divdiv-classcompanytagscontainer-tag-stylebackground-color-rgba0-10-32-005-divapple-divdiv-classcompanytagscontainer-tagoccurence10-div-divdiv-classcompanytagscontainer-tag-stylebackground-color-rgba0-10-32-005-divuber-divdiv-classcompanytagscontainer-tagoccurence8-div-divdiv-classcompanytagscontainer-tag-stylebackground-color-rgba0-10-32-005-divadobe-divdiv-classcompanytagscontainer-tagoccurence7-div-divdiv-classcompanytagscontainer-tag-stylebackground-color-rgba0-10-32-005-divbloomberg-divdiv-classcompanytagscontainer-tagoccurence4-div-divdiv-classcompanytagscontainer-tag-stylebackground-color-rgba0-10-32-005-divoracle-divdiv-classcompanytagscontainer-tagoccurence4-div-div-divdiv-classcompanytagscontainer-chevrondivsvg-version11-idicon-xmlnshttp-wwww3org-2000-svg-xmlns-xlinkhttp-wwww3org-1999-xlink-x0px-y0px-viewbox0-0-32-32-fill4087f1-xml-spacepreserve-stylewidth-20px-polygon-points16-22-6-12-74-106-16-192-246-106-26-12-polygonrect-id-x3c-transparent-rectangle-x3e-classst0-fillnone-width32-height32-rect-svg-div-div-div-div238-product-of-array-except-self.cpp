class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int prod=1;
        for(int i=0;i<n-1;i++){
            prod*=nums[i];
            res[i+1]=prod;
        }
        for(auto it:res)    cout<<it<<" ";
        prod=1;
        for(int i=n-1;i>0;i--){
            prod*=nums[i];
            res[i-1]*=prod;
        }
        return res;
    }
};