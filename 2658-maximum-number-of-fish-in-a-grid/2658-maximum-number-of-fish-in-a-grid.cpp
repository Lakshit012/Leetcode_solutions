class Solution {
public:
    int dfs(vector<vector<int>>&grid,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=n || col>=m || col<0 || row<0  || grid[row][col]==0) return 0;
        int fish=grid[row][col];
        grid[row][col]=0;
        int right=dfs(grid,row,col+1);
        int left=dfs(grid,row,col-1);
        int up=dfs(grid,row+1,col);
        int down=dfs(grid,row-1,col);
        return left+right+up+down+fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};