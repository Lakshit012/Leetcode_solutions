class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                string nums;
                i++;
                while(s[i]!=')'){
                    nums.push_back(s[i]);
                    i++;
                }
               if(mpp.find(nums)!=mpp.end()){
                ans+=mpp[nums];
               }
               else{
                ans+="?";
               }
        }
         else
               ans.push_back(s[i]);
            
        }
        return ans;
    }
};