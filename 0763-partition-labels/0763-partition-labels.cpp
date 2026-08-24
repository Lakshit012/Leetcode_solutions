class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mpp[ch]=i;
        }
        vector<int>ans;
        int maxi=INT_MIN;
        int start=0;
        for(int i=0;i<s.length();i++){
            int freq=mpp[s[i]];
            maxi=max(freq,maxi);
            if(maxi==i){
                 ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
        }
    };