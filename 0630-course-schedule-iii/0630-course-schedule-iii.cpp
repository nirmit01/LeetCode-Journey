class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(),courses.end(),[](auto& a,auto& b){
            if(a[1]==b[1])
                return a[0]<b[0];
            return a[1]<b[1];
        });
        int day=0;
        for(auto& v:courses)
        {
            int duration=v[0],lastday=v[1];
            day+=duration;
            pq.push(duration);
            if(day>lastday)
            {
                int k=pq.top();
                pq.pop();
                day-=k;
            }
        }
        return pq.size();
    }
};