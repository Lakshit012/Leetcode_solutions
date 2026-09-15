class Solution {
public:
    string reorganizeString(string s) {
      unordered_map<char,int>mpp;
     for(char  ch:s){
        mpp[ch]++;
     }
     priority_queue<pair<int,char>>pq;
     for(auto it:mpp){
        char ch=it.first;
        int freq=it.second;
        if(freq>(s.length()+1)/2) return "";
        pq.push({freq,ch});
     }
     string ans;
     while(!pq.empty()){
         char ch=pq.top().second;
         int freq=pq.top().first;
         pq.pop();
         ans.push_back(ch);
          freq--;
         if(!pq.empty()){
        char ch2=pq.top().second;
        int freq2=pq.top().first;
        pq.pop();
        ans.push_back(ch2);
        freq2--;
        if(freq>0){
            pq.push({freq,ch});
         }
        if(freq2>0){
            pq.push({freq2,ch2});
        }
         }
       
     }
     return ans;
    }
};