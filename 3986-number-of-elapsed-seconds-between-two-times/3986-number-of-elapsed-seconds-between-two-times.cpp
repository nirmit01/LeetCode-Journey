class Solution {
public:
    int sec(string s)
    {
        int hr=stoi(s.substr(0,2));
        int min=stoi(s.substr(3,2));
        int sc = stoi(s.substr(6,2));
        return hr*3600+min*60+sc;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return sec(endTime)-sec(startTime);
    }
};