class Solution {
public:
    bool find(int i, int j, int n, int m, vector<vector<char>> &board,string word, int ind){
        if(ind==word.length())  return true;
        if(i<0||j<0||i==n||j==m||board[i][j]!=word[ind]) return false;
        char ch = board[i][j];
        board[i][j]='#';
        bool opt1= find(i+1,j,n,m,board,word,ind+1);
        bool opt2= find(i,j+1,n,m,board,word,ind+1);
        bool opt3= find(i-1,j,n,m,board,word,ind+1);
        bool opt4= find(i,j-1,n,m,board,word,ind+1);
        board[i][j]=ch;
        return opt1||opt2||opt3||opt4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(find(i,j,n,m,board,word,0))  return true;
            }
        }
        return false;
    }
};