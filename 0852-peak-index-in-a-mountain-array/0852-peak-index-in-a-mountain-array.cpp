class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int x=0;
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]> arr[mid-1] && arr[mid]>arr[mid+1]){
                x=mid;
                break;
            }
            else if(arr[mid]<arr[mid+1])    l=mid;
            else    r=mid;
        }
        return x;
    }
};