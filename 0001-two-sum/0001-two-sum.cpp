class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> arr(nums);
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        int a,b;
        vector<int> res;
        while(l<=r){
            int sum=nums[l]+nums[r];
            if(sum==target){
                a=nums[l];
                b=nums[r];
                break;
            }
            else if(sum>target) r--;
            else    l++;
        }
        for(int i=0;i<n;i++){
            if(a==arr[i] || b==arr[i])   res.push_back(i);
        }
        return res;
    }
};
