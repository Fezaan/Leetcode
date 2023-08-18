class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long l=0,r=0,sum=0,mx=0;
        while(r<n){
            sum+=arr[r];
            while(arr[r]*(r-l+1)>sum+k){
                sum-=arr[l];
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};