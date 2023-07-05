//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &zoro, vector<int> &enma) {
        // code here
        vector<vector<int>> OnePiece;
        for(int i=0;i<N;i++){
            if(enma[1]<zoro[i][0]){
                OnePiece.push_back(enma);
                for(int j=i;j<N;j++)    OnePiece.push_back(zoro[j]);
                return OnePiece;
            }
            else if(enma[0]>zoro[i][1]) OnePiece.push_back(zoro[i]);
            else{
                enma[0]=min(enma[0],zoro[i][0]);
                enma[1]=max(enma[1],zoro[i][1]);
            }
            
        }
        OnePiece.push_back(enma);
        return OnePiece;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends