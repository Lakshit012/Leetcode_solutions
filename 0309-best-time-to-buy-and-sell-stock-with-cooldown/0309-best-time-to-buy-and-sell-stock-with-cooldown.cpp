class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& nums, int idx, int buy) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit = 0;
        if (buy) {
            int take = -nums[idx] + solve(nums, idx + 1, 0);
            int skip = solve(nums, idx + 1, 1);
            profit = max(take, skip);
        }
        else {
            int sell = nums[idx] + solve(nums, idx + 2, 1);
            int skip = solve(nums, idx + 1, 0);
            profit = max(sell, skip);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1);
    }
};