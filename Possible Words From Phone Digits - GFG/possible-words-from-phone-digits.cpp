//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void find(int index, string arr[],string digits, vector<string>& res, string ds){
        if(index>=digits.length()){
            res.emplace_back(ds);
            return;
        }
        int num=digits[index]-'0';
        string val=arr[num];
        
        for(int i=0;i<val.length();i++){
            ds.push_back(val[i]);
            find(index+1,arr,digits,res,ds);
            ds.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string s="";
        for(int i=0;i<N;i++)    s+=to_string(a[i]);
        vector<string> res;
        if(s.length()==0)  return res;
        string arr[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ds="";
        find(0, arr,s,res,ds);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends