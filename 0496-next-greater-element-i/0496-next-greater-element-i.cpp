class Solution {
public:
    int greater(int target, vector<int> &nums){
        int count=0;
        auto itr= find(nums.begin(),nums.end(),target);
        for(int i=itr-nums.begin();i<nums.size();i++){
            if(nums[i]>target){  
                count=nums[i];
                break;
            }
        }
        return count==0? -1:count;
        
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(greater(nums1[i],nums2));
        }
        return res;
    }
};