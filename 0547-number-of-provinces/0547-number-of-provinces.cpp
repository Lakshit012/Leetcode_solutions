class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) 
    {
     queue<int>q;
     q.push(start);
     vis[start]=1;
     while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int neigh:adj[node]){
            if(vis[neigh]==-1){
                vis[neigh]=1;
                q.push(neigh);
            }
        }
     }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
vector<vector<int>> adj(n);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && i != j) {
            adj[i].push_back(j);
        }
    }
}
vector<int>vis(n,-1);
    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            ans++;
            bfs(i,adj,vis);
        }
    }
    return ans;
    }
};