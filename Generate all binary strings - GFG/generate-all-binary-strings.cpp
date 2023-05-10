//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void gen(int num, string s , int index){
        if(index == num){
            cout<<s<<" ";
            return;
        }
        if(index!=0 && s[index-1]=='1'){
            gen(num, s+'0',index+1);
        }
        else{
            gen(num, s+'0',index+1);
            gen(num, s+'1', index+1);
        }
    }

    void generateBinaryStrings(int num){
        //Write your code
        gen(num,"",0);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends