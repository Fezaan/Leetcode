//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int count(vector<int> & nums, int goal){
        if(goal<0)  return 0;
        int res=0,r=0,l=0,sum=0;
        
        while(r<nums.size()){
            sum+=nums[r];
            
            while(sum>goal) sum-=nums[l++];
            
            res+=(r-l+1);
            r++;
        }
        return res;
    }
  
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        return count(arr,target)-count(arr,target-1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends