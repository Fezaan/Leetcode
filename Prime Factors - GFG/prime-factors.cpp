//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    vector<int> AllPrimeFactors(int N) {
        if (N == 2)
            return {2};

        vector<int> factors;
        int sqrtN = sqrt(N);
        vector<bool> isPrime(sqrtN + 1, true);

        for (int i = 2; i <= sqrtN; i++) {
            if (isPrime[i]) {
                if (N % i == 0) {
                    factors.push_back(i);
                    while (N % i == 0) {
                        N /= i;
                    }
                }
                for (int j = i * i; j <= sqrtN; j += i)
                    isPrime[j] = false;
            }
        }

        if (N > 1)
            factors.push_back(N);

        return factors;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends