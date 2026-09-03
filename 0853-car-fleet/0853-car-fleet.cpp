class Solution {
public:
   static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]>b[0];
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>>nums;
        for(int i=0;i<speed.size();i++){
            nums.push_back({position[i],speed[i]});
        }
        sort(nums.begin(),nums.end(),cmp);
        int ans=1;
        double prevTime=(double)(target-nums[0][0])/nums[0][1];
        for(int i=1;i<nums.size();i++){
            double time=(double)(target-nums[i][0])/nums[i][1];
            if(prevTime<time){
                prevTime=time;
                 ans++;
            }
        }
        return ans;
    }
};