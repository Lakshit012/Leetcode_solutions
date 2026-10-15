class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> arr(101, 0);
            int distinct = 0;

            for (int j = i; j < nums.size(); j++) {
                if (arr[nums[j]] == 0) {
                    distinct++;
                }
                arr[nums[j]]++;
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};