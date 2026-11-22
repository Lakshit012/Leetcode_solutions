class Solution {
public:   
      int t[101][101];
   bool visited[101][101];
    int solve(vector<vector<int>>&matrix,int row,int col){
        if(col<0|| col>=matrix[0].size()) return INT_MAX/2;
        if(row==matrix.size()-1) return matrix[row][col];
        if(visited[row][col]) return t[row][col];
visited[row][col] = true;
        int sum=matrix[row][col];
        int minSum=INT_MAX;
        minSum=min(minSum,solve(matrix,row+1,col));
        minSum=min(minSum,solve(matrix,row+1,col+1));
        minSum=min(minSum,solve(matrix,row+1,col-1));
        return t[row][col]=sum+minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(t,-1,sizeof(t));
        memset(visited, false, sizeof(visited));
        int row=0;
        int n=matrix[0].size();
        int ans=INT_MAX;
        for(int col=0;col<n;col++){
           ans= min(ans,solve(matrix,row,col));
        }
        return ans;
    }
};