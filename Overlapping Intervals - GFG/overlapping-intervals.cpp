//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& nami) {
         // Code here
         sort(nami.begin(),nami.end());
         vector<vector<int>> zeus;
         vector<int> Wegg=(nami[0]);
         for(auto it: nami){
             if(it[0]<=Wegg[1]) Wegg[1]=max(Wegg[1],it[1]);
             else{
                 zeus.push_back(Wegg);
                 Wegg=it;
             }
         }
         zeus.push_back(Wegg);
         return zeus;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends