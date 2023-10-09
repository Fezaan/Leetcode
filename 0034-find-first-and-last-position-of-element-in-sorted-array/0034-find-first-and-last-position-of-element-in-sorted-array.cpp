class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)    return {-1,-1};
        int l=0,h=n-1,ind1=-1,ind2=-1;
        if(nums[0]==target) ind1=0;
        else{
            while(l<=h){
                int m=l+(h-l)/2;
                if(nums[m]==target){
                    if(nums[m-1]!=target){
                        ind1=m;
                        break;
                    }
                    else{
                        h=m-1;
                    }
                }
                else if(nums[m]>target) h=m-1;
                else    l=m+1;
            }
        }
        l=0,h=n-1;
        if(nums[n-1]==target)   ind2=n-1;
        else{
            while(l<=h){
                int m=l+(h-l)/2;
                if(nums[m]==target){
                    if(nums[m+1]!=target){
                        ind2=m;
                        break;
                    }
                    else{
                        l=m+1;
                    }
                }
                else if(nums[m]>target) h=m-1;
                else    l=m+1;
            }
        }
        return {ind1,ind2};
    }
};