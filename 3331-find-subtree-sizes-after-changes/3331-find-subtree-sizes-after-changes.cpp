class Solution {
public: 
    unordered_map<int,vector<int>>adj;
    vector<int>ans;
    vector<int>last;
    void dfs(int idx,string &s,vector<int>&parent){
        int c=s[idx]-'a';
        int nearest=last[c];
        last[c]=idx;
        for(int child:adj[idx]){
            dfs(child,s,parent);
        }
        last[c]=nearest;
        if(idx!=0){
         int newParent=parent[idx];
        if(nearest!=-1)
        newParent=nearest;
        parent[idx]=newParent;
        ans[newParent]+=ans[idx];
        }

    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        for(int i=1;i<n;i++){
            int u=parent[i];
            adj[u].push_back(i);
        }
        ans.assign(n,1);
        last.assign(26,-1);
        dfs(0,s,parent);
        return ans;
    }
};