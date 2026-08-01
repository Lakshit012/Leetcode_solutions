class Solution {
public:
    int solve(vector<int>&nums,int l ,int r,int person){
        if (l == r) {
    if (person == 1)
        return nums[l];
    return 0;
}
        if(l>r) return 0;
        if(person==1){
            int left=nums[l]+solve(nums,l+1,r,0);
            int right=nums[r]+solve(nums,l,r-1,0);
            return max(left,right);
        }
        else if(person==0){
            int left=solve(nums,l+1,r,1);
            int right=solve(nums,l,r-1,1);
              return min(left,right);
        }
        return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int player1=solve(nums,l,r,1);
        int player2=accumulate(nums.begin(),nums.end(),0)-player1;
        return player1>=player2;
    }
};