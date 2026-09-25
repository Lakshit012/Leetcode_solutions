class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>nums;
        int ans=0;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1)nums.push_back(i);
        }
        if(seats[0] == 0)
            ans = nums[0];
            
        if(seats[seats.size()-1]==0){
            ans=max(ans,(int)seats.size()-1-nums.back());
        }
        int prev=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int dis=(nums[i+1]-nums[i]);
            if(prev<dis){
                prev=dis;
                ans=max(ans,dis/2);
            }
        }
        return ans;
    }
};