class Solution {
public:
    int solve(vector<int>& nums, int l, int m) {
        int maxTotal = 0;
        int n = nums.size();

        // Aapka code: Ab 'l' length ke har possible window ko try karenge
        for (int start = 0; start <= n - l; start++) {
            
            // 1. 'l' length subarray ka sum (ansl)
            int ansl = 0;
            int startIndex = start;
            int endIndex = start + l - 1;
            for (int k = startIndex; k <= endIndex; k++) {
                ansl += nums[k];
            }

            // 2. Taken vector mark karna (Aapka logic)
            vector<bool> taken(n, false);
            for (int k = startIndex; k <= endIndex; k++) {
                taken[k] = true;
            }

            // 3. Remaining elements mein 'm' length ka max sum (Aapka loop + window fix)
            int i = 0, j = 0;
            int sumM = 0;
            int currM = 0;

            while (j < n) {
                if (taken[j] == true) {
                    currM = 0;      // Blocked element milte hi sum reset
                    i = j + 1;      // Window ko blocked element ke aage shift kiya
                } else {
                    currM += nums[j];
                    if (j - i + 1 == m) {
                        sumM = max(sumM, currM);
                        currM -= nums[i];
                        i++;
                    }
                }
                j++;
            }

            // Max result update
            maxTotal = max(maxTotal, ansl + sumM);
        }

        return maxTotal;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int l = solve(nums, firstLen, secondLen);
        int m = solve(nums, secondLen, firstLen);
        return max(l, m);
    }
};



