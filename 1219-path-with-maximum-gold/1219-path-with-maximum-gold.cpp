class Solution {
public:
    int m,n;
    int dfs(vector<vector<int>>&grid,int row,int col){
        if(row<0 || row>=n || col>=m || col<0 || grid[row][col]==0) return 0;
        int temp=grid[row][col];
        grid[row][col]=0;
        int up=dfs(grid,row-1,col);
        int down=dfs(grid,row+1,col);
        int right=dfs(grid,row,col+1);
        int left=dfs(grid,row,col-1);
        grid[row][col]=temp;
        return temp+max({left,up,down,right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
         n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                     ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};