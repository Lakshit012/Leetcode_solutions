class Solution {
public:
    bool solve(string s,string p,vector<int>&removable,int k){
        string ans;
        unordered_map<int,int>mpp;
        for(int  i=0;i<k;i++){
            mpp[removable[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mpp.find(i)!=mpp.end()) continue;
            else {
                ans.push_back(s[i]);
            }
        }
        int j=0;
        int ch=0;
        int i=0;
        while(j<p.length()&& i<ans.length()){
            if(p[j]==ans[i]) {
                ch++;
                j++;
            }
            i++;
        }
        return ch==p.length();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
      int low=0;
      int high =removable.size();
      int ans=0;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(solve(s,p,removable,mid)){
            ans=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
      }  
      return ans;
    }
};