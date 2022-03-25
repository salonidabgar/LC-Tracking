class Solution {
public:
    int get_last_nonconflicting_job(vector<vector<int>>&jobs, int i)
    {
        int low = 0;
        int high = i;
        while (low <= high)
        {
            int mid =(low+high)/2;
            if(jobs[mid][0]<=jobs[i][1])
            {
                if(jobs[mid+1][0]<=jobs[i][1])
                {
                    low= mid+1;
                }
                else return mid;
                }
            else
            {
                high = mid-1;
            }
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int> > jobs;
        for(int i=0;i<n;i++)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> max_profit(n,0);
        max_profit[0] = jobs[0][2];
        int j=0;
        for(int i=1;i<n;i++)
        {
            j = get_last_nonconflicting_job(jobs,i);
            int curr_profit = jobs[i][2];
            if(j!=-1)
            {
                curr_profit +=max_profit[j];
            }
            max_profit[i] = max(curr_profit, max_profit[i-1]);
            
    }
        return max_profit[n-1];
    }
};