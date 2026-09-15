class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>maxi(nums2.size(),-1);
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]){
                
                maxi[i]=st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int>mpp;
      for(int i=0;i<nums2.size();i++){
          mpp[nums2[i]]=maxi[i];
    }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int num=mpp[nums1[i]];
            ans.push_back(num);
        }
        return ans;
    }
};