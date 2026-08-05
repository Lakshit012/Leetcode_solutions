class NumArray {
public:
    int n;
    vector<int>segmentTree;
    void buildSegmentTree(int i,int l,int r,vector<int>&segmentTree,vector<int>&nums){

        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,segmentTree,nums);
        buildSegmentTree(2*i+2,mid+1,r,segmentTree,nums);
         segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    NumArray(vector<int>& nums) {
       n=nums.size();
       segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,segmentTree,nums);
    }
    
    void updatesegmentTree(int i,int l,int r,int idx,int val){
        if(l==r)
        {
            segmentTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            updatesegmentTree(2*i+1,l,mid,idx,val);
        }
        else{
            updatesegmentTree(2*i+2,mid+1,r,idx,val);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    void update(int index, int val) {
        updatesegmentTree(0,0,n-1,index,val);
    }
    int query(int i,int left,int right,int l,int r){
        if(left>r || right<l) return 0;
        if(left<=l &&  r<=right){
            return segmentTree[i];
        }
        int mid=l+(r-l)/2;
        return query(2*i+1,left,right,l,mid)+query(2*i+2,left,right,mid+1,r);
    }
    int sumRange(int left, int right) {
        return (query(0,left,right,0,n-1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */