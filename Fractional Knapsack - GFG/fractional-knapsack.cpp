//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(Item a, Item b){
    double x=(double)a.value/ (double)a.weight;
    double y=(double)b.value/ (double)b.weight;
    return x>y;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        int wait=0;
        double val=0;
        for(int i=0;i<n;i++){
            if(wait+arr[i].weight <= W){
                wait+=arr[i].weight;
                val+=arr[i].value;
            }
            else{
                int remain=(W-wait);
                val+=((double)arr[i].value/(double)arr[i].weight)*remain;
                break;
            }
        }
        return val;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends