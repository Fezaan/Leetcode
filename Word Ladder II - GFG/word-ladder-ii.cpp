//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> res;
        vector<string> tmp;
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        tmp.push_back(beginWord);
        int lvl=0;
        
        while(!q.empty()){
            vector<string> words=q.front();
            q.pop();
            
            if(words.size()>lvl){
                lvl++;
                for(auto it: tmp){
                    s.erase(it);
                }
            }
            string word=words.back();
            
            if(word==endWord){
                if(res.size()==0)   res.push_back(words);
                else if(res[0].size()==words.size())    res.push_back(words);
            }
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(int j='a';j<='z';j++){
                    word[i]=j;
                    if(s.count(word)>0){
                        words.push_back(word);
                        q.push(words);
                        tmp.push_back(word);
                        words.pop_back();
                    }
                }
                word[i]=org;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends