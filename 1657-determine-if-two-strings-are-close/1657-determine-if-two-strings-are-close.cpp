class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;  
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(int i=0;i<word1.length();i++){
            mpp1[word1[i]]++;
        }
        for(char ch:word2){
            mpp2[ch]++;
        }
        vector<int> nums1;
        vector<int> nums2;
        for(auto it:mpp1){
            int no=it.second;
            nums1.push_back(no);
        }
          for(auto it:mpp2){
            int no=it.second;
            nums2.push_back(no);
        }
        if(mpp1.size() != mpp2.size()) return false;
        for(auto it : mpp1){
        if(mpp2.find(it.first) == mpp2.end())
        return false;  
       } 
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=nums2[i]) return false;
        }
        return true;
    }
};