class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
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