//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asd) {
        // code here
        vector<int> res;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                if((st.top()<0&&asd[i]<0) || (st.top()>0&&asd[i]>0) || ((st.top()<0&&asd[i]>0))){
                    st.push(asd[i]);
                }else{
                    if(abs(st.top())>abs(asd[i]));
                    else if(abs(st.top())==abs(asd[i])) st.pop();
                    else{
                        st.pop();
                        i--;
                    }
                }
            }else{
                st.push(asd[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends