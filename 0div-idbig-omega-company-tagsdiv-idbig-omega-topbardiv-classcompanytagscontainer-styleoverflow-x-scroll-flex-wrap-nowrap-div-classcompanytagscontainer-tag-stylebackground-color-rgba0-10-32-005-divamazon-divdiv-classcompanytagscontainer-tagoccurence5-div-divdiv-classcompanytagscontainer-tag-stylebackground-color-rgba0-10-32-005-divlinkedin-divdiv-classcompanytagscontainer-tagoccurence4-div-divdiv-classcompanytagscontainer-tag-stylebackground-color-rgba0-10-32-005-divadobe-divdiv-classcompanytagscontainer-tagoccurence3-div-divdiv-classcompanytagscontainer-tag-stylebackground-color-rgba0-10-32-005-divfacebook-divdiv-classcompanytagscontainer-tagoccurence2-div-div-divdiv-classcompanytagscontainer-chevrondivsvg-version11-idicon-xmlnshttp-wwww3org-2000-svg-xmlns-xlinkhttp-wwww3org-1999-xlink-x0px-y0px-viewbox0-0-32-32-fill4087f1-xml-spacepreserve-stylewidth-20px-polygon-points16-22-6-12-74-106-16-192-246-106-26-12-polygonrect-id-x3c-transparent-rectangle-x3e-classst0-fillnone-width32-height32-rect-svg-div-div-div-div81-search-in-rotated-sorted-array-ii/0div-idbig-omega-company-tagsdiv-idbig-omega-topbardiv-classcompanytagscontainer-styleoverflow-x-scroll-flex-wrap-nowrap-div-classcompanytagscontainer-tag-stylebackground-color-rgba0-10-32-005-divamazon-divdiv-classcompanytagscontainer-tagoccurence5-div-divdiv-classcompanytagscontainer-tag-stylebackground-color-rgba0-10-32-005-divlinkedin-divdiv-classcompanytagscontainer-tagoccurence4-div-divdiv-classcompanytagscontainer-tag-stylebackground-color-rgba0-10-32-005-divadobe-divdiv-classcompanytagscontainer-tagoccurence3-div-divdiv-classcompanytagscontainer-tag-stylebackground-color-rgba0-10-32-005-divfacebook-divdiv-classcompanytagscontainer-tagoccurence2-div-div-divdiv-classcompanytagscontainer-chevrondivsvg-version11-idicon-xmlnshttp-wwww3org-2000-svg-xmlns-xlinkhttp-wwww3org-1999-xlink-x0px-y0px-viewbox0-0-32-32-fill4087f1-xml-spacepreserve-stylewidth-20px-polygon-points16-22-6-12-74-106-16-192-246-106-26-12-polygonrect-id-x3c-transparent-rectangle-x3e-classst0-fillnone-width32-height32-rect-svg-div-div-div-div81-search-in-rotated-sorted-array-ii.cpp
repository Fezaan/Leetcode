class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
        int rot=0;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                rot=i;
                break;
            }
        }
        int l=rot,h=rot+n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int tmp=m%n;
            if(arr[tmp]==k) return 1;
            else if(arr[tmp]>k) h=m-1;
            else    l=m+1;
        }
        return 0;
    }
};