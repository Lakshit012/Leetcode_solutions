class Solution {
public:
    int n,m;
    int dfs(int row,int col,vector<vector<int>>&grid,int count,int countZero){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==-1) return 0;
        if(grid[row][col]==0) count++;
         if(grid[row][col]==2){
             if(count == countZero)
        return 1;
    else
        return 0;
         }
        int temp=grid[row][col];
        grid[row][col]=-1;
        int up=dfs(row-1,col,grid,count,countZero);
        int down=dfs(row+1,col,grid,count,countZero);
        int right=dfs(row,col+1,grid,count,countZero);
        int left=dfs(row,col-1,grid,count,countZero);
        grid[row][col]=temp;
        return up+ down+right+ left;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         int countZero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) countZero++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=(dfs(i,j,grid,0,countZero));
                }
            }
        }
        return ans;
    }
};