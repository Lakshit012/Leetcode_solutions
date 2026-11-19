class Solution {
public: 
    int t[501][501];
    int solve(string &s1,string &s2,int i,int j){
       // base case
        if(i>=s1.size()) return s2.size()-j;
        if(j>=s2.size()) return s1.size()-i;
        if(t[i][j]!=-1) return t[i][j];
       if(s1[i]==s2[j]){
       return t[i][j]=solve(s1,s2,i+1,j+1);
       }

       int insert=0;
       int del=0;
       int replace=0;
       insert=1+solve(s1,s2,i,j+1);
       del=1+solve(s1,s2,i+1,j);
       replace=1+solve(s1,s2,i+1,j+1);
       return t[i][j]=min({insert,replace,del});
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
    }
};