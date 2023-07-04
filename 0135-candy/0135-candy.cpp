class Solution {
public:
    int candy(vector<int>& arr) {
        vector<int> res(arr.size(),1);
        int sum=0;
        for(int i=1;i<arr.size();i++)   if(arr[i]>arr[i-1]) res[i]=res[i-1]+1;
        for(int i=arr.size()-2;i>=0;i--) if(arr[i]>arr[i+1] && res[i]<=res[i+1]) res[i]=res[i+1]+1;
        return accumulate(res.begin(),res.end(),sum);
    }
};