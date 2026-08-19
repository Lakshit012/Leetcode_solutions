class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> nums;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int rowNo = reservedSeats[i][0];
            int seatNo = reservedSeats[i][1];
            nums[rowNo].push_back(seatNo);
        }
        int ans = 2LL * (n - nums.size());
        for (auto row:nums) {
            bool g1 = true;
             bool g2 = true;
              bool g3 = true;
             for(int seat:row.second){
                if(seat>=2 && seat<=5){
                    g1=false;
                }
                if(seat>=4 && seat<=7){
                    g2=false;
                }
                if(seat>=6 && seat<=9){
                    g3=false;
                }
             }
               if (g1 && g3) {
                    ans += 2;
                } else if (g1 || g2 || g3) {
                    ans += 1;
                }
        }
        return ans;
    }
};
