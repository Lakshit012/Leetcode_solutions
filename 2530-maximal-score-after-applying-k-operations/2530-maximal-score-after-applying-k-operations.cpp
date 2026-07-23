class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      long long ans=0;
      priority_queue<int>pq;
      for(int x:nums){
        pq.push(x);
      }
      while(k--){
        int maxEl=pq.top();
        pq.pop();
        ans+=maxEl;
        maxEl=ceil(maxEl/3.0);
        pq.push(maxEl);
      }
      return ans;
    }
};