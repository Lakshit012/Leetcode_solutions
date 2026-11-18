class Solution {
public:
int t[501][501];
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(nums1[i]==nums2[j]){
            return t[i][j]=1+solve(nums1,nums2,i+1,j+1);
        }
    else return t[i][j]=max(solve(nums1,nums2,i,j+1),solve(nums1,nums2,i+1,j));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));
        return solve(nums1,nums2,0,0);
    }
};