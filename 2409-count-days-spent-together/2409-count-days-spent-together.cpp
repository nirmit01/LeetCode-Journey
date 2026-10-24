class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int vec[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string s){
            int month=stoi(s.substr(0,2));
            int day=stoi(s.substr(3,2));
            for(int i=0;i<month-1;i++)
                day+=vec[i];
            return day;
        };
        int aa=convert(arriveAlice);
        int la=convert(leaveAlice);
        int ab=convert(arriveBob);
        int lb=convert(leaveBob);

        int start=max(aa,ab);
        int end=min(la,lb);

        return max(0,end-start+1);
    }
};