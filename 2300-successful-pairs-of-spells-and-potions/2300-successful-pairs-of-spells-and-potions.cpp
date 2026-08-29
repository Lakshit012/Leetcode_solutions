class Solution {
public:
    int solve(vector<int>&potions,int num,long long success){
        int low=0;
        int high=potions.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((long long)potions[mid]*num>=success){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int num=solve(potions,spells[i],success);
            ans.push_back(num);
        }
        return ans;
    }
};