class Solution {
public: 
    int t[301][11];
    int solve(vector<int>&nums,int idx,int d){
        if(d==1){
            int maxD=nums[idx];
            for(int i=idx;i<nums.size();i++){
                maxD=max(maxD,nums[i]);
            }
            return maxD;
        }
        if(t[idx][d]!=-1) return t[idx][d];
        int maxD=nums[idx];
        int ans=INT_MAX;
        int result=0;
        for(int i=idx;i<=nums.size()-d;i++){
            maxD=max(maxD,nums[i]);
            result=maxD+solve(nums,i+1,d-1);
            ans=min(ans,result);
        }
        return t[idx][d]=ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        memset(t,-1,sizeof(t));
        if(jd.size()<d) return -1;
        return solve(jd,0,d);
    }
};