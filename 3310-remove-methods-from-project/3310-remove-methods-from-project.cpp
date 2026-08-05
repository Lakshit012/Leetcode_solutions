class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&susp,vector<int>&indegree){
        susp[node]=true;
        for(int &it:adj[node]){
            indegree[it]--;
            if(susp[it]==false){
                dfs(it,adj,susp,indegree);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<int>susp(n,false);
        for(auto &edges:invocations){
           int u=edges[0];
           int v=edges[1];
           adj[u].push_back(v);
           indegree[v]++;
        }
        dfs(k,adj,susp,indegree);
        bool ok=false;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(susp[i] && indegree[i]>0){
                ok=true;
                break;
            }
            if(!susp[i]){
                result.push_back(i);
            }
        }
        if(ok==true) {
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
     return result;
    }
};