class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>>& board,string word,int idx){
        int n=board.size();
        int m=board[0].size();
         if(idx==word.size()) return true;
        if(row<0 || col<0 || row>=n || col>=m || board[row][col]=='#') return false;
        if(board[row][col]!=word[idx]) return false;
        char temp=board[row][col];
        board[row][col]='#';
        bool right=dfs(row,col+1,board,word,idx+1);
        bool left=dfs(row,col-1,board,word,idx+1);
        bool down=dfs(row+1,col,board,word,idx+1);
        bool up=dfs(row-1,col,board,word,idx+1);
        board[row][col]=temp;
        return up|| down|| right||left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                   if(dfs(i,j,board,word,0)){
                    return true;
                   }
                }
            }
        }
        return false;
    }
};