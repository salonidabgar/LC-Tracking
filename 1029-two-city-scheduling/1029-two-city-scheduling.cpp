class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        nth_element(costs.begin(),costs.begin()+costs.size()/2, costs.end(), [](vector<int>&a, vector<int> &b)
             {
                 return(a[1]-a[0] > b[1]-b[0]);
             });
            int res =0;
        for(int i=0;i<costs.size()/2;i++)
        {
            res+=costs[i][0] + costs[i+costs.size()/2][1];
        }
        return res;
        
    }
};