//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& words) {
        // Code here
        queue<pair<string, int>> q;
        unordered_set<string> s(words.begin(),words.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        
        while(!q.empty()){
            string data=q.front().first;
            int len=q.front().second;
            q.pop();
            if(data==endWord)   return len;
            for(int i=0;i<data.size();i++){
                char ch=data[i];
                for(char j='a';j<='z';j++){
                    data[i]=j;
                    if(s.find(data)!=s.end()){
                        s.erase(data);
                        q.push({data,len+1});
                    }
                }
                data[i]=ch;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends