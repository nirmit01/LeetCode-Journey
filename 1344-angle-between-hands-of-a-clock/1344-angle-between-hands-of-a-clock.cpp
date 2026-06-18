class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = ((hour*30)+(30/60.0)*minutes);
        double m = (360/60)*minutes;
        double angle = abs(h-m);
        return min(angle,360-angle);
    }
};