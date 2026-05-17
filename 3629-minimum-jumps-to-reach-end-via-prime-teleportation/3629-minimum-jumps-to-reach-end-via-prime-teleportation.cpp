const int maxi=1000000;
vector<int> sieve(maxi+1);
bool initialized=[](){
    for(int i=0;i<=maxi;i++)
    sieve[i]=i;
    for(int i=2;i<=sqrt(maxi);i++)
    {
        if(sieve[i]==i)
        {
            int j=i*i;
            while(j<=maxi)
            {
                if(sieve[j]==j)
                    sieve[j]=i;
                j+=i;
            }
        }
    }
    return true;
}();
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> buckets;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            vector<int> prime;
            while(x>1)
            {
                int p=sieve[x];
                prime.push_back(p);
                while(x%p==0)
                    x/=p;
            }
            for(const int& p : prime)
            {
                buckets[p].push_back(i);
            }
        }
        vector<int> q;
        q.push_back(0);
        int visited[n];
        memset(visited,0,sizeof(visited));
        visited[0]=1;
        int steps=0;
        while(true)
        {
            vector<int> q2;
            for(int i:q)
            {
                if(i==n-1)
                    return steps;
                vector<int> v={i+1,i-1};
                for(int& j :v)
                {
                    if(j>=0 && j<n && !visited[j])
                    {
                        q2.push_back(j);
                        visited[j]=1;
                    }
                }

                if(sieve[nums[i]]==nums[i] && nums[i]>=2)
                {
                    for(int &k:buckets[nums[i]])
                    {
                        if(!visited[k])
                        {
                            q2.push_back(k);
                            visited[k]=1;
                        }
                    }
                    buckets[nums[i]].clear();
                }
            }
            q=move(q2);
            steps++;
        }
        return steps;
    }
};