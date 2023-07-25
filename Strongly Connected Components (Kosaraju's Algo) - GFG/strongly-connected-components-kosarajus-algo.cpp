//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<int>& vis, stack<int>& st, vector<vector<int>>& adj){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it])
	            dfs(it,vis,st,adj);
	    }
	    st.push(node);
	}
	void dfs3(int node,vector<int>& vis, vector<int> adj[]){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it])
	            dfs3(it,vis,adj);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,vis,st,adj);
        }
        vector<int> adjT[n];
        
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs3(node,vis,adjT);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends