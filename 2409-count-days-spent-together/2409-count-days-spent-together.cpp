class Solution {
public:
    int convert(string date,vector<int>&year){
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        for(int i=0;i<month-1;i++){
            day+=year[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob){
        vector<int>year={31,28,31,30,31,30,31,31,30,31,30,31};
        int a1=convert(arriveAlice,year);
        int a2=convert(leaveAlice,year);
        int b1=convert(arriveBob,year);
        int b2=convert(leaveBob,year);
        int start=max(a1,b1);
        int end=min(a2,b2);
        if(start>end)return 0;
        return end-start+1;
    }
};