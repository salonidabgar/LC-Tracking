class Solution {
public:
    static bool comparator(vector<int> & a, vector<int>& b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int maxUnits = 0;
        for(int i=0;i<boxTypes.size();i++)
        {
            
            if(boxTypes[i][0] <=truckSize)
            {
                maxUnits += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize = truckSize - boxTypes[i][0];
            }
            else
            {
                maxUnits +=(truckSize*boxTypes[i][1]);
                truckSize = 0;
            }
            if(!truckSize) break;
        }
        return maxUnits;
    }
};