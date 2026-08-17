class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi=*max_element(lights.begin(),lights.end());
        int ans=0;
      for(int i=0;i<arrivalTime.size();i++){
        int r=arrivalTime[i]%period;
         if(maxi<=r){
        ans=max(ans,period-r);
        }
      }
      return ans;
    }
};