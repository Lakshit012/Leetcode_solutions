class Solution {
public:
    void dfs(int node,vector<vector<int>>&rooms,vector<int>&vis){
        vis[node]=1;
        for(int neigh:rooms[node]){
            if(vis[neigh]==-1){
                dfs(neigh,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<int>vis(n,-1);
        dfs(0,rooms,vis);
        for(int x:vis){
            if(x<0) return false;
        }
        return true;
    }
};