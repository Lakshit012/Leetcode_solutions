class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int>rightMatched(n+1,0);
        int matched=0;
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                matched++;
                j--;
            }
            rightMatched[i]=matched;
            i--;
        }
        vector<int>ans;
        bool change=true;
        i=0;
        j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
        }
        else if(change==true && rightMatched[i+1]>=m-j-1){
            ans.push_back(i);
            j++;
            change=false;
        }
        i++;
      }
      if(j==m) return ans;
      else return {};
    }
};