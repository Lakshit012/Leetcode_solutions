class Solution {
public: 
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int>pq;
       for(int x:piles){
        pq.push(x);
       } 
       while(k--){
        if(!pq.empty()){
          int stone=pq.top();
          pq.pop();
          stone=ceil(stone/2.0);
          pq.push(stone);
        }
       }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};