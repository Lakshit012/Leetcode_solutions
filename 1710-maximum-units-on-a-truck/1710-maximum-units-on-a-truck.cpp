class Solution {
public:
    static bool cmp(vector<int>&a ,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(),boxTypes.end(),cmp);
       int ans=0;
       for(int i=0;i<boxTypes.size();i++){
            int noofBoxes=boxTypes[i][0];
            int noofUnits=boxTypes[i][1];
            if(noofBoxes<=truckSize){
                ans+=noofUnits*noofBoxes;
                truckSize-=noofBoxes;
            }
            else if(noofBoxes>truckSize){
                ans+=truckSize*noofUnits;
                break;
            }
        }
       return ans;
    }
};