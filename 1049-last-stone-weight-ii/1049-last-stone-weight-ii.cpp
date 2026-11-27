class Solution {
public:
    int total=0;
    int t[31][3001];
    int solve(vector<int>& stones, int idx, int sum) {
    if(idx == stones.size()) {
        int other = total - sum;
        return abs(sum - other);
    }
    if(t[idx][sum] != -1) return t[idx][sum];

    int take = solve(stones, idx+1, sum + stones[idx]);
    int skip = solve(stones, idx+1, sum);

    return t[idx][sum]=min(take, skip);
}
    int lastStoneWeightII(vector<int>& stones) {
        total=0;
        memset(t,-1,sizeof(t));
        for(int x : stones) {
            total += x;
        }
        return solve(stones,0,0);
    }
};