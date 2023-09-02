class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> res; 
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                int sum=arr[i]+arr[l]+arr[r];
                vector<int> tmp;
                if(sum==0){
                    tmp.insert(tmp.end(), {arr[i],arr[l],arr[r]});
                    res.push_back(tmp);;
                    l++;
                    while(arr[l]==arr[l-1] && l<r)    l++;
                }
                else if(sum<0)   l++;
                else    r--;
            }
        }
        return res;
    }
};